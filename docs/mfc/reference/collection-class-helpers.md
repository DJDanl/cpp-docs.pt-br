---
title: Auxiliares da classe de coleção
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros.classes
helpviewer_keywords:
- DestructElements function
- ConstructElements function
- SerializeElements function
- collection classes [MFC], helper functions
- helper functions collection class [MFC]
ms.assetid: bc3a2368-9edd-4748-9e6a-13cba79517ca
ms.openlocfilehash: 3992e6c0cf25925e01858016e4bac93d5552fe8b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62373460"
---
# <a name="collection-class-helpers"></a>Auxiliares da classe de coleção

As classes de coleção `CMap`, `CList`, e `CArray` usar funções auxiliares global com modelo para esses fins, como comparação, copiando e serializando elementos. Como parte de sua implementação de classes com base na `CMap`, `CList`, e `CArray`, você deve substituir essas funções conforme necessário com as versões adaptadas para o tipo de dados armazenados no seu mapa, lista ou matriz. Para obter informações sobre substituição de funções auxiliares, como `SerializeElements`, consulte o artigo [coleções: Como fazer uma coleção fortemente tipada](../../mfc/how-to-make-a-type-safe-collection.md). Observe que `ConstructElements` e `DestructElements` foram preteridos.

A biblioteca Microsoft Foundation Class fornece as seguintes funções globais na afxtempl.h para ajudá-lo a personalizar suas classes de coleção:

### <a name="collection-class-helpers"></a>Auxiliares da classe de coleção

