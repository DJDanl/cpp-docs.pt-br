---
title: Auxiliares da classe de coleção
ms.date: 11/04/2016
helpviewer_keywords:
- DestructElements function
- ConstructElements function
- SerializeElements function
- collection classes [MFC], helper functions
- helper functions collection class [MFC]
ms.assetid: bc3a2368-9edd-4748-9e6a-13cba79517ca
ms.openlocfilehash: 04b142cde12a9795f217559f875eef7fcec3b0f2
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841422"
---
# <a name="collection-class-helpers"></a>Auxiliares da classe de coleção

As classes de coleção `CMap` , `CList` e `CArray` usam funções auxiliares globais modeladas para tais finalidades como comparar, copiar e serializar elementos. Como parte da implementação de classes baseadas em `CMap` , `CList` e `CArray` , você deve substituir essas funções conforme necessário com versões personalizadas para o tipo de dados armazenados em seu mapa, lista ou matriz. Para obter informações sobre como substituir funções auxiliares como `SerializeElements` , consulte o artigo [coleções: como criar uma coleção de tipo seguro](../../mfc/how-to-make-a-type-safe-collection.md). Observe que `ConstructElements` e foram `DestructElements` preteridos.

O biblioteca MFC fornece as seguintes funções globais em afxtempl. h para ajudá-lo a personalizar suas classes de coleção:

### <a name="collection-class-helpers"></a>Auxiliares da classe de coleção

