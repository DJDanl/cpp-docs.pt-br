---
title: Classe CTypedPtrMap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CTypedPtrMap
- AFXTEMPL/CTypedPtrMap
- AFXTEMPL/CTypedPtrMap::GetNextAssoc
- AFXTEMPL/CTypedPtrMap::Lookup
- AFXTEMPL/CTypedPtrMap::RemoveKey
- AFXTEMPL/CTypedPtrMap::SetAt
dev_langs:
- C++
helpviewer_keywords:
- CTypedPtrMap [MFC], GetNextAssoc
- CTypedPtrMap [MFC], Lookup
- CTypedPtrMap [MFC], RemoveKey
- CTypedPtrMap [MFC], SetAt
ms.assetid: 9f377385-c6e9-4471-8b40-8fe220c50164
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 85f44473237a17a83aae2377e63a4e35d43483b9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433784"
---
# <a name="ctypedptrmap-class"></a>Classe CTypedPtrMap

Fornece um "wrapper" para objetos das classes de mapa de ponteiro de tipo seguro `CMapPtrToPtr`, `CMapPtrToWord`, `CMapWordToPtr`, e `CMapStringToPtr`.

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class KEY, class VALUE>
class CTypedPtrMap : public BASE_CLASS
```

#### <a name="parameters"></a>Parâmetros

*BASE_CLASS*<br/>
Classe base da classe map ponteiro tipado; deve ser uma classe de mapa de ponteiro ( `CMapPtrToPtr`, `CMapPtrToWord`, `CMapWordToPtr`, ou `CMapStringToPtr`).

*KEY*<br/>
Classe do objeto usado como a chave para o mapa.

*VALOR*<br/>
Classe do objeto armazenado no mapa.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento para a iteração.|
|[CTypedPtrMap::Lookup](#lookup)|Retorna um `KEY` com base em um `VALUE`.|
|[CTypedPtrMap::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[CTypedPtrMap::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente, se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[[CTypedPtrMap::operator]](#operator_at)|Insere um elemento do mapa.|

## <a name="remarks"></a>Comentários

Quando você usa `CTypedPtrMap`, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiro incompatíveis.

Porque todos os `CTypedPtrMap` funções são embutidos, uso deste modelo não afeta significativamente o tamanho ou velocidade do seu código.

Para obter mais informações sobre como usar `CTypedPtrMap`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base no modelo](../../mfc/template-based-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`CTypedPtrMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

##  <a name="getnextassoc"></a>  CTypedPtrMap::GetNextAssoc

Recupera o elemento de mapa na `rNextPosition`, em seguida, atualiza `rNextPosition` para referir-se para o próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rPosition,
    KEY& rKey,
    VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*rPosition*<br/>
Especifica uma referência a um valor de posição retornado por uma anterior `GetNextAssoc` ou `BASE_CLASS` **:: GetStartPosition** chamar.

*KEY*<br/>
Parâmetro de modelo especificando o tipo de chaves do mapa.

*rKey*<br/>
Especifica a chave retornada do elemento de dados recuperado.

*VALOR*<br/>
Parâmetro de modelo que especifica o tipo de valores do mapa.

*rValue*<br/>
Especifica o valor retornado do elemento de dados recuperado.

### <a name="remarks"></a>Comentários

Essa função é mais útil para iterar por meio de todos os elementos no mapa. Observe que a sequência de posição não é necessariamente o mesmo que a sequência de valor de chave.

Se o elemento recuperado é o último no mapa, em seguida, o novo valor de `rNextPosition` é definido como NULL.

Essa função embutida chama `BASE_CLASS` **:: GetNextAssoc**.

##  <a name="lookup"></a>  CTypedPtrMap::Lookup

`Lookup` usa um algoritmo de hash para localizar rapidamente o elemento do mapa com uma chave que corresponda exatamente.

```
BOOL Lookup(BASE_CLASS ::BASE_ARG_KEY key, VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*BASE_CLASS*<br/>
Parâmetro de modelo especificando a classe base da classe deste mapa.

*key*<br/>
A chave do elemento a ser pesquisado.

*VALOR*<br/>
Especifica o tipo de valores armazenados neste mapa de um parâmetro de modelo.

*rValue*<br/>
Especifica o valor retornado do elemento de dados recuperado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o elemento foi encontrado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função embutida chama `BASE_CLASS` **:: Lookup**.

##  <a name="operator_at"></a>  [CTypedPtrMap::operator]

Esse operador pode ser usado apenas no lado esquerdo de uma instrução de atribuição (um l-value).

```
VALUE& operator[ ](base_class ::base_arg_key key);
```

### <a name="parameters"></a>Parâmetros

*VALOR*<br/>
Especifica o tipo de valores armazenados neste mapa de um parâmetro de modelo.

*BASE_CLASS*<br/>
Parâmetro de modelo especificando a classe base da classe deste mapa.

*key*<br/>
A chave do elemento a ser pesquisado ou criado no mapa.

### <a name="remarks"></a>Comentários

Se não houver nenhum elemento do mapa com a chave especificada, um novo elemento é criado. Não há nenhum "direita" (r-Value) equivalente ao operador porque não há uma possibilidade de que uma chave não pode ser encontrada no mapa. Use o `Lookup` a função de membro para a recuperação do elemento.

##  <a name="removekey"></a>  CTypedPtrMap::RemoveKey

Essa função membro chama `BASE_CLASS` **:: RemoveKey**.

```
BOOL RemoveKey(KEY key);
```

### <a name="parameters"></a>Parâmetros

*KEY*<br/>
Parâmetro de modelo especificando o tipo de chaves do mapa.

*key*<br/>
A chave para o elemento a ser removido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a entrada tiver sido encontrada e removida com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey).

##  <a name="setat"></a>  CTypedPtrMap::SetAt

Essa função membro chama `BASE_CLASS` **:: SetAt**.

```
void SetAt(KEY key, VALUE newValue);
```

### <a name="parameters"></a>Parâmetros

*KEY*<br/>
Parâmetro de modelo especificando o tipo de chaves do mapa.

*key*<br/>
Especifica o valor da chave do novo valor.

*newValue*<br/>
Especifica o ponteiro de objeto que é o valor do novo elemento.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat).

## <a name="see-also"></a>Consulte também

[Exemplo MFC COLETAR](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)<br/>
[Classe CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)<br/>
[Classe CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)<br/>
[Classe CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)
