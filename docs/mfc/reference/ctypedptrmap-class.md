---
title: Classe CTypedPtrMap
ms.date: 11/04/2016
f1_keywords:
- CTypedPtrMap
- AFXTEMPL/CTypedPtrMap
- AFXTEMPL/CTypedPtrMap::GetNextAssoc
- AFXTEMPL/CTypedPtrMap::Lookup
- AFXTEMPL/CTypedPtrMap::RemoveKey
- AFXTEMPL/CTypedPtrMap::SetAt
helpviewer_keywords:
- CTypedPtrMap [MFC], GetNextAssoc
- CTypedPtrMap [MFC], Lookup
- CTypedPtrMap [MFC], RemoveKey
- CTypedPtrMap [MFC], SetAt
ms.assetid: 9f377385-c6e9-4471-8b40-8fe220c50164
ms.openlocfilehash: 41416c8223ac94364e8f83028ea93189e9f3f60c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373254"
---
# <a name="ctypedptrmap-class"></a>Classe CTypedPtrMap

Fornece um "invólucro" seguro para objetos `CMapPtrToPtr` `CMapPtrToWord`das `CMapWordToPtr`classes `CMapStringToPtr`do mapa de ponteiros, e .

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class KEY, class VALUE>
class CTypedPtrMap : public BASE_CLASS
```

#### <a name="parameters"></a>Parâmetros

*Base_class*<br/>
Classe base da classe de mapa de ponteiro digitado; deve ser uma classe `CMapPtrToPtr` `CMapPtrToWord`de `CMapWordToPtr`mapa `CMapStringToPtr`de ponteiros ( , , ou ).

*Chave*<br/>
Classe do objeto usado como chave para o mapa.

*Valor*<br/>
Classe do objeto armazenado no mapa.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrMap::GetNextAssoc](#getnextassoc)|Recebe o próximo elemento para iteração.|
|[CTypedPtrMap::Procurar](#lookup)|Retorna `KEY` um baseado `VALUE`em um .|
|[CTypedPtrMap::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[CTypedPtrMap::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrMap::operador \[\]](#operator_at)|Insere um elemento no mapa.|

## <a name="remarks"></a>Comentários

Quando você `CTypedPtrMap`usa, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiros incompatíveis.

Como `CTypedPtrMap` todas as funções são inline, o uso deste modelo não afeta significativamente o tamanho ou a velocidade do seu código.

Para obter mais `CTypedPtrMap`informações sobre o uso, consulte os artigos Coleções e Classes [Baseadas](../../mfc/collections.md) [em Modelos](../../mfc/template-based-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`CTypedPtrMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

## <a name="ctypedptrmapgetnextassoc"></a><a name="getnextassoc"></a>CTypedPtrMap::GetNextAssoc

Recupera o elemento `rNextPosition`mapa em `rNextPosition` , em seguida, atualiza-se para se referir ao próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rPosition,
    KEY& rKey,
    VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*Rposition*<br/>
Especifica uma referência a um valor DE `GetNextAssoc` `BASE_CLASS`POSIÇÃO retornado por uma chamada anterior ou **::GetStartPosition.**

*Chave*<br/>
Parâmetro de modelo especificando o tipo de chaves do mapa.

*Rkey*<br/>
Especifica a chave devolvida do elemento recuperado.

*Valor*<br/>
Parâmetro de modelo especificando o tipo de valores do mapa.

*Rvalue*<br/>
Especifica o valor retornado do elemento recuperado.

### <a name="remarks"></a>Comentários

Esta função é mais útil para iterar através de todos os elementos do mapa. Observe que a seqüência de posição não é necessariamente a mesma da seqüência de valor-chave.

Se o elemento recuperado for o último no mapa, então o novo valor de `rNextPosition` é definido como NULL.

Esta função inline `BASE_CLASS` **chama::GetNextAssoc**.

## <a name="ctypedptrmaplookup"></a><a name="lookup"></a>CTypedPtrMap::Procurar

`Lookup`usa um algoritmo de hashing para encontrar rapidamente o elemento do mapa com uma chave que corresponde exatamente.

```
BOOL Lookup(BASE_CLASS ::BASE_ARG_KEY key, VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*Base_class*<br/>
Parâmetro de modelo especificando a classe base da classe deste mapa.

*Chave*<br/>
A chave do elemento a ser olhado para cima.

*Valor*<br/>
Parâmetro de modelo especificando o tipo de valores armazenados neste mapa.

*Rvalue*<br/>
Especifica o valor retornado do elemento recuperado.

### <a name="return-value"></a>Valor retornado

Não zero se o elemento foi encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função inline `BASE_CLASS` **chama::Lookup**.

## <a name="ctypedptrmapoperator--"></a><a name="operator_at"></a>CTypedPtrMap::operador [ ]

Este operador só pode ser usado no lado esquerdo de uma declaração de atribuição (um valor l).

```
VALUE& operator[ ](base_class ::base_arg_key key);
```

### <a name="parameters"></a>Parâmetros

*Valor*<br/>
Parâmetro de modelo especificando o tipo de valores armazenados neste mapa.

*Base_class*<br/>
Parâmetro de modelo especificando a classe base da classe deste mapa.

*Chave*<br/>
A chave do elemento a ser olhado para cima ou criado no mapa.

### <a name="remarks"></a>Comentários

Se não houver nenhum elemento de mapa com a chave especificada, então um novo elemento será criado. Não há "lado direito" (valor r) equivalente a este operador porque existe a possibilidade de que uma chave não possa ser encontrada no mapa. Use `Lookup` a função membro para recuperação de elementos.

## <a name="ctypedptrmapremovekey"></a><a name="removekey"></a>CTypedPtrMap::RemoveKey

Esta função `BASE_CLASS`de membro chama **::RemoveKey**.

```
BOOL RemoveKey(KEY key);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Parâmetro de modelo especificando o tipo de chaves do mapa.

*Chave*<br/>
Chave para que o elemento seja removido.

### <a name="return-value"></a>Valor retornado

Não zero se a entrada foi encontrada e removida com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey).

## <a name="ctypedptrmapsetat"></a><a name="setat"></a>CTypedPtrMap::SetAt

Esta função `BASE_CLASS`de membro chama **::SetAt**.

```
void SetAt(KEY key, VALUE newValue);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Parâmetro de modelo especificando o tipo de chaves do mapa.

*Chave*<br/>
Especifica o valor-chave do newValue.

*newValue*<br/>
Especifica o ponteiro do objeto que é o valor do novo elemento.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat).

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)<br/>
[Classe CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)<br/>
[Classe CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)<br/>
[Classe CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)
