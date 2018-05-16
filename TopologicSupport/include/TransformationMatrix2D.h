#pragma once

#include <Geom2d_Transformation.hxx>

#include <Utilities.h>

#include <memory>

namespace TopologicSupport
{
	class TransformationMatrix2D
	{
	public:
		typedef std::shared_ptr<TransformationMatrix2D> Ptr;

	public:
		TransformationMatrix2D(const Handle(Geom2d_Transformation) kpOcctTransformationMatrix2D);
		~TransformationMatrix2D();

	protected:
		Handle(Geom2d_Transformation) m_pOcctTransformationMatrix2D;
	};
}