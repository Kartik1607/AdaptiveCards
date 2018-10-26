#include "pch.h"
#include "Enums.h"

#ifdef USE_CPPCORECHECK
#pragma warning(push)

// Unfortunately, the checker for WARNING_NO_GLOBAL_INIT_CALLS (26426) has an issue: it considers initialization of the
// below std::unordered_map statics to be global, and thus flags them all as having overly-complex initialization. We
// want to keep this check on, in general, but turn it off for this file (all warning instances were reviewed prior to
// disablement).
#pragma warning(disable : 26426)

// While we'd like to use GSL eventually, we don't currently have support for it. As such, some checks that ask us to
// use GSL idioms need to be disabled until we do have support:

// Use not_null<T> to indicate null check responsibility
#pragma warning(disable: 26429)
#endif

namespace AdaptiveSharedNamespace
{
    template<typename T>
    const std::unordered_map<std::string, T, CaseInsensitiveHash, CaseInsensitiveEqualTo>
    GenerateStringToEnumMap(const std::unordered_map<T, std::string, EnumHash>& keyToStringMap)
    {
        std::unordered_map<std::string, T, CaseInsensitiveHash, CaseInsensitiveEqualTo> result;
        for (const auto& kv : keyToStringMap)
        {
            result[kv.second] = kv.first;
        }
        return result;
    }

