#include <Alerts.hpp>
#include <Handler.hpp>
#include <Nexus.h>
#include <exception>

void AddonLoad(AddonAPI *aApi);
void AddonUnload();

extern "C" __declspec(dllexport) AddonDefinition *GetAddonDef();

AddonDefinition *GetAddonDef()
{
    static AddonDefinition def{
        .Signature = GW2::Alerts::Signature,
        .APIVersion = NEXUS_API_VERSION,
        .Name = "Events: " ADDON_NAME,
        .Version = AddonVersion{ADDON_VERSION_MAJOR, ADDON_VERSION_MINOR, ADDON_VERSION_PATCH, ADDON_VERSION_REVISION},
        .Author = "Vonsh.1427",
        .Description = "Provides game's alerts as events for other addons.",
        .Load = AddonLoad,
        .Unload = AddonUnload,
        .Flags = EAddonFlags_None,
        .Provider = EUpdateProvider_GitHub,
        .UpdateLink = "https://github.com/jsantorek/GW2-" ADDON_NAME,
    };
    return &def;
}
namespace G
{
AddonAPI *Nexus = nullptr;
} // namespace G
static GW2::Alerts::Handler *AlertHandler = nullptr;
void AddonLoad(AddonAPI *aApi)
{
    G::Nexus = aApi;
    try
    {
        AlertHandler = new GW2::Alerts::Handler();
    }
    catch (const std::exception &e)
    {
        G::Nexus->Log(ELogLevel_CRITICAL, ADDON_NAME, "Failed to install alert handler");
        G::Nexus->Log(ELogLevel_CRITICAL, ADDON_NAME, e.what());
    }
}

void AddonUnload()
{
    if (AlertHandler)
        delete AlertHandler;
    G::Nexus = nullptr;
}