|||
|-|-|
|[CompareElements](#compareelements)|Indica se os elementos são iguais.|
|[CopyElements](#copyelements)|Copia os elementos de uma matriz para outra.|
|[DumpElements](#dumpelements)|Fornece a saída de diagnóstico orientada por fluxo.|
|[HashKey](#hashkey)|Calcula uma chave de hash.|
|[SerializeElements](#serializeelements)|Armazena ou recupera os elementos de ou para um arquivo morto.|

##  <a name="compareelements"></a>  CompareElements

Chamado diretamente pelo [CList::Find] (clist class.md not_found.md # #clist__find e indiretamente [cmap__lookup](cmap-class.md#lookup) e [cmap__operator &#91; &#93; ](cmap-class.md#operator_at).

```
template<class TYPE, class ARG_TYPE>
BOOL AFXAPI
CompareElements(
    const TYPE* pElement1,
    const ARG_TYPE* pElement2);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
O tipo do primeiro elemento a ser comparado.

*pElement1*<br/>
Ponteiro para o primeiro elemento a ser comparado.

*ARG_TYPE*<br/>
O tipo do segundo elemento a ser comparado.

*pElement2*<br/>
Ponteiro para o segundo elemento a ser comparado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto apontado por *pElement1* é igual ao objeto apontado por *pElement2*; caso contrário, 0.

### <a name="remarks"></a>Comentários

O `CMap` chama o uso de `CMap` parâmetros de modelo *chave* e *ARG_KEY*.

A implementação padrão retorna o resultado da comparação do  *\*pElement1* e  *\*pElement2*. Substitua essa função para que ele compara os elementos de uma maneira que é apropriado para seu aplicativo.

A linguagem C++ define o operador de comparação ( `==`) para tipos simples (**char**, **int**, **float**e assim por diante), mas não definem um operador de comparação classes e estruturas. Se você quiser usar `CompareElements` ou para instanciar uma das classes de coleção que usa-o, você deve definir o operador de comparação ou sobrecarregar `CompareElements` com uma versão que retorna os valores apropriados.

### <a name="requirements"></a>Requisitos

   **Cabeçalho:** afxtempl.h

##  <a name="copyelements"></a>  CopyElements

Essa função é chamada diretamente pelo [CArray::Append](carray-class.md#append) e [CArray::Copy](carray-class.md#copy).

```
template<class TYPE>
void AFXAPI CopyElements(
    TYPE* pDest,
    const TYPE* pSrc,
    INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos a serem copiados.

*pDest*<br/>
Ponteiro para o destino no qual os elementos serão copiados.

*pSrc*<br/>
Ponteiro para a origem dos elementos a serem copiados.

*nCount*<br/>
Número de elementos a serem copiados.

### <a name="remarks"></a>Comentários

A implementação padrão usa o operador de atribuição simples ( **=** ) para executar a operação de cópia. Se o tipo que está sendo copiado não tem um operador sobrecarregado =, em seguida, a implementação padrão executa uma cópia bit a bit.

Para obter informações sobre como implementar essas e outras funções de auxiliar, consulte o artigo [coleções: Como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).

### <a name="requirements"></a>Requisitos

  **Header** afxtempl.h

##  <a name="dumpelements"></a>  DumpElements

Fornece saída de diagnóstico orientada por fluxo na forma de texto para os elementos de sua coleção quando é substituído.

```
template<class TYPE>
void  AFXAPI DumpElements(
    CDumpContext& dc,
    const TYPE* pElements,
    INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*dc*<br/>
Contexto para despejar os elementos de despejo.

*TIPO*<br/>
Especifica o tipo dos elementos de parâmetro de modelo.

*pElements*<br/>
Ponteiro para os elementos a ser despejado.

*nCount*<br/>
Número de elementos a ser despejado.

### <a name="remarks"></a>Comentários

O `CArray::Dump`, `CList::Dump`, e `CMap::Dump` funções chamá-lo se a profundidade do despejo é maior que 0.

A implementação padrão não faz nada. Se os elementos de sua coleção derivam `CObject`, sua substituição normalmente irá iterar os elementos da coleção, chamando `Dump` para cada elemento, por sua vez.

### <a name="requirements"></a>Requisitos

  **Header** afxtempl.h

##  <a name="hashkey"></a>  HashKey

Calcula um valor de hash para a chave especificada.

```
template<class ARG_KEY>
AFX_INLINE UINT AFXAPI HashKey(ARG_KEY  key);
```

### <a name="parameters"></a>Parâmetros

*ARG_KEY*<br/>
Parâmetro de modelo especificando o tipo de dados usado para acessar as chaves do mapa.

*key*<br/>
A chave cujo valor de hash é calculado.

### <a name="return-value"></a>Valor de retorno

Valor de hash da chave.

### <a name="remarks"></a>Comentários

Essa função é chamada diretamente pelo [CMap::RemoveKey](cmap-class.md#removekey) e indiretamente [CMap::Lookup](cmap-class.md#lookup) e [CMap::Operator &#91; &#93; ](cmap-class.md#operator_at).

A implementação padrão cria um valor de hash com a mudança *chave* direita em quatro posições. Substitua essa função para que ele retorna valores de hash apropriada para seu aplicativo.

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

  **Header** afxtempl.h

##  <a name="serializeelements"></a>  SerializeElements

[CArray](carray-class.md), [CList](clist-class.md), e [CMap](cmap-class.md) chame essa função para serializar os elementos.

```
template<class TYPE>
void AFXAPI SerializeElements(CArchive& ar, TYPE* pElements, INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Especifica o tipo dos elementos de parâmetro de modelo.

*ar*<br/>
Um objeto de arquivo morto para arquivar ou para.

*pElements*<br/>
Ponteiro para os elementos que estão sendo arquivados.

*nCount*<br/>
Número de elementos que estão sendo arquivadas

### <a name="remarks"></a>Comentários

A implementação do padrão faz um bit a bit de leitura ou gravação.

Para obter informações sobre como implementar essas e outras funções de auxiliar, consulte o artigo [coleções: Como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).

### <a name="example"></a>Exemplo

Veja o exemplo neste artigo [coleções: Como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).

### <a name="requirements"></a>Requisitos

  **Header** afxtempl.h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CMap](cmap-class.md)<br/>
[Classe CList](clist-class.md)<br/>
[Classe CArray](carray-class.md)
