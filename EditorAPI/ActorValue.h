#pragma once

// wrapper class
class ActorValue
{
	enum
	{
		kAVTrait_Aggression_Unaggressive	= 0,
		kAVTrait_Aggression_Aggressive,
		kAVTrait_Aggression_VeryAggressive,
		kAVTrait_Aggression_Frenzied,

		kAVTrait_Aggression__MAX
	};

	enum
	{
		kAVTrait_Confidence_Cowardly	= 0,
		kAVTrait_Confidence_Cautious,
		kAVTrait_Confidence_Average,
		kAVTrait_Confidence_Brave,
		kAVTrait_Confidence_Foolhardy,

		kAVTrait_Confidence__MAX
	};

	enum
	{
		kAVTrait_Morality_AnyCrime		= 0,
		kAVTrait_Morality_ViolenceAgainstEnemies,
		kAVTrait_Morality_PropertyCrimeOnly,
		kAVTrait_Morality_NoCrime,

		kAVTrait_Morality__MAX
	};

	enum
	{
		kAVTrait_Mood_Neutral			= 0,
		kAVTrait_Mood_Angry,
		kAVTrait_Mood_Fear,
		kAVTrait_Mood_Happy,
		kAVTrait_Mood_Sad,
		kAVTrait_Mood_Surprised,
		kAVTrait_Mood_Puzzled,
		kAVTrait_Mood_Disgusted,
		kAVTrait_Mood_UNDEFINED,

		kAVTrait_Mood__MAX
	};

	enum
	{
		kAVTrait_Assistance_HelpsNobody		= 0,
		kAVTrait_Assistance_HelpsAllies,
		kAVTrait_Assistance_HelpsFriendsAndAllies,

		kAVTrait_Assistance__MAX
	};

};