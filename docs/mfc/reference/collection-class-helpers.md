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
ms.openlocfilehash: 05fe49a4d8e6de92c584d40f3871f3efb906c7c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374811"
---
# <a name="collection-class-helpers"></a>Auxiliares da classe de coleção

As classes `CMap` `CList`de `CArray` coleção e o uso de funções de ajudante global modeladas para fins como comparação, cópia e serialização de elementos. Como parte de sua implementação `CList`de `CArray`classes baseadas em `CMap`, e , você deve substituir essas funções conforme necessário com versões adaptadas ao tipo de dados armazenados em seu mapa, lista ou matriz. Para obter informações sobre funções `SerializeElements`de ajudante sinuosas, como, consulte o artigo [Coleções: Como Fazer uma Coleção De Tipo seguro](../../mfc/how-to-make-a-type-safe-collection.md). Note `ConstructElements` isso `DestructElements` e foram preteridos.

A Biblioteca de Classes da Microsoft Foundation fornece as seguintes funções globais em afxtempl.h para ajudá-lo a personalizar suas aulas de coleção:

### <a name="collection-class-helpers"></a>Auxiliares da classe de coleção

|||
|-|-|
|[CompareElements](#compareelements)|Indica se os elementos são os mesmos.|
|[CopyElements](#copyelements)|Copia elementos de uma matriz para outra.|
|[DumpElements](#dumpelements)|Fornece saída de diagnóstico orientada a fluxo.|
|[HashKey](#hashkey)|Calcula uma chave hash.|
|[SerializeElements](#serializeelements)|Armazena ou recupera elementos para ou de um arquivo.|

## <a name="compareelements"></a><a name="compareelements"></a>CompareElementos

Chamado diretamente por [CList::Find](clist-class.md#not_found.md#clist__find e indiretamente por [cmap__lookup](cmap-class.md#lookup) e [cmap__operator &#91;&#93;](cmap-class.md#operator_at).

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

*Arg_type*<br/>
O tipo do segundo elemento a ser comparado.

*pElement2*<br/>
Ponteiro para o segundo elemento a ser comparado.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto apontado por *pElement1* for igual ao objeto apontado por *pElement2*; caso contrário, 0.

### <a name="remarks"></a>Comentários

As `CMap` chamadas `CMap` usam os parâmetros de modelo *KEY* e *ARG_KEY*.

A implementação padrão retorna o resultado da comparação de * \*pElement1* e * \*pElement2*. Anular esta função para que ela compare os elementos de uma forma apropriada para a sua aplicação.

A linguagem C++ define o `==`operador de comparação ( ) para tipos simples (**char**, **int,** **float**, e assim por diante), mas não define um operador de comparação para classes e estruturas. Se você quiser `CompareElements` usar ou instanciar uma das classes de coleta que `CompareElements` o utiliza, você deve definir o operador de comparação ou sobrecarregar com uma versão que devolva valores apropriados.

### <a name="requirements"></a>Requisitos

   **Cabeçalho:** afxtempl.h

## <a name="copyelements"></a><a name="copyelements"></a>CopyElements

Esta função é chamada diretamente por [CArray::Apêndice](carray-class.md#append) e [CArray::Copy](carray-class.md#copy).

```
template<class TYPE>
void AFXAPI CopyElements(
    TYPE* pDest,
    const TYPE* pSrc,
    INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos a serem copiados.

*pDest*<br/>
Ponteiro para o destino onde os elementos serão copiados.

*Psrc*<br/>
Ponteiro para a fonte dos elementos a serem copiados.

*Ncount*<br/>
Número de elementos a serem copiados.

### <a name="remarks"></a>Comentários

A implementação padrão usa **=** o operador de atribuição simples ( ) para executar a operação de cópia. Se o tipo que está sendo copiado não tiver um operador sobrecarregado=, então a implementação padrão executa uma cópia bitwise.

Para obter informações sobre a implementação desta e de outras funções auxiliares, consulte o artigo [Coleções: Como Fazer uma Coleção De Tipo Seguro](../how-to-make-a-type-safe-collection.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl.h

## <a name="dumpelements"></a><a name="dumpelements"></a>DumpElements

Fornece saída de diagnóstico orientada a fluxo em forma de texto para os elementos de sua coleção quando substituído.

```
template<class TYPE>
void  AFXAPI DumpElements(
    CDumpContext& dc,
    const TYPE* pElements,
    INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
Contexto de despejo para elementos de dumping.

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos.

*pElementos*<br/>
Ponteiro para os elementos a serem despejados.

*Ncount*<br/>
Número de elementos a serem despejados.

### <a name="remarks"></a>Comentários

As `CArray::Dump` `CList::Dump`funções `CMap::Dump` e funções chamam isso se a profundidade do lixão for maior que 0.

A implementação padrão não faz nada. Se os elementos de sua `CObject`coleção forem derivados, sua substituição tipicamente iterará através dos elementos da coleção, chamando `Dump` por cada elemento por sua vez.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl.h

## <a name="hashkey"></a><a name="hashkey"></a>HashKey

Calcula um valor de hash para a chave dada.

```
template<class ARG_KEY>
AFX_INLINE UINT AFXAPI HashKey(ARG_KEY  key);
```

### <a name="parameters"></a>Parâmetros

*Arg_key*<br/>
Parâmetro de modelo especificando o tipo de dados usado para acessar chaves do mapa.

*Chave*<br/>
A chave cujo valor de hash deve ser calculado.

### <a name="return-value"></a>Valor retornado

O valor de hash da chave.

### <a name="remarks"></a>Comentários

Esta função é chamada diretamente pelo [CMap::RemoveKey](cmap-class.md#removekey) e indiretamente por [CMap::Lookup](cmap-class.md#lookup) e [CMap::Operator &#91;&#93;](cmap-class.md#operator_at).

A implementação padrão cria um valor de hash deslocando *a chave* para a direita por quatro posições. Anular esta função para que ela retorne os valores de hash apropriados para sua aplicação.

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

  **Cabeçalho** afxtempl.h

## <a name="serializeelements"></a><a name="serializeelements"></a>Serializeelements

[CArray,](carray-class.md) [CList](clist-class.md)e [CMap](cmap-class.md) chamam essa função para serializar elementos.

```
template<class TYPE>
void AFXAPI SerializeElements(CArchive& ar, TYPE* pElements, INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos.

*ar*<br/>
Um objeto de arquivo para arquivar de ou para.

*pElementos*<br/>
Ponteiro para os elementos que estão sendo arquivados.

*Ncount*<br/>
Número de elementos arquivados

### <a name="remarks"></a>Comentários

A implementação padrão faz uma leitura ou gravação de forma bitais.

Para obter informações sobre a implementação desta e de outras funções auxiliares, consulte o artigo [Coleções: Como Fazer uma Coleção De Tipo Seguro](../how-to-make-a-type-safe-collection.md).

### <a name="example"></a>Exemplo

Veja o exemplo no artigo [Coleções: Como Fazer uma Coleção De Tipo Seguro](../how-to-make-a-type-safe-collection.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxtempl.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CMap](cmap-class.md)<br/>
[Classe CList](clist-class.md)<br/>
[Classe CArray](carray-class.md)