    static void GetAdaptiveCardSchemaKeyEnumMappings(
        _Outptr_ const std::unordered_map<AdaptiveCardSchemaKey, std::string, EnumHash>** adaptiveCardSchemaKeyEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, AdaptiveCardSchemaKey, CaseInsensitiveHash, CaseInsensitiveEqualTo>** adaptiveCardSchemaKeyNameToEnumOut)
    {
        static const std::unordered_map<AdaptiveCardSchemaKey, std::string, EnumHash> adaptiveCardSchemaKeyEnumToName = {
            {AdaptiveCardSchemaKey::Accent, "accent"},
            {AdaptiveCardSchemaKey::ActionAlignment, "actionAlignment"},
            {AdaptiveCardSchemaKey::ActionMode, "actionMode"},
            {AdaptiveCardSchemaKey::Actions, "actions"},
            {AdaptiveCardSchemaKey::ActionSetConfig, "actionSetConfig"},
            {AdaptiveCardSchemaKey::ActionsOrientation, "actionsOrientation"},
            {AdaptiveCardSchemaKey::AdaptiveCard, "adaptiveCard"},
            {AdaptiveCardSchemaKey::AllowCustomStyle, "allowCustomStyle"},
            {AdaptiveCardSchemaKey::AllowInlinePlayback, "allowInlinePlayback"},
            {AdaptiveCardSchemaKey::AltText, "altText"},
            {AdaptiveCardSchemaKey::Attention, "attention"},
            {AdaptiveCardSchemaKey::BackgroundColor, "backgroundColor"},
            {AdaptiveCardSchemaKey::BackgroundImage, "backgroundImage"},
            {AdaptiveCardSchemaKey::BackgroundImageUrl, "backgroundImageUrl"},
            {AdaptiveCardSchemaKey::BaseCardElement, "baseCardElement"},
            {AdaptiveCardSchemaKey::Body, "body"},
            {AdaptiveCardSchemaKey::Bolder, "bolder"},
            {AdaptiveCardSchemaKey::BorderColor, "borderColor"},
            {AdaptiveCardSchemaKey::BorderThickness, "borderThickness"},
            {AdaptiveCardSchemaKey::Bottom, "bottom"},
            {AdaptiveCardSchemaKey::ButtonSpacing, "buttonSpacing"},
            {AdaptiveCardSchemaKey::Card, "card"},
            {AdaptiveCardSchemaKey::Center, "center"},
            {AdaptiveCardSchemaKey::Choices, "choices"},
            {AdaptiveCardSchemaKey::ChoiceSet, "choiceSet"},
            {AdaptiveCardSchemaKey::Color, "color"},
            {AdaptiveCardSchemaKey::ColorConfig, "colorConfig"},
            {AdaptiveCardSchemaKey::ForegroundColors, "foregroundColors"},
            {AdaptiveCardSchemaKey::Column, "column"},
            {AdaptiveCardSchemaKey::Columns, "columns"},
            {AdaptiveCardSchemaKey::ColumnSet, "columnSet"},
            {AdaptiveCardSchemaKey::Container, "container"},
            {AdaptiveCardSchemaKey::ContainerStyles, "containerStyles"},
            {AdaptiveCardSchemaKey::Dark, "dark"},
            {AdaptiveCardSchemaKey::Data, "data"},
            {AdaptiveCardSchemaKey::DateInput, "dateInput"},
            {AdaptiveCardSchemaKey::Default, "default"},
            {AdaptiveCardSchemaKey::DefaultPoster, "defaultPoster"},
            {AdaptiveCardSchemaKey::Emphasis, "emphasis"},
            {AdaptiveCardSchemaKey::ExtraLarge, "extraLarge"},
            {AdaptiveCardSchemaKey::Facts, "facts"},
            {AdaptiveCardSchemaKey::FactSet, "factSet"},
            {AdaptiveCardSchemaKey::FallbackText, "fallbackText"},
            {AdaptiveCardSchemaKey::FontFamily, "fontFamily"},
            {AdaptiveCardSchemaKey::FontSizes, "fontSizes"},
            {AdaptiveCardSchemaKey::FontWeights, "fontWeights"},
            {AdaptiveCardSchemaKey::Good, "good"},
            {AdaptiveCardSchemaKey::Height, "height"},
            {AdaptiveCardSchemaKey::HorizontalAlignment, "horizontalAlignment"},
            {AdaptiveCardSchemaKey::IconPlacement, "iconPlacement"},
            {AdaptiveCardSchemaKey::IconSize, "iconSize"},
            {AdaptiveCardSchemaKey::IconUrl, "iconUrl"},
            {AdaptiveCardSchemaKey::Id, "id"},
            {AdaptiveCardSchemaKey::Image, "image"},
            {AdaptiveCardSchemaKey::ImageBaseUrl, "imageBaseUrl"},
            {AdaptiveCardSchemaKey::Images, "images"},
            {AdaptiveCardSchemaKey::ImageSet, "imageSet"},
            {AdaptiveCardSchemaKey::ImageSize, "imageSize"},
            {AdaptiveCardSchemaKey::ImageSizes, "imageSizes"},
            {AdaptiveCardSchemaKey::InlineAction, "inlineAction"},
            {AdaptiveCardSchemaKey::InlineTopMargin, "inlineTopMargin"},
            {AdaptiveCardSchemaKey::IsMultiline, "isMultiline"},
            {AdaptiveCardSchemaKey::IsMultiSelect, "isMultiSelect"},
            {AdaptiveCardSchemaKey::IsRequired, "isRequired"},
            {AdaptiveCardSchemaKey::IsSelected, "isSelected"},
            {AdaptiveCardSchemaKey::IsSubtle, "isSubtle"},
            {AdaptiveCardSchemaKey::Items, "items"},
            {AdaptiveCardSchemaKey::Language, "lang"},
            {AdaptiveCardSchemaKey::Large, "large"},
            {AdaptiveCardSchemaKey::Left, "left"},
            {AdaptiveCardSchemaKey::Light, "light"},
            {AdaptiveCardSchemaKey::Lighter, "lighter"},
            {AdaptiveCardSchemaKey::LineColor, "lineColor"},
            {AdaptiveCardSchemaKey::LineThickness, "lineThickness"},
            {AdaptiveCardSchemaKey::Max, "max"},
            {AdaptiveCardSchemaKey::MaxActions, "maxActions"},
            {AdaptiveCardSchemaKey::MaxImageHeight, "maxImageHeight"},
            {AdaptiveCardSchemaKey::MaxLength, "maxLength"},
            {AdaptiveCardSchemaKey::MaxLines, "maxLines"},
            {AdaptiveCardSchemaKey::MaxWidth, "maxWidth"},
            {AdaptiveCardSchemaKey::Media, "media"},
            {AdaptiveCardSchemaKey::Medium, "medium"},
            {AdaptiveCardSchemaKey::Method, "method"},
            {AdaptiveCardSchemaKey::MimeType, "mimeType"},
            {AdaptiveCardSchemaKey::Min, "min"},
            {AdaptiveCardSchemaKey::NumberInput, "numberInput"},
            {AdaptiveCardSchemaKey::Padding, "padding"},
            {AdaptiveCardSchemaKey::Placeholder, "placeholder"},
            {AdaptiveCardSchemaKey::PlayButton, "playButton"},
            {AdaptiveCardSchemaKey::Poster, "poster"},
            {AdaptiveCardSchemaKey::Right, "right"},
            {AdaptiveCardSchemaKey::SelectAction, "selectAction"},
            {AdaptiveCardSchemaKey::Sentiment, "sentiment"},
            {AdaptiveCardSchemaKey::Separator, "separator"},
            {AdaptiveCardSchemaKey::Thickness, "thickness"},
            {AdaptiveCardSchemaKey::ShowActionMode, "showActionMode"},
            {AdaptiveCardSchemaKey::ShowCard, "showCard"},
            {AdaptiveCardSchemaKey::ShowCardActionConfig, "showCardActionConfig"},
            {AdaptiveCardSchemaKey::Size, "size"},
            {AdaptiveCardSchemaKey::Small, "small"},
            {AdaptiveCardSchemaKey::Sources, "sources"},
            {AdaptiveCardSchemaKey::Spacing, "spacing"},
            {AdaptiveCardSchemaKey::SpacingDefinition, "spacingDefinition"},
            {AdaptiveCardSchemaKey::Speak, "speak"},
            {AdaptiveCardSchemaKey::Stretch, "stretch"},
            {AdaptiveCardSchemaKey::Style, "style"},
            {AdaptiveCardSchemaKey::Subtle, "subtle"},
            {AdaptiveCardSchemaKey::SupportsInteractivity, "supportsInteractivity"},
            {AdaptiveCardSchemaKey::Text, "text"},
            {AdaptiveCardSchemaKey::TextBlock, "textBlock"},
            {AdaptiveCardSchemaKey::TextConfig, "textConfig"},
            {AdaptiveCardSchemaKey::TextInput, "textInput"},
            {AdaptiveCardSchemaKey::TextWeight, "weight"},
            {AdaptiveCardSchemaKey::Thick, "thick"},
            {AdaptiveCardSchemaKey::Thickness, "thickness"},
            {AdaptiveCardSchemaKey::TimeInput, "timeInput"},
            {AdaptiveCardSchemaKey::Title, "title"},
            {AdaptiveCardSchemaKey::ToggleInput, "toggleInput"},
            {AdaptiveCardSchemaKey::Top, "top"},
            {AdaptiveCardSchemaKey::Type, "type"},
            {AdaptiveCardSchemaKey::Url, "url"},
            {AdaptiveCardSchemaKey::Value, "value"},
            {AdaptiveCardSchemaKey::ValueOff, "valueOff"},
            {AdaptiveCardSchemaKey::ValueOn, "valueOn"},
            {AdaptiveCardSchemaKey::Version, "version"},
            {AdaptiveCardSchemaKey::VerticalContentAlignment, "verticalContentAlignment"},
            {AdaptiveCardSchemaKey::Warning, "warning"},
            {AdaptiveCardSchemaKey::Weight, "weight"},
            {AdaptiveCardSchemaKey::Width, "width"},
            {AdaptiveCardSchemaKey::Wrap, "wrap"}};
        static const auto adaptiveCardSchemaKeyNameToEnum =
            GenerateStringToEnumMap<AdaptiveCardSchemaKey>(adaptiveCardSchemaKeyEnumToName);

        if (adaptiveCardSchemaKeyEnumToNameOut)
        {
            *adaptiveCardSchemaKeyEnumToNameOut = &adaptiveCardSchemaKeyEnumToName;
        }

        if (adaptiveCardSchemaKeyNameToEnumOut)
        {
            *adaptiveCardSchemaKeyNameToEnumOut = &adaptiveCardSchemaKeyNameToEnum;
        }
    }

    static void GetCardElementTypeEnumMappings(
        _Outptr_ const std::unordered_map<CardElementType, std::string, EnumHash>** cardElementTypeEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, CardElementType, CaseInsensitiveHash, CaseInsensitiveEqualTo>** cardElementTypeNameToEnumOut)
    {
        static const std::unordered_map<CardElementType, std::string, EnumHash> cardElementTypeEnumToName = {
            {CardElementType::AdaptiveCard, "AdaptiveCard"},
            {CardElementType::Column, "Column"},
            {CardElementType::ColumnSet, "ColumnSet"},
            {CardElementType::Container, "Container"},
            {CardElementType::Fact, "Fact"},
            {CardElementType::FactSet, "FactSet"},
            {CardElementType::Image, "Image"},
            {CardElementType::ImageSet, "ImageSet"},
            {CardElementType::ChoiceSetInput, "Input.ChoiceSet"},
            {CardElementType::DateInput, "Input.Date"},
            {CardElementType::NumberInput, "Input.Number"},
            {CardElementType::TextInput, "Input.Text"},
            {CardElementType::TimeInput, "Input.Time"},
            {CardElementType::ToggleInput, "Input.Toggle"},
            {CardElementType::TextBlock, "TextBlock"},
            {CardElementType::Custom, "Custom"},
            {CardElementType::Unknown, "Unknown"},
            {CardElementType::Media, "Media"},
        };
        static const auto cardElementTypeNameToEnum = GenerateStringToEnumMap<CardElementType>(cardElementTypeEnumToName);

        if (cardElementTypeEnumToNameOut)
        {
            *cardElementTypeEnumToNameOut = &cardElementTypeEnumToName;
        }

        if (cardElementTypeNameToEnumOut)
        {
            *cardElementTypeNameToEnumOut = &cardElementTypeNameToEnum;
        }
    }

