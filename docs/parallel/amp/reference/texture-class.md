---
title: Classe Texture | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- texture
- AMP_GRAPHICS/texture
- AMP_GRAPHICS/concurrency::graphics::texture::texture
- AMP_GRAPHICS/concurrency::graphics::texture::copy_to
- AMP_GRAPHICS/concurrency::graphics::texture::data
- AMP_GRAPHICS/concurrency::graphics::texture::get
- AMP_GRAPHICS/concurrency::graphics::texture::get_associated_accelerator_view
- AMP_GRAPHICS/concurrency::graphics::texture::get_depth_pitch
- AMP_GRAPHICS/concurrency::graphics::texture::get_row_pitch
- AMP_GRAPHICS/concurrency::graphics::texture::set
- AMP_GRAPHICS/concurrency::graphics::texture::rank
- AMP_GRAPHICS/concurrency::graphics::texture::associated_accelerator_view
- AMP_GRAPHICS/concurrency::graphics::texture::depth_pitch
- AMP_GRAPHICS/concurrency::graphics::texture::row_pitch
dev_langs:
- C++
ms.assetid: 16e85d4d-e80a-474a-995d-8bf63fbdf34c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 822797fb04104b28cf72f8d8ea4291a5ad283d20
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="texture-class"></a>Classe texture
Uma textura é uma agregação de dados um `accelerator_view` no domínio de extensão. É uma coleção de variáveis para cada elemento em um domínio de extensão. Cada variável contém um valor que corresponde ao tipo primitivo do C++ ( `unsigned int`, `int`, `float`, `double`), um tipo escalar ( `norm`, ou `unorm`), ou um tipo vector curto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename value_type,  int _Rank>  
class texture;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo dos elementos na textura.  
  
 `_Rank`  
 A classificação da textura.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`scalar_type`|Tipos escalares.|  
