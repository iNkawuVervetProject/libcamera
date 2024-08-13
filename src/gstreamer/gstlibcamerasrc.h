/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2019, Collabora Ltd.
 *     Author: Nicolas Dufresne <nicolas.dufresne@collabora.com>
 *
 * GStreamer Capture Element
 */

#pragma once

#include <libcamera/control_ids.h>

#include <gst/gst.h>

G_BEGIN_DECLS

#define GST_TYPE_LIBCAMERA_SRC gst_libcamera_src_get_type()
G_DECLARE_FINAL_TYPE(GstLibcameraSrc, gst_libcamera_src,
		     GST_LIBCAMERA, SRC, GstElement)

G_END_DECLS

inline GType
gst_libcamera_auto_focus_get_type()
{
	static GType type = 0;
	static const GEnumValue values[] = {
		{
			static_cast<gint>(libcamera::controls::AfModeManual),
			"AfModeManual",
			"manual-focus",
		},
		{
			static_cast<gint>(libcamera::controls::AfModeAuto),
			"AfModeAuto",
			"automatic-auto-focus",
		},
		{
			static_cast<gint>(libcamera::controls::AfModeContinuous),
			"AfModeContinuous",
			"continuous-auto-focus",
		},
		{ 0, NULL, NULL }
	};

	if (!type)
		type = g_enum_register_static("GstLibcameraAutoFocus", values);

	return type;
}

inline GType
gst_libcamera_awb_get_type()
{
	static GType type = 0;
	static const GEnumValue values[] = {
		{
			static_cast<gint>(libcamera::controls::AwbAuto),
			"AwbAuto",
			"awb-auto",
		},
		{
			static_cast<gint>(libcamera::controls::AwbIncandescent),
			"AwbIncandescent",
			"awb-incandescent",
		},
		{
			static_cast<gint>(libcamera::controls::AwbTungsten),
			"AwbTungsten",
			"awb-tungsten",
		},
		{
			static_cast<gint>(libcamera::controls::AwbFluorescent),
			"AwbFluorescent",
			"awb-fluorescent",
		},
		{
			static_cast<gint>(libcamera::controls::AwbIndoor),
			"AwbIndoor",
			"awb-indoor",
		},
		{
			static_cast<gint>(libcamera::controls::AwbDaylight),
			"AwbDaylight",
			"awb-daylight",
		},
		{
			static_cast<gint>(libcamera::controls::AwbCloudy),
			"AwbCloudy",
			"awb-cloudy",
		},
		{
			static_cast<gint>(libcamera::controls::AwbCustom),
			"AwbCustom",
			"awb-custom",
		},
		{ 0, NULL, NULL },
	};

	if (!type)
		type = g_enum_register_static("GstLibcameraAWB", values);

	return type;
}

inline GType
gst_libcamera_auto_focus_range_get_type()
{
	static GType type = 0;
	static const GEnumValue values[] = {
		{
			static_cast<gint>(libcamera::controls::AfRangeNormal),
			"AfRangeNormal",
			"af-range-normal",
		},
		{
			static_cast<gint>(libcamera::controls::AfRangeMacro),
			"AfRangeMacro",
			"af-range-macro",
		},
		{
			static_cast<gint>(libcamera::controls::AfRangeFull),
			"AfRangeFull",
			"af-range-full",
		},
		{ 0, NULL, NULL },
	};

	if (!type)
		type = g_enum_register_static("GstLibcameraAutoFocusRange", values);

	return type;
}