    static void GetActionTypeEnumMappings(
        _Outptr_ const std::unordered_map<ActionType, std::string, EnumHash>** actionTypeEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ActionType, CaseInsensitiveHash, CaseInsensitiveEqualTo>** actionTypeNameToEnumOut)
    {
        static const std::unordered_map<ActionType, std::string, EnumHash> actionTypeEnumToName = {
            {ActionType::OpenUrl, "Action.OpenUrl"},
            {ActionType::ShowCard, "Action.ShowCard"},
            {ActionType::Submit, "Action.Submit"},
            {ActionType::Custom, "Custom"}};
        static const auto actionTypeNameToEnum = GenerateStringToEnumMap<ActionType>(actionTypeEnumToName);

        if (actionTypeEnumToNameOut)
        {
            *actionTypeEnumToNameOut = &actionTypeEnumToName;
        }

        if (actionTypeNameToEnumOut)
        {
            *actionTypeNameToEnumOut = &actionTypeNameToEnum;
        }
    }

    static void GetHeightTypeEnumMappings(
        _Outptr_ const std::unordered_map<HeightType, std::string, EnumHash>** heightTypeEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, HeightType, CaseInsensitiveHash, CaseInsensitiveEqualTo>** heightTypeNameToEnumOut)
    {
        static const std::unordered_map<HeightType, std::string, EnumHash> heightTypeEnumToName = {{HeightType::Auto, "Auto"},
                                                                                                   {HeightType::Stretch, "Stretch"}};

        static const auto heightTypeNameToEnum = GenerateStringToEnumMap<HeightType>(heightTypeEnumToName);

        if (heightTypeEnumToNameOut)
        {
            *heightTypeEnumToNameOut = &heightTypeEnumToName;
        }

        if (heightTypeNameToEnumOut)
        {
            *heightTypeNameToEnumOut = &heightTypeNameToEnum;
        }
    }

    static void GetSpacingMappings(_Outptr_ const std::unordered_map<Spacing, std::string, EnumHash>** spacingEnumToNameOut,
                                   _Outptr_ const std::unordered_map<std::string, Spacing, CaseInsensitiveHash, CaseInsensitiveEqualTo>** spacingNameToEnumOut)
    {
        static const std::unordered_map<Spacing, std::string, EnumHash> spacingEnumToName = {
            {Spacing::Default, "default"},
            {Spacing::None, "none"},
            {Spacing::Small, "small"},
            {Spacing::Medium, "medium"},
            {Spacing::Large, "large"},
            {Spacing::ExtraLarge, "extraLarge"},
            {Spacing::Padding, "padding"},
        };
        static const auto spacingNameToEnum = GenerateStringToEnumMap<Spacing>(spacingEnumToName);

        if (spacingEnumToNameOut)
        {
            *spacingEnumToNameOut = &spacingEnumToName;
        }

        if (spacingNameToEnumOut)
        {
            *spacingNameToEnumOut = &spacingNameToEnum;
        }
    }

    static void GetSeparatorThicknessEnumMappings(
        _Outptr_ const std::unordered_map<SeparatorThickness, std::string, EnumHash>** separatorThicknessEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, SeparatorThickness, CaseInsensitiveHash, CaseInsensitiveEqualTo>** separatorThicknessNameToEnumOut)
    {
        static const std::unordered_map<SeparatorThickness, std::string, EnumHash> separatorThicknessEnumToName = {
            {SeparatorThickness::Default, "default"},
            {SeparatorThickness::Thick, "thick"},
        };
        static const auto separatorThicknessNameToEnum = GenerateStringToEnumMap<SeparatorThickness>(separatorThicknessEnumToName);

        if (separatorThicknessEnumToNameOut)
        {
            *separatorThicknessEnumToNameOut = &separatorThicknessEnumToName;
        }

        if (separatorThicknessNameToEnumOut)
        {
            *separatorThicknessNameToEnumOut = &separatorThicknessNameToEnum;
        }
    }

    static void GetImageStyleEnumMappings(
        _Outptr_ const std::unordered_map<ImageStyle, std::string, EnumHash>** imageStyleEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ImageStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>** imageStyleNameToEnumOut)
    {
        static const std::unordered_map<ImageStyle, std::string, EnumHash> imageStyleEnumToName = {{ImageStyle::Default, "default"},
                                                                                                   {ImageStyle::Person, "person"}};

        static const std::unordered_map<std::string, ImageStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo> imageStyleNameToEnum = {
            {"default", ImageStyle::Default},
            {"person", ImageStyle::Person},
            {"normal", ImageStyle::Default} // Back compat to support "Normal" for "Default" for pre V1.0 payloads
        };

        if (imageStyleEnumToNameOut)
        {
            *imageStyleEnumToNameOut = &imageStyleEnumToName;
        }

        if (imageStyleNameToEnumOut)
        {
            *imageStyleNameToEnumOut = &imageStyleNameToEnum;
        }
    }

    static void GetImageSizeEnumMappings(
        _Outptr_ const std::unordered_map<ImageSize, std::string, EnumHash>** imageSizeEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ImageSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>** imageSizeNameToEnumOut)
    {
        static const std::unordered_map<ImageSize, std::string, EnumHash> imageSizeEnumToName = {
            {ImageSize::Auto, "Auto"},
            {ImageSize::Large, "Large"},
            {ImageSize::Medium, "Medium"},
            {ImageSize::Small, "Small"},
            {ImageSize::Stretch, "Stretch"},
        };
        static const auto imageSizeNameToEnum = GenerateStringToEnumMap<ImageSize>(imageSizeEnumToName);

        if (imageSizeEnumToNameOut)
        {
            *imageSizeEnumToNameOut = &imageSizeEnumToName;
        }

        if (imageSizeNameToEnumOut)
        {
            *imageSizeNameToEnumOut = &imageSizeNameToEnum;
        }
    };