|`value_type`|Tipos de valor.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de textura](#ctor)|Inicializa uma nova instância da classe `texture`.|  
|[~ Destruidor de textura](#ctor)|Destrói a `texture` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[copy_to](#copy_to)|Copia o `texture` objeto para o destino, fazendo uma cópia profunda.|  
|[data](#data)|Retorna um ponteiro de CPU para os dados brutos desse textura.|  
|[get](#get)|Retorna o valor do elemento no índice especificado.|  
|[get_associated_accelerator_view](#get_associated_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) que é o destino preferencial para esse textura a ser copiado para.|  
|[get_depth_pitch](#get_depth_pitch)|Retorna o número de bytes entre cada fatia de profundidade em uma 3D preparo textura na CPU.|  
|[get_row_pitch](#get_row_pitch)|Retorna o número de bytes entre cada linha em uma 2D ou 3D preparo textura na CPU.|  
|[set](#set)|Define o valor do elemento no índice especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator()](#operator_call)|Retorna o valor do elemento que é especificado pelos parâmetros.|  
|[operator[]](#operator_at)|Retorna o elemento no índice especificado.|  
|[operator=](#operator_eq)|Copia especificado [textura](texture-class.md) deste objeto.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante de classificação](#rank)|Obtém a classificação do `texture` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[associated_accelerator_view](#associated_accelerator_view)|Obtém o [accelerator_view](accelerator-view-class.md) que é o destino preferencial para esse textura a ser copiado para.|  
|[depth_pitch](#depth_pitch)|Obtém o número de bytes entre cada fatia de profundidade em uma textura 3D de preparo na CPU.|  
|[row_pitch](#row_pitch)|Obtém o número de bytes entre cada linha em um 2D ou 3D preparo textura na CPU.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Texture_base`  
  
 `texture`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="dtor"></a> ~ textura 

 Destrói a `texture` objeto.  
  
```  
~texture() restrict(cpu);
```  
  
##  <a name="associated_accelerator_view"></a> associated_accelerator_view 

 Obtém o [accelerator_view](accelerator-view-class.md) que é o destino preferencial para esse textura a ser copiado para.  
  
```  
__declspec(property(get= get_associated_accelerator_view)) Concurrency::accelerator_view associated_accelerator_view;  
```  
  
##  <a name="copy_to"></a> copy_to 

 Copia o `texture` objeto para o destino, fazendo uma cópia profunda.  
  
```  
void copy_to(texture& _Dest) const; 
void copy_to(writeonly_texture_view<value_type, _Rank>& _Dest) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O objeto a ser copiado para.  
  
 `_Rank`  
 A classificação da textura.  
  
 `value_type`  
 O tipo dos elementos na textura.  
  
##  <a name="data"></a> data 

 Retorna um ponteiro de CPU para os dados brutos desse textura.  
  
```  
void* data() restrict(cpu);

 
const void* data() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para os dados brutos da textura.  
  
##  <a name="depth_pitch"></a> depth_pitch 

 Obtém o número de bytes entre cada fatia de profundidade em uma textura 3D de preparo na CPU.  
  
```  
__declspec(property(get= get_depth_pitch)) unsigned int depth_pitch;  
```  
  
##  <a name="get"></a> Obter 

 Retorna o valor do elemento no índice especificado.  
  
```  
const value_type get(const index<_Rank>& _Index) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento no índice especificado.  
  
##  <a name="get_associated_accelerator_view"></a> get_associated_accelerator_view 

 Retorna o que é o destino preferencial para esse textura a ser copiado para accelerator_view.  
  
```  
Concurrency::accelerator_view get_associated_accelerator_view() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [accelerator_view](accelerator-view-class.md) que é o destino preferencial para esse textura a ser copiado para.  
  
##  <a name="get_depth_pitch"></a> get_depth_pitch 

 Retorna o número de bytes entre cada fatia de profundidade em uma 3D preparo textura na CPU.  
  
```  
unsigned int get_depth_pitch() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes entre cada fatia de profundidade em uma 3D preparo textura na CPU.  
  
##  <a name="get_row_pitch"></a> get_row_pitch 

 Retorna o número de bytes entre cada linha em uma textura de preparo 2-dimensional ou entre cada linha de uma fatia de profundidade em 3-dimensional textura de preparo.  
  
```  
unsigned int get_row_pitch() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes entre cada linha em uma textura de preparo 2-dimensional ou entre cada linha de uma fatia de profundidade em 3-dimensional textura de preparo.  
  
##  <a name="operator_call"></a> operator() 

 Retorna o valor do elemento que é especificado pelos parâmetros.  
  
```  
const value_type operator() (
    const index<_Rank>& _Index) const restrict(amp);

 
const value_type operator() (
    int _I0) const restrict(amp);

 
const value_type operator() (
    int _I0,  
    int _I1) const restrict(amp);

 
const value_type operator() (
    int _I0,  
    int _I1,  
    int _I2) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice.  
  
 `_I0`  
 O componente mais significativo do índice.  
  
 `_I1`  
 O componente Avançar-para-mais significativo do índice.  
  
 `_I2`  
 O componente menos significativo do índice.  
  
 `_Rank`  
 A posição do índice.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento que é especificado pelos parâmetros.  
  
##  <a name="operator_at"></a> operador] 

 Retorna o elemento no índice especificado.  
  
```  
const value_type operator[] (const index<_Rank>& _Index) const restrict(amp);

 
const value_type operator[] (int _I0) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice.  
  
 `_I0`  
 O índice.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento no índice especificado.  
  
##  <a name="operator_eq"></a> operador = 

 Copia especificado [textura](texture-class.md) deste objeto.  
  
```  
texture& operator= (
    const texture& _Other);

 
texture& operator= (
    texture<value_type, _Rank>&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `texture` objeto do qual copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `texture` objeto.  
  
##  <a name="rank"></a> Classificação 

 Obtém a classificação do `texture` objeto.  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="row_pitch"></a> row_pitch 

 Obtém o número de bytes entre cada linha em um 2D ou 3D preparo textura na CPU.  
  
```  
__declspec(property(get= get_row_pitch)) unsigned int row_pitch;  
```  
  
##  <a name="set"></a> Definir 

 Define o valor do elemento no índice especificado.  
  
```  
void set(
    const index<_Rank>& _Index,  
    const value_type& value) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento.  
  
 `_Rank`  
 A posição do índice.  
  
 `value`  
 O novo valor do elemento.  
  
##  <a name="ctor"></a> textura 

 Inicializa uma nova instância da classe `texture`.  
  
```  
texture(const Concurrency::extent<_Rank>& _Ext) restrict(cpu);
 
texture(int _E0) restrict(cpu);
 
texture(int _E0, int _E1) restrict(cpu);
 
texture(int _E0, int _E1, int _E2) restrict(cpu);
 
texture(
    const Concurrency::extent<_Rank>& _Ext,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);
 
texture(
    int _E0,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);
 
texture(
    int _E0,  
    int _E1,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);
 
texture(
    int _E0,  
    int _E1,  
    int _E2,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);


template<typename _Input_iterator>  
texture(
    const Concurrency::extent<_Rank>& _Ext, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    int _E0, _Input_iterator _Src_first, _Input_iterator _Src_last) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    int _E0,  
    int _E1, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    int _E0,  
    int _E1,  
    int _E2, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    const Concurrency::extent<_Rank>& _Ext, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    int _E0, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    int _E0,  
    int _E1, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
template<typename _Input_iterator>  
texture(
    int _E0,  
    int _E1,  
    int _E2, 
    _Input_iterator _Src_first, 
    _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu))  ;  
 
texture(
    int _E0,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    int _E2,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    const Concurrency::extent<_Rank>& _Ext,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
texture(
    int _E0,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av)  ;  
 
texture(
    int _E0,  
    int _E1,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    int _E2,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
texture(
    const Concurrency::extent<_Rank>& _Ext,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    int _E0,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    int _E2,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element) restrict(cpu);

 
texture(
    const Concurrency::extent<_Rank>& _Ext,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av)  ;  
 
texture(
    int _E0,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    int _E2,  
    _In_ void* _Source,  
    unsigned int _Src_byte_size,  
    unsigned int _Bits_per_scalar_element,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
texture(
    const texture& _Src,  
    const Concurrency::accelerator_view& _Acc_view);

 
texture(
    texture&& _Other);

 
texture(
    const Concurrency::extent<_Rank>& _Ext,   
    unsigned int _Bits_per_scalar_element,   
    const Concurrency::accelerator_view& _Av);

 
texture(
    const texture& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Acc_view`  
 O [accelerator_view](accelerator-view-class.md) que especifica o local da textura.  
  
 `_Av`  
 O [accelerator_view](accelerator-view-class.md) que especifica o local da textura.  
  
 `_Associated_av`  
 Um accelerator_view que especifica o destino preferencial para cópias de ou para este textura.  
  
 `_Bits_per_scalar_element`  
 O número de bits por cada elemento escalar no tipo escalar subjacente da textura. Em geral, o valor com suporte são 8, 16, 32 e 64. Se 0 for especificado, o número de bits é o mesmo que o scalar_type subjacente. 64 só é válida para texturas com base em duplo.  
  
 `_Ext`  
 A extensão em cada dimensão da textura.  
  
 `_E0`  
 O fator mais significativo da textura.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da textura.  
  
 `_E2`  
 O componente menos significativo de extensão da textura.  
  
 `_Input_iterator`  
 O tipo de interator a entrada.  
  
 `_Mipmap_levels`  
 O número de níveis de mipmap na textura subjacente. Se 0 for especificado, a textura terá a gama completa de níveis de mipmap até o menor tamanho possível para a extensão especificada.  
  
 `_Rank`  
 A classificação da extensão.  
  
 `_Source`  
 Um ponteiro para um buffer do host.  
  
 `_Src`  
 A textura para copiar.  
  
 `_Src_byte_size`  
 O número de bytes no buffer de origem.  
  
 `_Src_first`  
 Um iterador de início para o recipiente de origem.  
  
 `_Src_last`  
 Um iterador final para o recipiente de origem.  
  
 `_Other`  
 Outra fonte de dados.  
  
 `_Rank`  
 A classificação da seção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