|Nome|Descrição|
|-|-|
|[CompareElements](#compareelements)|Indica se os elementos são iguais.|
|[CopyElements](#copyelements)|Copia elementos de uma matriz para outra.|
|[DumpElements](#dumpelements)|Fornece saída de diagnóstico orientado a fluxo.|
|[HashKey](#hashkey)|Calcula uma chave de hash.|
|[SerializeElements](#serializeelements)|Armazena ou recupera elementos de ou para um arquivo morto.|

## <a name="compareelements"></a><a name="compareelements"></a> CompareElements

Chamado diretamente por [CList:: find] (CList-Class. MD # not_found. MD # clist__find e indiretamente por [cmap__lookup](cmap-class.md#lookup) e [cmap__operator &#91;&#93;](cmap-class.md#operator_at).

```
template<class TYPE, class ARG_TYPE>
BOOL AFXAPI
CompareElements(
    const TYPE* pElement1,
    const ARG_TYPE* pElement2);
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
O tipo do primeiro elemento a ser comparado.

*pElement1*<br/>
Ponteiro para o primeiro elemento a ser comparado.

*ARG_TYPE*<br/>
O tipo do segundo elemento a ser comparado.

*pElement2*<br/>
Ponteiro para o segundo elemento a ser comparado.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o objeto apontado por *pElement1* for igual ao objeto apontado por *pElement2*; caso contrário, 0.

### <a name="remarks"></a>Comentários

As `CMap` chamadas usam a `CMap` *chave* de parâmetros de modelo e *ARG_KEY*.

A implementação padrão retorna o resultado da comparação de * \* pElement1* e * \* pElement2*. Substitua essa função para que ela compare os elementos de uma maneira apropriada para seu aplicativo.

A linguagem C++ define o operador de comparação ( `==` ) para tipos simples ( **`char`** ,, **`int`** **`float`** e assim por diante), mas não define um operador de comparação para classes e estruturas. Se você quiser usar `CompareElements` ou para criar uma instância de uma das classes de coleção que a utiliza, deverá definir o operador de comparação ou a sobrecarga `CompareElements` com uma versão que retorna os valores apropriados.

### <a name="requirements"></a>Requisitos

   **Cabeçalho:** afxtempl. h

## <a name="copyelements"></a><a name="copyelements"></a> CopyElements

Essa função é chamada diretamente por [CArray:: Append](carray-class.md#append) e [CArray:: Copy](carray-class.md#copy).

```
template<class TYPE>
void AFXAPI CopyElements(
    TYPE* pDest,
    const TYPE* pSrc,
    INT_PTR nCount);
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos a serem copiados.

*pDest*<br/>
Ponteiro para o destino onde os elementos serão copiados.

*pSrc*<br/>
Ponteiro para a fonte dos elementos a serem copiados.

*nCount*<br/>
Número de elementos a serem copiados.

### <a name="remarks"></a>Comentários

A implementação padrão usa o operador de atribuição simples ( **=** ) para executar a operação de cópia. Se o tipo que está sendo copiado não tiver um operador sobrecarregado =, a implementação padrão executará uma cópia de bits.

Para obter informações sobre como implementar essa e outras funções auxiliares, consulte o artigo [coleções: como criar uma coleção de tipo seguro](../how-to-make-a-type-safe-collection.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl. h

## <a name="dumpelements"></a><a name="dumpelements"></a> DumpElements

Fornece saída de diagnóstico orientado a fluxo na forma de texto para os elementos da sua coleção quando substituídos.

```
template<class TYPE>
void  AFXAPI DumpElements(
    CDumpContext& dc,
    const TYPE* pElements,
    INT_PTR nCount);
```

### <a name="parameters"></a>parâmetros

*origem*<br/>
Contexto de despejo para despejar elementos.

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo dos elementos.

*pElements*<br/>
Ponteiro para os elementos a serem despejados.

*nCount*<br/>
Número de elementos a serem despejados.

### <a name="remarks"></a>Comentários

As `CArray::Dump` `CList::Dump` funções, e `CMap::Dump` chamam isso se a profundidade do despejo for maior que 0.

A implementação padrão não faz nada. Se os elementos da coleção forem derivados de `CObject` , sua substituição normalmente irá iterar pelos elementos da coleção, chamando `Dump` cada elemento por vez.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl. h

## <a name="hashkey"></a><a name="hashkey"></a> HashKey

Calcula um valor de hash para a chave fornecida.

```
template<class ARG_KEY>
AFX_INLINE UINT AFXAPI HashKey(ARG_KEY  key);
```

### <a name="parameters"></a>parâmetros

*ARG_KEY*<br/>
Parâmetro de modelo que especifica o tipo de dados usado para acessar as chaves de mapa.

*chave*<br/>
A chave cujo valor de hash deve ser calculado.

### <a name="return-value"></a>Valor Retornado

O valor de hash da chave.

### <a name="remarks"></a>Comentários

Essa função é chamada diretamente por [CMap:: RemoveKey](cmap-class.md#removekey) e indiretamente pelo operador [CMap:: Lookup](cmap-class.md#lookup) e [CMap:: Operator &#91;&#93;](cmap-class.md#operator_at).

A implementação padrão cria um valor de hash alternando a *tecla* para a direita em quatro posições. Substitua essa função para que ela retorne valores de hash apropriados para seu aplicativo.

### <a name="example"></a>Exemplo

```cpp
template <> UINT AFXAPI HashKey(unsigned __int64 key)
{
   // Generate the hash value by XORing the lower 32 bits of the number
   // with the upper 32 bits
   return(UINT(key) ^ UINT(key >> 32));
}
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl. h

## <a name="serializeelements"></a><a name="serializeelements"></a> SerializeElements

[CArray](carray-class.md), [CList](clist-class.md)e [CMap](cmap-class.md) chamam essa função para serializar elementos.

```
template<class TYPE>
void AFXAPI SerializeElements(CArchive& ar, TYPE* pElements, INT_PTR nCount);
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo dos elementos.

*multi-hop*<br/>
Um objeto de arquivo morto no qual arquivar.

*pElements*<br/>
Ponteiro para os elementos que estão sendo arquivados.

*nCount*<br/>
Número de elementos que estão sendo arquivados

### <a name="remarks"></a>Comentários

A implementação padrão faz uma leitura ou gravação de bit-nte.

Para obter informações sobre como implementar essa e outras funções auxiliares, consulte o artigo [coleções: como criar uma coleção de tipo seguro](../how-to-make-a-type-safe-collection.md).

### <a name="example"></a>Exemplo

Consulte o exemplo nas coleções de artigos [: como criar uma coleção de tipo seguro](../how-to-make-a-type-safe-collection.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe de CMap](cmap-class.md)<br/>
[Classe CList](clist-class.md)<br/>
[Classe CArray](carray-class.md)
