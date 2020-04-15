---
title: Classe CFixedStringT
ms.date: 03/27/2019
f1_keywords:
- CFixedStringT
- CSTRINGT/ATL::CFixedStringT
- CSTRINGT/ATL::CFixedStringT::CFixedStringT
helpviewer_keywords:
- CFixedStringT class
- shared classes, CFixedStringT
ms.assetid: 6d4171ba-3104-493a-a6cc-d515f4ba9a4b
ms.openlocfilehash: fe096185f6f0b71ad45757cd0b75ab13c41e5f5b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317821"
---
# <a name="cfixedstringt-class"></a>Classe CFixedStringT

Esta classe representa um objeto de seqüência com um buffer de caractere fixo.

## <a name="syntax"></a>Sintaxe

```
template<class StringType, int t_nChars>
class CFixedStringT : private CFixedStringMgr, public StringType
```

#### <a name="parameters"></a>Parâmetros

*Stringtype*<br/>
Usado como a classe base para o `CStringT`objeto de string fixo e pode ser qualquer tipo baseado. Alguns exemplos `CString` `CStringA`incluem `CStringW`, e .

*T_nchars*<br/>
O número de caracteres armazenados no buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[stringt cfixo::CFixedstringT](#cfixedstringt)|O construtor do objeto de corda.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFixedStringT::operador =](#operator_eq)|Atribui um novo valor `CFixedStringT` a um objeto.|

## <a name="remarks"></a>Comentários

Esta classe é um exemplo de `CStringT`uma classe de strings personalizada baseada em . Embora semelhantes, as duas classes diferem na implementação. As principais `CFixedStringT` `CStringT` diferenças entre e são:

- O buffer de caractereinicial é alocado como parte do objeto e tem tamanho *t_nChars*. Isso permite `CFixedString` que o objeto ocupe um pedaço de memória contíguo para fins de desempenho. No entanto, se `CFixedStringT` o conteúdo de um objeto crescer além *de t_nChars,* o buffer será alocado dinamicamente.

- O buffer de `CFixedStringT` caracteres para um objeto tem sempre o mesmo comprimento *(t_nChars).* Não há limitação no `CStringT` tamanho do buffer para objetos.

- O gerenciador `CFixedStringT` de memória é personalizado de tal forma que `CFixedStringT` o compartilhamento de um objeto [CStringData](../../atl-mfc-shared/reference/cstringdata-class.md) entre dois ou mais objetos não é permitido. `CStringT`objetos não têm essa limitação.

Para obter mais informações `CFixedStringT` sobre a personalização e o gerenciamento de memória para objetos de seqüência em geral, consulte [Memory Management e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlStringMgr`

`StringType`

`CFixedStringMgr`

`CFixedStringT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** cstringt.h

## <a name="cfixedstringtcfixedstringt"></a><a name="cfixedstringt"></a>stringt cfixo::CFixedstringT

Constrói um objeto `CFixedStringT`.

```
CFixedStringT() throw();
explicit CFixedStringT(IAtlStringMgr* pStringMgr) throw();
CFixedStringT(const CFixedStringT<StringType, t_nChars>& strSrc);
CFixedStringT(const StringType& strSrc);
CFixedStringT(const StringType::XCHAR* pszSrc);
explicit CFixedStringT(const StringType::YCHAR* pszSrc);
explicit CFixedStringT(const unsigned char* pszSrc);
```

### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Uma seqüência de terminadas nula a ser copiada para este `CFixedStringT` objeto.

*strSrc*<br/>
Um objeto `CFixedStringT` existente a ser `CFixedStringT` copiado para este objeto.

*pStringMgr*<br/>
Um ponteiro para o `CFixedStringT` gerenciador de memória do objeto. Para obter `IAtlStringMgr` mais informações `CFixedStringT`sobre o gerenciamento de memória e memória para , consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

### <a name="remarks"></a>Comentários

Como os construtores copiam os dados de entrada em um novo armazenamento alocado, você deve estar ciente de que exceções de memória podem resultar. Alguns desses construtores atuam como funções de conversão.

## <a name="cfixedstringtoperator-"></a><a name="operator_eq"></a>CFixedStringT::operador =

Reinicializa um objeto `CFixedStringT` existente com novos dados.

```
CFixedStringT<StringType, t_nChars>& operator=(
    const CFixedStringT<StringType, t_nChars>& strSrc);
CFixedStringT<StringType, t_nChars>& operator=(const char* pszSrc);
CFixedStringT<StringType, t_nChars>& operator=(const wchar_t* pszSrc);
CFixedStringT<StringType, t_nChars>& operator=(const unsigned char* pszSrc);
CFixedStringT<StringType, t_nChars>& operator=(const StringType& strSrc);
```

### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Uma seqüência de terminadas nula a ser copiada para este `CFixedStringT` objeto.

*strSrc*<br/>
Um existente `CFixedStringT` a ser copiado para este `CFixedStringT` objeto.

### <a name="remarks"></a>Comentários

Você deve estar ciente de que exceções de memória podem ocorrer sempre que você `CFixedStringT` usar o operador de atribuição, porque o novo armazenamento é frequentemente alocado para segurar o objeto resultante.

## <a name="see-also"></a>Confira também

[Classe Cstringt](../../atl-mfc-shared/reference/cstringt-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
