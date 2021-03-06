#pragma once

#include <salviax/include/salviax_forward.h>
#include <eflib/include/utility/shared_declaration.h>

namespace salviar
{
	EFLIB_DECLARE_CLASS_SHARED_PTR(surface);
	EFLIB_DECLARE_CLASS_SHARED_PTR(renderer);
	struct renderer_parameters;
}

BEGIN_NS_SALVIAX();

EFLIB_DECLARE_CLASS_SHARED_PTR(swap_chain);
class swap_chain
{
public:
	virtual salviar::surface_ptr	get_surface()	= 0;
	virtual void					present()		= 0;
};

enum swap_chain_types
{
	swap_chain_none = 0UL,
    swap_chain_default = 1UL,
	swap_chain_d3d11= 2UL,
	swap_chain_gl	= 3UL
};

enum renderer_types
{
	renderer_none	= 0UL,
	renderer_async	= 1UL,
	renderer_sync	= 2UL
};

END_NS_SALVIAX();

extern "C"
{
	void salviax_create_swap_chain_and_renderer(
		salviax::swap_chain_ptr&			out_swap_chain,
		salviar::renderer_ptr&				out_renderer,
		salviar::renderer_parameters const*	render_params,
        uint32_t							renderer_type	= salviax::renderer_async,
		uint32_t		 					swap_chain_type	= salviax::swap_chain_default
	);
}