    static void GetHorizontalAlignmentEnumMappings(
        _Outptr_ const std::unordered_map<HorizontalAlignment, std::string, EnumHash>** horizontalAlignmentEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, HorizontalAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>** horizontalAlignmentNameToEnumOut)
    {
        static const std::unordered_map<HorizontalAlignment, std::string, EnumHash> horizontalAlignmentEnumToName = {
            {HorizontalAlignment::Center, "Center"}, {HorizontalAlignment::Left, "Left"}, {HorizontalAlignment::Right, "Right"}};
        static const auto horizontalAlignmentNameToEnum =
            GenerateStringToEnumMap<HorizontalAlignment>(horizontalAlignmentEnumToName);

        if (horizontalAlignmentEnumToNameOut)
        {
            *horizontalAlignmentEnumToNameOut = &horizontalAlignmentEnumToName;
        }

        if (horizontalAlignmentNameToEnumOut)
        {
            *horizontalAlignmentNameToEnumOut = &horizontalAlignmentNameToEnum;
        }
    };

    static void GetColorEnumMappings(
        _Outptr_ const std::unordered_map<ForegroundColor, std::string, EnumHash>** colorEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ForegroundColor, CaseInsensitiveHash, CaseInsensitiveEqualTo>** colorNameToEnumOut)
    {
        static const std::unordered_map<ForegroundColor, std::string, EnumHash> colorEnumToName = {
            {ForegroundColor::Accent, "Accent"},
            {ForegroundColor::Attention, "Attention"},
            {ForegroundColor::Dark, "Dark"},
            {ForegroundColor::Default, "Default"},
            {ForegroundColor::Good, "Good"},
            {ForegroundColor::Light, "Light"},
            {ForegroundColor::Warning, "Warning"},
        };
        static const auto colorNameToEnum = GenerateStringToEnumMap<ForegroundColor>(colorEnumToName);

        if (colorEnumToNameOut)
        {
            *colorEnumToNameOut = &colorEnumToName;
        }

        if (colorNameToEnumOut)
        {
            *colorNameToEnumOut = &colorNameToEnum;
        }
    }

    static void GetTextWeightEnumMappings(
        _Outptr_ const std::unordered_map<TextWeight, std::string, EnumHash>** textWeightEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, TextWeight, CaseInsensitiveHash, CaseInsensitiveEqualTo>** textWeightNameToEnumOut)
    {
        static const std::unordered_map<TextWeight, std::string, EnumHash> textWeightEnumToName = {
            {TextWeight::Bolder, "Bolder"},
            {TextWeight::Lighter, "Lighter"},
            {TextWeight::Default, "Default"},
        };

        static const std::unordered_map<std::string, TextWeight, CaseInsensitiveHash, CaseInsensitiveEqualTo> textWeightNameToEnum = {
            {"Bolder", TextWeight::Bolder},
            {"Lighter", TextWeight::Lighter},
            {"Default", TextWeight::Default},
            {"Normal", TextWeight::Default}, // Back compat to support "Normal" for "Default" for pre V1.0 payloads
        };

        if (textWeightEnumToNameOut)
        {
            *textWeightEnumToNameOut = &textWeightEnumToName;
        }

        if (textWeightNameToEnumOut)
        {
            *textWeightNameToEnumOut = &textWeightNameToEnum;
        }
    }

    static void GetTextSizeEnumMappings(
        _Outptr_ const std::unordered_map<TextSize, std::string, EnumHash>** textSizeEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, TextSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>** textSizeNameToEnumOut)
    {
        static const std::unordered_map<TextSize, std::string, EnumHash> textSizeEnumToName = {
            {TextSize::ExtraLarge, "ExtraLarge"},
            {TextSize::Large, "Large"},
            {TextSize::Medium, "Medium"},
            {TextSize::Default, "Default"},
            {TextSize::Small, "Small"},
        };

        static const std::unordered_map<std::string, TextSize, CaseInsensitiveHash, CaseInsensitiveEqualTo> textSizeNameToEnum = {
            {"ExtraLarge", TextSize::ExtraLarge},
            {"Large", TextSize::Large},
            {"Medium", TextSize::Medium},
            {"Default", TextSize::Default},
            {"Small", TextSize::Small},
            {"Normal", TextSize::Default}, // Back compat to support "Normal" for "Default" for pre V1.0 payloads
        };

        if (textSizeEnumToNameOut)
        {
            *textSizeEnumToNameOut = &textSizeEnumToName;
        }

        if (textSizeNameToEnumOut)
        {
            *textSizeNameToEnumOut = &textSizeNameToEnum;
        }
    }

    static void GetActionsOrientationEnumMappings(
        _Outptr_ const std::unordered_map<ActionsOrientation, std::string, EnumHash>** actionsOrientationEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ActionsOrientation, CaseInsensitiveHash, CaseInsensitiveEqualTo>** actionsOrientationNameToEnumOut)
    {
        static const std::unordered_map<ActionsOrientation, std::string, EnumHash> actionsOrientationEnumToName = {
            {ActionsOrientation::Horizontal, "Horizontal"},
            {ActionsOrientation::Vertical, "Vertical"},
        };
        static const auto actionsOrientationNameToEnum = GenerateStringToEnumMap<ActionsOrientation>(actionsOrientationEnumToName);

        if (actionsOrientationEnumToNameOut)
        {
            *actionsOrientationEnumToNameOut = &actionsOrientationEnumToName;
        }

        if (actionsOrientationNameToEnumOut)
        {
            *actionsOrientationNameToEnumOut = &actionsOrientationNameToEnum;
        }
    }

    static void GetActionModeEnumMappings(
        _Outptr_ const std::unordered_map<ActionMode, std::string, EnumHash>** actionModeEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ActionMode, CaseInsensitiveHash, CaseInsensitiveEqualTo>** actionModeNameToEnumOut)
    {
        static const std::unordered_map<ActionMode, std::string, EnumHash> actionModeEnumToName = {{ActionMode::Inline, "Inline"},
                                                                                                   {ActionMode::Popup, "Popup"}};
        static const auto actionModeNameToEnum = GenerateStringToEnumMap<ActionMode>(actionModeEnumToName);

        if (actionModeEnumToNameOut)
        {
            *actionModeEnumToNameOut = &actionModeEnumToName;
        }

        if (actionModeNameToEnumOut)
        {
            *actionModeNameToEnumOut = &actionModeNameToEnum;
        }
    }

    static void GetChoiceSetStyleEnumMappings(
        _Outptr_ const std::unordered_map<ChoiceSetStyle, std::string, EnumHash>** choiceSetStyleEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ChoiceSetStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>** choiceSetStyleNameToEnumOut)
    {
        static const std::unordered_map<ChoiceSetStyle, std::string, EnumHash> choiceSetStyleEnumToName = {
            {ChoiceSetStyle::Compact, "Compact"}, {ChoiceSetStyle::Expanded, "Expanded"}};
        static const auto choiceSetStyleNameToEnum = GenerateStringToEnumMap<ChoiceSetStyle>(choiceSetStyleEnumToName);

        if (choiceSetStyleEnumToNameOut)
        {
            *choiceSetStyleEnumToNameOut = &choiceSetStyleEnumToName;
        }

        if (choiceSetStyleNameToEnumOut)
        {
            *choiceSetStyleNameToEnumOut = &choiceSetStyleNameToEnum;
        }
    };

