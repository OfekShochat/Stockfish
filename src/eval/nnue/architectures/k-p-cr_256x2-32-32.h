// NNUE�]���֐��ŗp������͓����ʂƃl�b�g���[�N�\���̒�`

#ifndef K_P_CR_256X2_32_32_H
#define K_P_CR_256X2_32_32_H

#include "../features/feature_set.h"
#include "../features/k.h"
#include "../features/p.h"
#include "../features/castling_right.h"

#include "../layers/input_slice.h"
#include "../layers/affine_transform.h"
#include "../layers/clipped_relu.h"

namespace Eval {

  namespace NNUE {

    // �]���֐��ŗp������͓�����
    using RawFeatures = Features::FeatureSet<Features::K, Features::P,
      Features::CastlingRight>;

    // �ϊ���̓��͓����ʂ̎�����
    constexpr IndexType kTransformedFeatureDimensions = 256;

    namespace Layers {

      // �l�b�g���[�N�\���̒�`
      using InputLayer = InputSlice<kTransformedFeatureDimensions * 2>;
      using HiddenLayer1 = ClippedReLU<AffineTransform<InputLayer, 32>>;
      using HiddenLayer2 = ClippedReLU<AffineTransform<HiddenLayer1, 32>>;
      using OutputLayer = AffineTransform<HiddenLayer2, 1>;

    }  // namespace Layers

    using Network = Layers::OutputLayer;

  }  // namespace NNUE

}  // namespace Eval
#endif // K_P_CR_256X2_32_32_H