---
title: Classe Texture | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_graphics/Concurrency::graphics::texture
dev_langs:
- C++
ms.assetid: 16e85d4d-e80a-474a-995d-8bf63fbdf34c
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: aafb23ac4d366baed37f1cf667984253160af9c3
ms.lasthandoff: 02/25/2017

---
# <a name="texture-class"></a>Classe texture
Uma textura é uma agregação de dados um `accelerator_view` no domínio de extensão. É uma coleção de variáveis para cada elemento em um domínio de extensão. Cada variável contém um valor correspondente ao tipo primitivo do C++ ( `unsigned int`, `int`, `float`, `double`), um tipo escalar ( `norm`, ou `unorm`), ou um tipo de vetor curto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <
    typename value_type,  
    int _Rank  
>  
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
|[~ Destruidor de textura](#ctor)|Destrói o `texture` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método copy_to](#copy_to)|Copia o `texture` objeto para o destino, fazendo uma cópia em profundidade.|  
|[Método de dados](#data)|Retorna um ponteiro de CPU para os dados brutos desse textura.|  
|[Método Get](#get)|Retorna o valor do elemento no índice especificado.|  
|[Método get_associated_accelerator_view](#get_associated_accelerator_view)|Retorna o [accelerator_view](accelerator-view-class.md) que é o alvo preferencial para esse textura sejam copiados.|  
|[Método get_depth_pitch](#get_depth_pitch)|Retorna o número de bytes entre cada fatia de profundidade em uma 3D preparo textura na CPU.|  
|[Método get_row_pitch](#get_row_pitch)|Retorna o número de bytes entre cada linha em um 2D ou 3D preparo textura na CPU.|  
|[Método Set](#set)|Define o valor do elemento no índice especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador Operator)](#operator_call)|Retorna o valor do elemento especificado pelos parâmetros.|  
|[Operador do operador]](#operator_at)|Retorna o elemento no índice especificado.|  
|[operador Operator =](#operator_eq)|Copia especificado [textura](texture-class.md) objeto a este.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Rank](#rank)|Obtém a classificação do `texture` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados associated_accelerator_view](#associated_accelerator_view)|Obtém o [accelerator_view](accelerator-view-class.md) que é o alvo preferencial para esse textura sejam copiados.|  
|[Membro de dados depth_pitch](#depth_pitch)|Obtém o número de bytes entre cada fatia de profundidade em uma textura de preparo 3D na CPU.|  
|[Membro de dados row_pitch](#row_pitch)|Obtém o número de bytes entre cada linha em um 2D ou 3D preparo textura na CPU.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Texture_base`  
  
 `texture`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namedtora-texture"></a><a name="dtor"></a>~ textura 

 Destrói o `texture` objeto.  
  
```  
~texture() restrict(cpu);
```  
  
##  <a name="a-nameassociatedacceleratorviewa-associatedacceleratorview"></a><a name="associated_accelerator_view"></a>associated_accelerator_view 

 Obtém o [accelerator_view](accelerator-view-class.md) que é o alvo preferencial para esse textura sejam copiados.  
  
```  
__declspec(property(get= get_associated_accelerator_view)) Concurrency::accelerator_view associated_accelerator_view;  
```  
  
##  <a name="a-namecopytoa-copyto"></a><a name="copy_to"></a>copy_to 

 Copia o `texture` objeto para o destino, fazendo uma cópia em profundidade.  
  
```  
void copy_to(
    texture& _Dest) const;

 
 
void copy_to(
    writeonly_texture_view<value_type, _Rank>& _Dest) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 O objeto para copiar.  
  
 `_Rank`  
 A classificação da textura.  
  
 `value_type`  
 O tipo dos elementos na textura.  
  
##  <a name="a-namedataa-data"></a><a name="data"></a>dados 

 Retorna um ponteiro de CPU para os dados brutos desse textura.  
  
```  
void* data() restrict(cpu);

 
const void* data() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para os dados brutos da textura.  
  
##  <a name="a-namedepthpitcha-depthpitch"></a><a name="depth_pitch"></a>depth_pitch 

 Obtém o número de bytes entre cada fatia de profundidade em uma textura de preparo 3D na CPU.  
  
```  
__declspec(property(get= get_depth_pitch)) unsigned int depth_pitch;  
```  
  
##  <a name="a-namegeta-get"></a><a name="get"></a>Obter 

 Retorna o valor do elemento no índice especificado.  
  
```  
const value_type get(const index<_Rank>& _Index) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento no índice especificado.  
  
##  <a name="a-namegetassociatedacceleratorviewa-getassociatedacceleratorview"></a><a name="get_associated_accelerator_view"></a>get_associated_accelerator_view 

 Retorna o accelerator_view é o alvo preferencial para esse textura a serem copiados para.  
  
```  
Concurrency::accelerator_view get_associated_accelerator_view() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [accelerator_view](accelerator-view-class.md) que é o alvo preferencial para esse textura sejam copiados.  
  
##  <a name="a-namegetdepthpitcha-getdepthpitch"></a><a name="get_depth_pitch"></a>get_depth_pitch 

 Retorna o número de bytes entre cada fatia de profundidade em uma 3D preparo textura na CPU.  
  
```  
unsigned int get_depth_pitch() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes entre cada fatia de profundidade em uma 3D preparo textura na CPU.  
  
##  <a name="a-namegetrowpitcha-getrowpitch"></a><a name="get_row_pitch"></a>get_row_pitch 

 Retorna o número de bytes entre cada linha em uma textura de preparo 2 dimensional ou entre cada linha de uma fatia de profundidade em 3 dimensões de textura de preparo.  
  
```  
unsigned int get_row_pitch() const restrict(cpu);
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes entre cada linha em uma textura de preparo 2 dimensional ou entre cada linha de uma fatia de profundidade em 3 dimensões de textura de preparo.  
  
##  <a name="a-nameoperatorcalla-operator"></a><a name="operator_call"></a>Operator) 

 Retorna o valor do elemento especificado pelos parâmetros.  
  
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
 O valor do elemento especificado pelos parâmetros.  
  
##  <a name="a-nameoperatorata-operator"></a><a name="operator_at"></a>operador] 

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
  
##  <a name="a-nameoperatoreqa-operator"></a><a name="operator_eq"></a>operador = 

 Copia especificado [textura](texture-class.md) objeto a este.  
  
```  
texture& operator= (
    const texture& _Other);

 
texture& operator= (
    texture<value_type, _Rank>&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `texture` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `texture` objeto.  
  
##  <a name="a-nameranka-rank"></a><a name="rank"></a>classificação 

 Obtém a classificação do `texture` objeto.  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="a-namerowpitcha-rowpitch"></a><a name="row_pitch"></a>row_pitch 

 Obtém o número de bytes entre cada linha em um 2D ou 3D preparo textura na CPU.  
  
```  
__declspec(property(get= get_row_pitch)) unsigned int row_pitch;  
```  
  
##  <a name="a-nameseta-set"></a><a name="set"></a>definir 

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
  
##  <a name="a-namectora-texture"></a><a name="ctor"></a>textura 

 Inicializa uma nova instância da classe `texture`.  
  
```  
texture(
    const Concurrency::extent<_Rank>& _Ext) restrict(cpu);

 
texture(
    int _E0) restrict(cpu);

 
texture(
    int _E0,  
    int _E1) restrict(cpu);

 
texture(
    int _E0,  
    int _E1,  
    int _E2) restrict(cpu);

 
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

 
template<
    typename _Input_iterator  
>  
texture(
    const Concurrency::extent<_Rank>& _Ext, _Input_iterator _Src_first, _Input_iterator _Src_last) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    int _E0, _Input_iterator _Src_first, _Input_iterator _Src_last) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    int _E0,  
    int _E1, _Input_iterator _Src_first, _Input_iterator _Src_last) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    int _E0,  
    int _E1,  
    int _E2, _Input_iterator _Src_first, _Input_iterator _Src_last) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    const Concurrency::extent<_Rank>& _Ext, _Input_iterator _Src_first, _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    int _E0, _Input_iterator _Src_first, _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    int _E0,  
    int _E1, _Input_iterator _Src_first, _Input_iterator _Src_last,  
    const Concurrency::accelerator_view& _Av) restrict(cpu);

 
template<
    typename _Input_iterator  
>  
texture(
    int _E0,  
    int _E1,  
    int _E2, _Input_iterator _Src_first, _Input_iterator _Src_last,  
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
 Um accelerator_view que especifica o destino preferencial para cópias de ou para este tipo de textura.  
  
 `_Bits_per_scalar_element`  
 O número de bits por cada elemento escalar no tipo escalar subjacente da textura. Em geral, o valor com suporte são 8, 16, 32 e 64. Se 0 for especificado, o número de bits é o mesmo que o scalar_type subjacente. 64 só é válida para texturas com base em duplo.  
  
 `_Ext`  
 A extensão em cada dimensão da textura.  
  
 `_E0`  
 O fator mais significativo da textura.  
  
 `_E1`  
 O componente Avançar-para-mais significativo da textura.  
  
 `_E2`  
 O componente menos significativo da extensão da textura.  
  
 `_Input_iterator`  
 O tipo de interator de entrada.  
  
 `_Mipmap_levels`  
 O número de níveis de mipmap na textura subjacente. Se 0 for especificado, a textura terá toda a gama de níveis de mipmap até o menor tamanho possível para a extensão especificada.  
  
 `_Rank`  
 A classificação da extensão.  
  
 `_Source`  
 Um ponteiro para um buffer do host.  
  
 `_Src`  
 A textura para copiar.  
  
 `_Src_byte_size`  
 O número de bytes no buffer de origem.  
  
 `_Src_first`  
 Um iterador de início para o contêiner de origem.  
  
 `_Src_last`  
 Um iterador final no contêiner de origem.  
  
 `_Other`  
 Outra fonte de dados.  
  
 `_Rank`  
 A classificação da seção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

