---
title: Classe CTypedPtrArray | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTypedPtrArray
- AFXTEMPL/CTypedPtrArray
- AFXTEMPL/CTypedPtrArray::Add
- AFXTEMPL/CTypedPtrArray::Append
- AFXTEMPL/CTypedPtrArray::Copy
- AFXTEMPL/CTypedPtrArray::ElementAt
- AFXTEMPL/CTypedPtrArray::GetAt
- AFXTEMPL/CTypedPtrArray::InsertAt
- AFXTEMPL/CTypedPtrArray::SetAt
- AFXTEMPL/CTypedPtrArray::SetAtGrow
dev_langs:
- C++
helpviewer_keywords:
- pointer arrays
- CTypedPtrArray class
ms.assetid: e3ecdf1a-a889-4156-92dd-ddbd36ccd919
caps.latest.revision: 22
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 24b21d017d46cc88d7e243aff75ccf6383d2c870
ms.lasthandoff: 02/25/2017

---
# <a name="ctypedptrarray-class"></a>Classe CTypedPtrArray
Fornece um "wrapper" de tipo seguro para objetos da classe `CPtrArray` ou `CObArray`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class BASE_CLASS, class TYPE>  
class CTypedPtrArray : public BASE_CLASS  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `BASE_CLASS`  
 Classe base da classe array ponteiro tipado; deve ser uma classe de matriz ( `CObArray` ou `CPtrArray`).  
  
 `TYPE`  
 Tipo dos elementos armazenados na matriz de classe base.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTypedPtrArray::Add](#add)|Adiciona um novo elemento ao final de uma matriz. Aumenta a matriz quando necessário|  
|[CTypedPtrArray::Append](#append)|Adiciona o conteúdo de uma matriz ao final do outro. Aumenta a matriz quando necessário|  
|[CTypedPtrArray::Copy](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CTypedPtrArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|  
|[CTypedPtrArray::GetAt](#getat)|Retorna o valor a um determinado índice.|  
|[CTypedPtrArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|  
|[CTypedPtrArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|  
|[CTypedPtrArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CTypedPtrArray::operator]](#operator_at)|Define ou obtém o elemento no índice especificado.|  
  
## <a name="remarks"></a>Comentários  
 Quando você usa `CTypedPtrArray` em vez de `CPtrArray` ou `CObArray`, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiro incompatíveis.  
  
 Além disso, o `CTypedPtrArray` wrapper executa muito a conversão que seria necessária se você usou `CObArray` ou `CPtrArray`.  
  
 Porque todos os `CTypedPtrArray` funções embutidas, uso deste modelo não afeta significativamente o tamanho ou a velocidade do seu código.  
  
 Para obter mais informações sobre como usar o `CTypedPtrArray`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base no modelo](../../mfc/template-based-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `BASE_CLASS`  
  
 `CTypedPtrArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtempl.h  
  
##  <a name="add"></a>CTypedPtrArray::Add  
 Chama essa função de membro `BASE_CLASS` **:: adicionar**.  
  
```  
INT_PTR Add(TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Especifica o tipo de elemento a ser adicionado à matriz de parâmetro do modelo.  
  
 `newElement`  
 O elemento a ser adicionado a essa matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do elemento adicionado.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::Add](../../mfc/reference/cobarray-class.md#add).  
  
##  <a name="append"></a>CTypedPtrArray::Append  
 Chama essa função de membro `BASE_CLASS` **:: Append**.  
  
```  
INT_PTR Append(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BASE_CLASS`  
 Classe base da classe array ponteiro tipado; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).  
  
 *TIPO*  
 Tipo dos elementos armazenados na matriz de classe base.  
  
 *src*  
 Fonte dos elementos a ser anexado a uma matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro elemento anexado.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::Append](../../mfc/reference/cobarray-class.md#append).  
  
##  <a name="copy"></a>CTypedPtrArray::Copy  
 Chama essa função de membro `BASE_CLASS` **:: Copy**.  
  
```  
void Copy(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BASE_CLASS`  
 Classe base da classe array ponteiro tipado; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).  
  
 *TIPO*  
 Tipo dos elementos armazenados na matriz de classe base.  
  
 *src*  
 Fonte dos elementos a serem copiados para uma matriz.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::Copy](../../mfc/reference/cobarray-class.md#copy).  
  
##  <a name="elementat"></a>CTypedPtrArray::ElementAt  
 Essa função embutida chama `BASE_CLASS` **:: ElementAt**.  
  
```  
TYPE& ElementAt(INT_PTR nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo de elementos armazenados nesta matriz.  
  
 `nIndex`  
 Um índice de inteiro é maior que ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência temporária para o elemento no local especificado por `nIndex`. Esse elemento é do tipo especificado pelo parâmetro de modelo *tipo*.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat).  
  
##  <a name="getat"></a>CTypedPtrArray::GetAt  
 Essa função embutida chama `BASE_CLASS` **:: GetAt**.  
  
```  
TYPE GetAt(INT_PTR nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Especifica o tipo de elementos armazenados na matriz de parâmetro de modelo.  
  
 `nIndex`  
 Um índice de inteiro é maior que ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do elemento no local especificado pelo `nIndex`. Esse elemento é do tipo especificado pelo parâmetro de modelo *tipo*.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::GetAt](../../mfc/reference/cobarray-class.md#getat)  
  
##  <a name="insertat"></a>CTypedPtrArray::InsertAt  
 Chama essa função de membro `BASE_CLASS` **:: InsertAt**.  
  
```  
void InsertAt(
    INT_PTR nIndex,  
    TYPE newElement,  
    INT_PTR nCount = 1);

 
void InsertAt(
    INT_PTR nStartIndex,  
    CTypedPtrArray<BASE_CLASS, TYPE>* pNewArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro pode ser maior que o valor retornado por [CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).  
  
 *TIPO*  
 Tipo dos elementos armazenados na matriz de classe base.  
  
 `newElement`  
 O ponteiro de objeto para ser colocada nessa matriz. A `newElement` do valor **nulo** é permitido.  
  
 `nCount`  
 O número de vezes que esse elemento deve ser inserido (o padrão é 1).  
  
 `nStartIndex`  
 Um índice de inteiro pode ser maior que o valor retornado por `CObArray::GetUpperBound`.  
  
 `BASE_CLASS`  
 Classe base da classe array ponteiro tipado; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).  
  
 `pNewArray`  
 Outra matriz que contém os elementos a serem adicionados a essa matriz.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat).  
  
##  <a name="operator_at"></a>[CTypedPtrArray::operator]  
 Esses operadores embutido chamar `BASE_CLASS` **:: [] do operador**.  
  
```  
TYPE& operator[ ](int_ptr nindex);  
TYPE operator[ ](int_ptr nindex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Especifica o tipo de elementos armazenados na matriz de parâmetro de modelo.  
  
 `nIndex`  
 Um índice de inteiro é maior que ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.  
  
### <a name="remarks"></a>Comentários  
 O operador first, chamada para matrizes que não são **const**, pode ser usado em à direita (r-Value) ou à esquerda (l-value) de uma instrução de atribuição. A segunda chamada para **const** matrizes, pode ser usado apenas no lado direito.  
  
 A versão de depuração da biblioteca declara se o subscrito (tanto no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.  
  
##  <a name="setat"></a>CTypedPtrArray::SetAt  
 Chama essa função de membro `BASE_CLASS` **:: SetAt**.  
  
```  
void SetAt(
    INT_PTR nIndex,  
    TYPE ptr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro é maior que ou igual a 0 e menor ou igual ao valor retornado por [CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).  
  
 *TIPO*  
 Tipo dos elementos armazenados na matriz de classe base.  
  
 *PTR*  
 Um ponteiro para o elemento a ser inserido na matriz na nIndex. Um valor NULL é permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::SetAt](../../mfc/reference/cobarray-class.md#setat).  
  
##  <a name="setatgrow"></a>CTypedPtrArray::SetAtGrow  
 Chama essa função de membro `BASE_CLASS` **:: SetAtGrow**.  
  
```  
void SetAtGrow(
    INT_PTR nIndex,  
    TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0.  
  
 *TIPO*  
 Tipo dos elementos armazenados na matriz de classe base.  
  
 `newElement`  
 O ponteiro de objeto a ser adicionado a essa matriz. A **nulo** valor permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CObArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CPtrArray](../../mfc/reference/cptrarray-class.md)   
 [Classe CObArray](../../mfc/reference/cobarray-class.md)