    static void GetTextInputStyleEnumMappings(
        _Outptr_ const std::unordered_map<TextInputStyle, std::string, EnumHash>** textInputStyleEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, TextInputStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>** textInputStyleNameToEnumOut)
    {
        static const std::unordered_map<TextInputStyle, std::string, EnumHash> textInputStyleEnumToName = {
            {TextInputStyle::Email, "Email"},
            {TextInputStyle::Tel, "Tel"},
            {TextInputStyle::Text, "Text"},
            {TextInputStyle::Url, "Url"},
        };
        static const auto textInputStyleNameToEnum = GenerateStringToEnumMap<TextInputStyle>(textInputStyleEnumToName);

        if (textInputStyleEnumToNameOut)
        {
            *textInputStyleEnumToNameOut = &textInputStyleEnumToName;
        }

        if (textInputStyleNameToEnumOut)
        {
            *textInputStyleNameToEnumOut = &textInputStyleNameToEnum;
        }
    }

    static void GetContainerStyleEnumMappings(
        _Outptr_ const std::unordered_map<ContainerStyle, std::string, EnumHash>** containerStyleEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ContainerStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>** containerStyleNameToEnumOut)
    {
        static const std::unordered_map<ContainerStyle, std::string, EnumHash> containerStyleEnumToName = {
            {ContainerStyle::Default, "Default"},
            {ContainerStyle::Emphasis, "Emphasis"},
        };
        static const auto containerStyleNameToEnum = GenerateStringToEnumMap<ContainerStyle>(containerStyleEnumToName);

        if (containerStyleEnumToNameOut)
        {
            *containerStyleEnumToNameOut = &containerStyleEnumToName;
        }

        if (containerStyleNameToEnumOut)
        {
            *containerStyleNameToEnumOut = &containerStyleNameToEnum;
        }
    }

    static void GetActionAlignmentEnumMappings(
        _Outptr_ const std::unordered_map<ActionAlignment, std::string, EnumHash>** actionAlignmentEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, ActionAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>** actionAlignmentNameToEnumOut)
    {
        static const std::unordered_map<ActionAlignment, std::string, EnumHash> actionAlignmentEnumToName = {
            {ActionAlignment::Left, "Left"},
            {ActionAlignment::Center, "Center"},
            {ActionAlignment::Right, "Right"},
            {ActionAlignment::Stretch, "Stretch"},
        };
        static const auto actionAlignmentNameToEnum = GenerateStringToEnumMap<ActionAlignment>(actionAlignmentEnumToName);

        if (actionAlignmentEnumToNameOut)
        {
            *actionAlignmentEnumToNameOut = &actionAlignmentEnumToName;
        }

        if (actionAlignmentNameToEnumOut)
        {
            *actionAlignmentNameToEnumOut = &actionAlignmentNameToEnum;
        }
    }

    static void GetIconPlacementEnumMappings(
        _Outptr_ const std::unordered_map<IconPlacement, std::string, EnumHash>** iconPlacementEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, IconPlacement, CaseInsensitiveHash, CaseInsensitiveEqualTo>** iconPlacementNameToEnumOut)
    {
        static const std::unordered_map<IconPlacement, std::string, EnumHash> iconPlacementEnumToName = {
            {IconPlacement::AboveTitle, "AboveTitle"}, {IconPlacement::LeftOfTitle, "LeftOfTitle"}};
        static const auto iconPlacementNameToEnum = GenerateStringToEnumMap<IconPlacement>(iconPlacementEnumToName);

        if (iconPlacementEnumToNameOut)
        {
            *iconPlacementEnumToNameOut = &iconPlacementEnumToName;
        }

        if (iconPlacementNameToEnumOut)
        {
            *iconPlacementNameToEnumOut = &iconPlacementNameToEnum;
        }
    }

    static void GetVerticalContentAlignmentEnumMappings(
        _Outptr_ const std::unordered_map<VerticalContentAlignment, std::string, EnumHash>** verticalContentAlignmentEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, VerticalContentAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>** verticalContentAlignmentNameToEnumOut)
    {
        static const std::unordered_map<VerticalContentAlignment, std::string, EnumHash> verticalContentAlignmentEnumToName = {
            {VerticalContentAlignment::Top, "Top"},
            {VerticalContentAlignment::Center, "Center"},
            {VerticalContentAlignment::Bottom, "Bottom"}};
        static const auto verticalContentAlignmentNameToEnum =
            GenerateStringToEnumMap<VerticalContentAlignment>(verticalContentAlignmentEnumToName);

        if (verticalContentAlignmentEnumToNameOut)
        {
            *verticalContentAlignmentEnumToNameOut = &verticalContentAlignmentEnumToName;
        }

        if (verticalContentAlignmentNameToEnumOut)
        {
            *verticalContentAlignmentNameToEnumOut = &verticalContentAlignmentNameToEnum;
        }
    }

    static void GetSentimentEnumMappings(
        _Outptr_ const std::unordered_map<Sentiment, std::string, EnumHash>** sentimentEnumToNameOut,
        _Outptr_ const std::unordered_map<std::string, Sentiment, CaseInsensitiveHash, CaseInsensitiveEqualTo>** sentimentNameToEnumOut)
    {
        static const std::unordered_map<Sentiment, std::string, EnumHash> sentimentEnumToName = {
            {Sentiment::Default, "Default"}, {Sentiment::Positive, "Positive"}, {Sentiment::Destructive, "Destructive"}};
        static const auto sentimentNameToEnum = GenerateStringToEnumMap<Sentiment>(sentimentEnumToName);

        if (sentimentEnumToNameOut)
        {
            *sentimentEnumToNameOut = &sentimentEnumToName;
        }

        if (sentimentNameToEnumOut)
        {
            *sentimentNameToEnumOut = &sentimentNameToEnum;
        }
    }

