#pragma once
#include <string>

namespace GW2::Alerts
{
constexpr int Signature = 0x67770261;
enum Type
{
    // plain advancement
    AdvancedLevel,
    AdvancedWvWRank,
    AdvancedBonusMagicFind,

    // reward earned
    EarnedWvWSkirmishPips,
    EarnedPvPRankPoints,
    EarnedRewardTrackProgress,

    // content unlocked
    UnlockedDye,
    UnlockedFinisher,
    UnlockedGliderSkin,
    UnlockedJadeBotSkin,
    UnlockedMailCarrier,
    UnlockedMinipet,
    UnlockedMountSkin,
    UnlockedOutfit,
    UnlockedRewardTrack,
    UnlockedSkin,
    UnlockedToy,

    // character progression
    PointOfInterestRevealed,
    SkillChallangeCompleted,
    RenownTaskCompleted,
    SkillLearned,
    TraitUnlocked,

    // notification

    Error,
    Announcement,
    VoicedAnnouncement,
    Notification,
    Invitation, // either squad or party
    SquadBroadcast,

    // need investigations
    AchievementCompleted, // progressed
    AchievementUnlock,

    // unidentified, no notification
    Unknown_0x03,
    Unknown_0x08,
    Unknown_0x06,
    Unknown_0x0B,
    Unknown_0x0F, // SkillLearned
    Unknown_0x10,
    Unknown_0x16,
    Unknown_0x18, // SkillLearned
    Unknown_0x1F,
};

struct UnlockPayload
{
    unsigned int ID;
};
struct GuidPayload
{
    std::string UUID;
};
struct AdvancementPayload
{
    int NewValue;
};
struct AwardPayload
{
    int Amount;
};

template <Type T> struct Info
{
    static constexpr const char *const Identifier = nullptr;
    using Payload = void;
};

template <> constexpr auto Info<Announcement>::Identifier = "EV_ALERT:Announcement";
template <> constexpr auto Info<VoicedAnnouncement>::Identifier = "EV_ALERT:VoicedAnnouncement";
template <> constexpr auto Info<Invitation>::Identifier = "EV_ALERT:Invitation";
template <> constexpr auto Info<Error>::Identifier = "EV_ALERT:Error";
template <> constexpr auto Info<Notification>::Identifier = "EV_ALERT:Notification";
template <> constexpr auto Info<TraitUnlocked>::Identifier = "EV_ALERT:TraitUnlocked";
template <> constexpr auto Info<SkillLearned>::Identifier = "EV_ALERT:SkillLearned";

template <> struct Info<SquadBroadcast>
{
    static constexpr auto Identifier = "EV_ALERT:SquadBroadcast";
    using Payload = std::string;
};

template <> struct Info<UnlockedDye>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedDye";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedFinisher>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedFinisher";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedGliderSkin>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedGliderSkin";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedJadeBotSkin>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedJadeBotSkin";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedMailCarrier>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedMailCarrier";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedMinipet>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedMinipet";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedMountSkin>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedMountSkin";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedOutfit>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedOutfit";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedRewardTrack>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedRewardTrack";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedToy>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedToy";
    using Payload = UnlockPayload;
};
template <> struct Info<UnlockedSkin>
{
    static constexpr auto Identifier = "EV_ALERT:UnlockedSkin";
    using Payload = UnlockPayload;
};

template <> struct Info<AdvancedLevel>
{
    static constexpr auto Identifier = "EV_ALERT:AdvancedLevel";
    using Payload = AdvancementPayload;
};
template <> struct Info<AdvancedWvWRank>
{
    static constexpr auto Identifier = "EV_ALERT:AdvancedWvWRank";
    using Payload = AdvancementPayload;
};
template <> struct Info<AdvancedBonusMagicFind>
{
    static constexpr auto Identifier = "EV_ALERT:AdvancedBonusMagicFind";
    using Payload = AdvancementPayload;
};

template <> struct Info<EarnedPvPRankPoints>
{
    static constexpr auto Identifier = "EV_ALERT:EarnedPvPRankPoints";
    using Payload = AwardPayload;
};
template <> struct Info<EarnedRewardTrackProgress>
{
    static constexpr auto Identifier = "EV_ALERT:EarnedRewardTrackProgress";
    using Payload = AwardPayload;
};
template <> struct Info<EarnedWvWSkirmishPips>
{
    static constexpr auto Identifier = "EV_ALERT:EarnedWvWSkirmishPips";
    using Payload = AwardPayload;
};

template <> struct Info<AchievementCompleted>
{
    static constexpr auto Identifier = "EV_ALERT:AchievementCompleted";
    using Payload = UnlockPayload;
};
template <> struct Info<AchievementUnlock>
{
    static constexpr auto Identifier = "EV_ALERT:AchievementUnlock";
    using Payload = void;
};

template <> struct Info<PointOfInterestRevealed>
{
    static constexpr auto Identifier = "EV_ALERT:PointOfInterestRevealed";
    using Payload = UnlockPayload;
};
template <> struct Info<SkillChallangeCompleted>
{
    static constexpr auto Identifier = "EV_ALERT:SkillChallangeCompleted";
    using Payload = GuidPayload;
};
template <> struct Info<RenownTaskCompleted>
{
    static constexpr auto Identifier = "EV_ALERT:RenownTaskCompleted";
    using Payload = UnlockPayload;
};

} // namespace GW2::Alerts