    const std::string AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey type)
    {
        const std::unordered_map<AdaptiveCardSchemaKey, std::string, EnumHash>* adaptiveCardSchemaKeyEnumToName = nullptr;
        GetAdaptiveCardSchemaKeyEnumMappings(&adaptiveCardSchemaKeyEnumToName, nullptr);

        if (adaptiveCardSchemaKeyEnumToName->find(type) == adaptiveCardSchemaKeyEnumToName->end())
        {
            throw std::out_of_range("Invalid AdaptiveCardSchemaKey");
        }

        return adaptiveCardSchemaKeyEnumToName->at(type);
    }

    AdaptiveCardSchemaKey AdaptiveCardSchemaKeyFromString(const std::string& type)
    {
        const std::unordered_map<std::string, AdaptiveCardSchemaKey, CaseInsensitiveHash, CaseInsensitiveEqualTo>* adaptiveCardSchemaKeyNameToEnum;
        GetAdaptiveCardSchemaKeyEnumMappings(nullptr, &adaptiveCardSchemaKeyNameToEnum);

        if (adaptiveCardSchemaKeyNameToEnum->find(type) == adaptiveCardSchemaKeyNameToEnum->end())
        {
            throw std::out_of_range("Invalid AdaptiveCardSchemaKey: " + type);
        }

        return adaptiveCardSchemaKeyNameToEnum->at(type);
    }

    const std::string CardElementTypeToString(CardElementType elementType)
    {
        const std::unordered_map<CardElementType, std::string, EnumHash>* cardElementTypeEnumToName;
        GetCardElementTypeEnumMappings(&cardElementTypeEnumToName, nullptr);

        if (cardElementTypeEnumToName->find(elementType) == cardElementTypeEnumToName->end())
        {
            throw std::out_of_range("Invalid CardElementType");
        }

        return cardElementTypeEnumToName->at(elementType);
    }

    CardElementType CardElementTypeFromString(const std::string& elementType)
    {
        const std::unordered_map<std::string, CardElementType, CaseInsensitiveHash, CaseInsensitiveEqualTo>* cardElementTypeNameToEnum;
        GetCardElementTypeEnumMappings(nullptr, &cardElementTypeNameToEnum);

        if (cardElementTypeNameToEnum->find(elementType) == cardElementTypeNameToEnum->end())
        {
            return CardElementType::Unsupported;
        }

        return cardElementTypeNameToEnum->at(elementType);
    }

    const std::string ActionTypeToString(ActionType actionType)
    {
        const std::unordered_map<ActionType, std::string, EnumHash>* actionTypeEnumToName;
        GetActionTypeEnumMappings(&actionTypeEnumToName, nullptr);

        if (actionTypeEnumToName->find(actionType) == actionTypeEnumToName->end())
        {
            throw std::out_of_range("Invalid ActionType");
        }

        return actionTypeEnumToName->at(actionType);
    }

    ActionType ActionTypeFromString(const std::string& actionType)
    {
        const std::unordered_map<std::string, ActionType, CaseInsensitiveHash, CaseInsensitiveEqualTo>* actionTypeNameToEnum;
        GetActionTypeEnumMappings(nullptr, &actionTypeNameToEnum);

        if (actionTypeNameToEnum->find(actionType) == actionTypeNameToEnum->end())
        {
            return ActionType::Unsupported;
        }

        return actionTypeNameToEnum->at(actionType);
    }

    const std::string HeightTypeToString(HeightType heightType)
    {
        const std::unordered_map<HeightType, std::string, EnumHash>* heightTypeEnumToName;
        GetHeightTypeEnumMappings(&heightTypeEnumToName, nullptr);

        if (heightTypeEnumToName->find(heightType) == heightTypeEnumToName->end())
        {
            throw std::out_of_range("Invalid HeightType type");
        }

        return heightTypeEnumToName->at(heightType);
    }

    HeightType HeightTypeFromString(const std::string& heightType)
    {
        const std::unordered_map<std::string, HeightType, CaseInsensitiveHash, CaseInsensitiveEqualTo>* heightTypeNameToEnum;
        GetHeightTypeEnumMappings(nullptr, &heightTypeNameToEnum);

        if (heightTypeNameToEnum->find(heightType) == heightTypeNameToEnum->end())
        {
            return HeightType::Auto;
        }

        return heightTypeNameToEnum->at(heightType);
    }

    const std::string HorizontalAlignmentToString(HorizontalAlignment alignment)
    {
        const std::unordered_map<HorizontalAlignment, std::string, EnumHash>* horizontalAlignmentEnumToName;
        GetHorizontalAlignmentEnumMappings(&horizontalAlignmentEnumToName, nullptr);

        if (horizontalAlignmentEnumToName->find(alignment) == horizontalAlignmentEnumToName->end())
        {
            throw std::out_of_range("Invalid HorizontalAlignment type");
        }
        return horizontalAlignmentEnumToName->at(alignment);
    }

    HorizontalAlignment HorizontalAlignmentFromString(const std::string& alignment)
    {
        const std::unordered_map<std::string, HorizontalAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>* horizontalAlignmentNameToEnum;
        GetHorizontalAlignmentEnumMappings(nullptr, &horizontalAlignmentNameToEnum);

        if (horizontalAlignmentNameToEnum->find(alignment) == horizontalAlignmentNameToEnum->end())
        {
            return HorizontalAlignment::Left;
        }

        return horizontalAlignmentNameToEnum->at(alignment);
    }

    const std::string ForegroundColorToString(ForegroundColor color)
    {
        const std::unordered_map<ForegroundColor, std::string, EnumHash>* colorEnumToName;
        GetColorEnumMappings(&colorEnumToName, nullptr);

        if (colorEnumToName->find(color) == colorEnumToName->end())
        {
            throw std::out_of_range("Invalid ForegroundColor type");
        }
        return colorEnumToName->at(color);
    }

    ForegroundColor ForegroundColorFromString(const std::string& color)
    {
        const std::unordered_map<std::string, ForegroundColor, CaseInsensitiveHash, CaseInsensitiveEqualTo>* colorNameToEnum;
        GetColorEnumMappings(nullptr, &colorNameToEnum);

        if (colorNameToEnum->find(color) == colorNameToEnum->end())
        {
            return ForegroundColor::Default;
        }

        return colorNameToEnum->at(color);
    }

    const std::string TextWeightToString(TextWeight weight)
    {
        const std::unordered_map<TextWeight, std::string, EnumHash>* textWeightEnumToName;
        GetTextWeightEnumMappings(&textWeightEnumToName, nullptr);

        if (textWeightEnumToName->find(weight) == textWeightEnumToName->end())
        {
            throw std::out_of_range("Invalid TextWeight type");
        }
        return textWeightEnumToName->at(weight);
    }

    TextWeight TextWeightFromString(const std::string& weight)
    {
        const std::unordered_map<std::string, TextWeight, CaseInsensitiveHash, CaseInsensitiveEqualTo>* textWeightNameToEnum;
        GetTextWeightEnumMappings(nullptr, &textWeightNameToEnum);

        if (textWeightNameToEnum->find(weight) == textWeightNameToEnum->end())
        {
            return TextWeight::Default;
        }

        return textWeightNameToEnum->at(weight);
    }

    const std::string TextSizeToString(TextSize size)
    {
        const std::unordered_map<TextSize, std::string, EnumHash>* textSizeEnumToName;
        GetTextSizeEnumMappings(&textSizeEnumToName, nullptr);

        if (textSizeEnumToName->find(size) == textSizeEnumToName->end())
        {
            throw std::out_of_range("Invalid TextSize type");
        }
        return textSizeEnumToName->at(size);
    }

    TextSize TextSizeFromString(const std::string& size)
    {
        const std::unordered_map<std::string, TextSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>* textSizeNameToEnum;
        GetTextSizeEnumMappings(nullptr, &textSizeNameToEnum);

        if (textSizeNameToEnum->find(size) == textSizeNameToEnum->end())
        {
            return TextSize::Default;
        }

        return textSizeNameToEnum->at(size);
    }

    const std::string ImageSizeToString(ImageSize size)
    {
        const std::unordered_map<ImageSize, std::string, EnumHash>* imageSizeEnumToName;
        GetImageSizeEnumMappings(&imageSizeEnumToName, nullptr);

        if (imageSizeEnumToName->find(size) == imageSizeEnumToName->end())
        {
            throw std::out_of_range("Invalid ImageSize type");
        }
        return imageSizeEnumToName->at(size);
    }

    ImageSize ImageSizeFromString(const std::string& size)
    {
        const std::unordered_map<std::string, ImageSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>* imageSizeNameToEnum;
        GetImageSizeEnumMappings(nullptr, &imageSizeNameToEnum);

        if (imageSizeNameToEnum->find(size) == imageSizeNameToEnum->end())
        {
            return ImageSize::Auto;
        }

        return imageSizeNameToEnum->at(size);
    }

    const std::string SpacingToString(Spacing spacing)
    {
        const std::unordered_map<Spacing, std::string, EnumHash>* spacingEnumToName;
        GetSpacingMappings(&spacingEnumToName, nullptr);

        if (spacingEnumToName->find(spacing) == spacingEnumToName->end())
        {
            throw std::out_of_range("Invalid Spacing type");
        }
        return spacingEnumToName->at(spacing);
    }

    Spacing SpacingFromString(const std::string& spacing)
    {
        const std::unordered_map<std::string, Spacing, CaseInsensitiveHash, CaseInsensitiveEqualTo>* spacingNameToEnum;
        GetSpacingMappings(nullptr, &spacingNameToEnum);

        if (spacingNameToEnum->find(spacing) == spacingNameToEnum->end())
        {
            return Spacing::Default;
        }

        return spacingNameToEnum->at(spacing);
    }

    const std::string SeparatorThicknessToString(SeparatorThickness thickness)
    {
        const std::unordered_map<SeparatorThickness, std::string, EnumHash>* separatorThicknessEnumToName;
        GetSeparatorThicknessEnumMappings(&separatorThicknessEnumToName, nullptr);

        if (separatorThicknessEnumToName->find(thickness) == separatorThicknessEnumToName->end())
        {
            throw std::out_of_range("Invalid SeparatorThickness type");
        }
        return separatorThicknessEnumToName->at(thickness);
    }

    SeparatorThickness SeparatorThicknessFromString(const std::string& thickness)
    {
        const std::unordered_map<std::string, SeparatorThickness, CaseInsensitiveHash, CaseInsensitiveEqualTo>* separatorThicknessNameToEnum;
        GetSeparatorThicknessEnumMappings(nullptr, &separatorThicknessNameToEnum);

        if (separatorThicknessNameToEnum->find(thickness) == separatorThicknessNameToEnum->end())
        {
            return SeparatorThickness::Default;
        }

        return separatorThicknessNameToEnum->at(thickness);
    }

    const std::string ImageStyleToString(ImageStyle style)
    {
        const std::unordered_map<ImageStyle, std::string, EnumHash>* imageStyleEnumToName;
        GetImageStyleEnumMappings(&imageStyleEnumToName, nullptr);

        if (imageStyleEnumToName->find(style) == imageStyleEnumToName->end())
        {
            throw std::out_of_range("Invalid ImageStyle style");
        }
        return imageStyleEnumToName->at(style);
    }

    ImageStyle ImageStyleFromString(const std::string& style)
    {
        const std::unordered_map<std::string, ImageStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>* imageStyleNameToEnum;
        GetImageStyleEnumMappings(nullptr, &imageStyleNameToEnum);

        if (imageStyleNameToEnum->find(style) == imageStyleNameToEnum->end())
        {
            return ImageStyle::Default;
        }

        return imageStyleNameToEnum->at(style);
    }

    const std::string ActionsOrientationToString(ActionsOrientation orientation)
    {
        const std::unordered_map<ActionsOrientation, std::string, EnumHash>* actionsOrientationEnumToName;
        GetActionsOrientationEnumMappings(&actionsOrientationEnumToName, nullptr);

        if (actionsOrientationEnumToName->find(orientation) == actionsOrientationEnumToName->end())
        {
            throw std::out_of_range("Invalid ActionsOrientation type");
        }
        return actionsOrientationEnumToName->at(orientation);
    }

    ActionsOrientation ActionsOrientationFromString(const std::string& orientation)
    {
        const std::unordered_map<std::string, ActionsOrientation, CaseInsensitiveHash, CaseInsensitiveEqualTo>* actionsOrientationNameToEnum;
        GetActionsOrientationEnumMappings(nullptr, &actionsOrientationNameToEnum);

        if (actionsOrientationNameToEnum->find(orientation) == actionsOrientationNameToEnum->end())
        {
            return ActionsOrientation::Horizontal;
        }
        return actionsOrientationNameToEnum->at(orientation);
    }

    const std::string ActionModeToString(ActionMode mode)
    {
        const std::unordered_map<ActionMode, std::string, EnumHash>* actionModeEnumToName;
        GetActionModeEnumMappings(&actionModeEnumToName, nullptr);

        if (actionModeEnumToName->find(mode) == actionModeEnumToName->end())
        {
            throw std::out_of_range("Invalid ActionMode type");
        }
        return actionModeEnumToName->at(mode);
    }

    ActionMode ActionModeFromString(const std::string& mode)
    {
        const std::unordered_map<std::string, ActionMode, CaseInsensitiveHash, CaseInsensitiveEqualTo>* actionModeNameToEnum;
        GetActionModeEnumMappings(nullptr, &actionModeNameToEnum);

        if (actionModeNameToEnum->find(mode) == actionModeNameToEnum->end())
        {
            return ActionMode::Inline;
        }
        return actionModeNameToEnum->at(mode);
    }

    const std::string ChoiceSetStyleToString(ChoiceSetStyle style)
    {
        const std::unordered_map<ChoiceSetStyle, std::string, EnumHash>* choiceSetStyleEnumToName;
        GetChoiceSetStyleEnumMappings(&choiceSetStyleEnumToName, nullptr);

        if (choiceSetStyleEnumToName->find(style) == choiceSetStyleEnumToName->end())
        {
            throw std::out_of_range("Invalid ChoiceSetStyle");
        }
        return choiceSetStyleEnumToName->at(style);
    }

    ChoiceSetStyle ChoiceSetStyleFromString(const std::string& style)
    {
        const std::unordered_map<std::string, ChoiceSetStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>* choiceSetStyleNameToEnum;
        GetChoiceSetStyleEnumMappings(nullptr, &choiceSetStyleNameToEnum);

        if (choiceSetStyleNameToEnum->find(style) == choiceSetStyleNameToEnum->end())
        {
            return ChoiceSetStyle::Compact;
        }
        return choiceSetStyleNameToEnum->at(style);
    }

    const std::string TextInputStyleToString(TextInputStyle style)
    {
        const std::unordered_map<TextInputStyle, std::string, EnumHash>* textInputStyleEnumToName;
        GetTextInputStyleEnumMappings(&textInputStyleEnumToName, nullptr);

        if (textInputStyleEnumToName->find(style) == textInputStyleEnumToName->end())
        {
            throw std::out_of_range("Invalid TextInputStyle");
        }
        return textInputStyleEnumToName->at(style);
    }

    TextInputStyle TextInputStyleFromString(const std::string& style)
    {
        const std::unordered_map<std::string, TextInputStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>* textInputStyleNameToEnum;
        GetTextInputStyleEnumMappings(nullptr, &textInputStyleNameToEnum);

        if (textInputStyleNameToEnum->find(style) == textInputStyleNameToEnum->end())
        {
            return TextInputStyle::Text;
        }
        return textInputStyleNameToEnum->at(style);
    }

    const std::string ContainerStyleToString(ContainerStyle style)
    {
        const std::unordered_map<ContainerStyle, std::string, EnumHash>* containerStyleEnumToName;
        GetContainerStyleEnumMappings(&containerStyleEnumToName, nullptr);

        if (containerStyleEnumToName->find(style) == containerStyleEnumToName->end())
        {
            throw std::out_of_range("Invalid ContainerStyle");
        }
        return containerStyleEnumToName->at(style);
    }

    ContainerStyle ContainerStyleFromString(const std::string& style)
    {
        const std::unordered_map<std::string, ContainerStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>* containerStyleNameToEnum;
        GetContainerStyleEnumMappings(nullptr, &containerStyleNameToEnum);

        if (containerStyleNameToEnum->find(style) == containerStyleNameToEnum->end())
        {
            return ContainerStyle::Default;
        }
        return containerStyleNameToEnum->at(style);
    }

    const std::string ActionAlignmentToString(ActionAlignment alignment)
    {
        const std::unordered_map<ActionAlignment, std::string, EnumHash>* actionAlignmentEnumToName;
        GetActionAlignmentEnumMappings(&actionAlignmentEnumToName, nullptr);

        if (actionAlignmentEnumToName->find(alignment) == actionAlignmentEnumToName->end())
        {
            throw std::out_of_range("Invalid ActionAlignment");
        }
        return actionAlignmentEnumToName->at(alignment);
    }

    ActionAlignment ActionAlignmentFromString(const std::string& alignment)
    {
        const std::unordered_map<std::string, ActionAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>* actionAlignmentNameToEnum;
        GetActionAlignmentEnumMappings(nullptr, &actionAlignmentNameToEnum);

        if (actionAlignmentNameToEnum->find(alignment) == actionAlignmentNameToEnum->end())
        {
            return ActionAlignment::Left;
        }
        return actionAlignmentNameToEnum->at(alignment);
    }

    const std::string IconPlacementToString(IconPlacement placement)
    {
        const std::unordered_map<IconPlacement, std::string, EnumHash>* iconPlacementEnumToName;
        GetIconPlacementEnumMappings(&iconPlacementEnumToName, nullptr);

        if (iconPlacementEnumToName->find(placement) == iconPlacementEnumToName->end())
        {
            throw std::out_of_range("Invalid IconPlacement");
        }
        return iconPlacementEnumToName->at(placement);
    }

    IconPlacement IconPlacementFromString(const std::string& placement)
    {
        const std::unordered_map<std::string, IconPlacement, CaseInsensitiveHash, CaseInsensitiveEqualTo>* iconPlacementNameToEnum;
        GetIconPlacementEnumMappings(nullptr, &iconPlacementNameToEnum);

        if (iconPlacementNameToEnum->find(placement) == iconPlacementNameToEnum->end())
        {
            return IconPlacement::AboveTitle;
        }
        return iconPlacementNameToEnum->at(placement);
    }

    const std::string VerticalContentAlignmentToString(VerticalContentAlignment verticalContentAlignment)
    {
        const std::unordered_map<VerticalContentAlignment, std::string, EnumHash>* verticalContentAlignmentEnumToName;
        GetVerticalContentAlignmentEnumMappings(&verticalContentAlignmentEnumToName, nullptr);

        if (verticalContentAlignmentEnumToName->find(verticalContentAlignment) == verticalContentAlignmentEnumToName->end())
        {
            throw std::out_of_range("Invalid VerticalContentAlignment");
        }
        return verticalContentAlignmentEnumToName->at(verticalContentAlignment);
    }

    VerticalContentAlignment VerticalContentAlignmentFromString(const std::string& verticalContentAlignment)
    {
        const std::unordered_map<std::string, VerticalContentAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>* verticalContentAlignmentNameToEnum;
        GetVerticalContentAlignmentEnumMappings(nullptr, &verticalContentAlignmentNameToEnum);

        if (verticalContentAlignmentNameToEnum->find(verticalContentAlignment) == verticalContentAlignmentNameToEnum->end())
        {
            return VerticalContentAlignment::Top;
        }
        return verticalContentAlignmentNameToEnum->at(verticalContentAlignment);
    }

    const std::string SentimentToString(Sentiment sentiment)
    {
        const std::unordered_map<Sentiment, std::string, EnumHash>* sentimentEnumToName;
        GetSentimentEnumMappings(&sentimentEnumToName, nullptr);

        if (sentimentEnumToName->find(sentiment) == sentimentEnumToName->end())
        {
            throw std::out_of_range("Invalid Sentiment");
        }
        return sentimentEnumToName->at(sentiment);
    }

    Sentiment SentimentFromString(const std::string& sentiment)
    {
        const std::unordered_map<std::string, Sentiment, CaseInsensitiveHash, CaseInsensitiveEqualTo>* sentimentNameToEnum;
        GetSentimentEnumMappings(nullptr, &sentimentNameToEnum);

        if (sentimentNameToEnum->find(sentiment) == sentimentNameToEnum->end())
        {
            return Sentiment::Default;
        }
        return sentimentNameToEnum->at(sentiment);
    }
}

#ifdef USE_CPPCORECHECK
#pragma warning(pop)
#endif
