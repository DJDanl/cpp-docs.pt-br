---
title: Classe CMapStringToString
ms.date: 11/04/2016
f1_keywords:
- CMapStringToString
- AFXCOLL/CMapStringToString
- AFXCOLL/CMapStringToString::CPair
- AFXCOLL/CMapStringToString::CMapStringToString
- AFXCOLL/CMapStringToString::GetCount
- AFXCOLL/CMapStringToString::GetHashTableSize
- AFXCOLL/CMapStringToString::GetNextAssoc
- AFXCOLL/CMapStringToString::GetSize
- AFXCOLL/CMapStringToString::GetStartPosition
- AFXCOLL/CMapStringToString::HashKey
- AFXCOLL/CMapStringToString::InitHashTable
- AFXCOLL/CMapStringToString::IsEmpty
- AFXCOLL/CMapStringToString::Lookup
- AFXCOLL/CMapStringToString::LookupKey
- AFXCOLL/CMapStringToString::PGetFirstAssoc
- AFXCOLL/CMapStringToString::PGetNextAssoc
- AFXCOLL/CMapStringToString::PLookup
- AFXCOLL/CMapStringToString::RemoveAll
- AFXCOLL/CMapStringToString::RemoveKey
- AFXCOLL/CMapStringToString::SetAt
helpviewer_keywords:
- CMapStringToString [MFC], CPair
- CMapStringToString [MFC], CMapStringToString
- CMapStringToString [MFC], GetCount
- CMapStringToString [MFC], GetHashTableSize
- CMapStringToString [MFC], GetNextAssoc
- CMapStringToString [MFC], GetSize
- CMapStringToString [MFC], GetStartPosition
- CMapStringToString [MFC], HashKey
- CMapStringToString [MFC], InitHashTable
- CMapStringToString [MFC], IsEmpty
- CMapStringToString [MFC], Lookup
- CMapStringToString [MFC], LookupKey
- CMapStringToString [MFC], PGetFirstAssoc
- CMapStringToString [MFC], PGetNextAssoc
- CMapStringToString [MFC], PLookup
- CMapStringToString [MFC], RemoveAll
- CMapStringToString [MFC], RemoveKey
- CMapStringToString [MFC], SetAt
ms.assetid: b45794c2-fe6b-4edb-a8ca-faa03b57b4a8
ms.openlocfilehash: 544154569c50369b805ba296aa975849f245d4ad
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370125"
---
# <a name="cmapstringtostring-class"></a>Classe CMapStringToString

Suporta mapas `CString` de objetos `CString` chaveados por objetos.

## <a name="syntax"></a>Sintaxe

```
class CMapStringToString : public CObject
```

## <a name="members"></a>Membros

As funções `CMapStringToString` do membro são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Onde quer que `CObject` você veja um ponteiro como um parâmetro de função de retorno ou "saída", substitua um ponteiro para **char**. Onde quer que `CObject` você veja um ponteiro como um parâmetro de função de "entrada", substitua um ponteiro para **char**.

`BOOL CMapStringToString::Lookup(LPCTSTR<key>, CString&<rValue>) const;`

por exemplo, traduz para

`BOOL CMapStringToOb::Lookup(const char*<key>, CObject*&<rValue>) const;`

### <a name="public-structures"></a>Estruturas Públicas

|Nome|Descrição|
|----------|-----------------|
|[Cmapstringtostring::CPair](#cpair)|Uma estrutura aninhada contendo um valor-chave e o valor do objeto de string associado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cmapstringtostring::Cmapstringtostring](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Cmapstringtostring::GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToString::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela hash.|
|[CMapStringToString::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Recebe o próximo elemento para iteração.|
|[CMapStringToString::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|
|[Cmapstringtostring::getStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToString::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToString:InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela hash.|
|[cmapstringtostring::isEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapStringToString::'Procurar',](../../mfc/reference/cmapstringtoob-class.md#lookup)|Olha para um ponteiro vazio com base na tecla void pointer. O valor do ponteiro, não a entidade que ele aponta, é usado para a comparação de chaves.|
|[CMapStringToString::'LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência à chave associada ao valor-chave especificado.|
|[CMapStringToString::PGetFirstAssoc](#pgetfirstassoc)|Recebe um ponteiro `CString` para o primeiro no mapa.|
|[CMapStringToString::PGetNextAssoc](#pgetnextassoc)|Recebe um ponteiro `CString` para o próximo para iterar.|
|[CMapStringToString::PLookup](#plookup)|Retorna um ponteiro `CString` para um cujo valor corresponde ao valor especificado.|
|[CMapstringtostring::removeAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos deste mapa.|
|[CMapstringtostring::removekey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|
|[Cmapstringtostring::setat](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToString::operador \[\]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa `SetAt`— substituição do operador para .|

## <a name="remarks"></a>Comentários

A `CMapStringToString` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado, por sua vez, se um mapa **<<** for armazenado em `Serialize` um arquivo, seja com o operador de inserção sobrecarregada ( ) ou com a função de membro.

Se você precisar de `CString` -  `CString` um despejo de elementos individuais, você deve definir a profundidade do contexto de despejo para 1 ou maior.

Quando `CMapStringToString` um objeto é excluído ou quando seus `CString` elementos são removidos, os objetos são removidos conforme apropriado.

Para obter `CMapStringToString`mais informações, consulte o artigo [Coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMapStringToString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll.h

## <a name="cmapstringtostringcpair"></a><a name="cpair"></a>Cmapstringtostring::CPair

Contém um valor-chave e o valor do objeto de seqüência associado.

### <a name="remarks"></a>Comentários

Esta é uma estrutura aninhada dentro da classe [CMapStringToString](../../mfc/reference/cmapstringtostring-class.md).

A estrutura é composta por dois campos:

- `key`O valor real do tipo chave.

- `value`O valor do objeto associado.

Ele é usado para armazenar os valores de retorno de [CMapStringToString::PLookup,](#plookup) [CMapStringToString::PGetFirstAssoc](#pgetfirstassoc)e [CMapStringToString::PGetNextAssoc](#pgetnextassoc).

### <a name="example"></a>Exemplo

  Para um exemplo de uso, consulte o exemplo de [CMapStringToString::PLookup](#plookup).

## <a name="cmapstringtostringpgetfirstassoc"></a><a name="pgetfirstassoc"></a>CMapStringToString::PGetFirstAssoc

Retorna a primeira entrada do objeto do mapa.

```
const CPair* PGetFirstAssoc() const;

CPair* PGetFirstAssoc();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a primeira entrada no mapa; consulte [CMapStringToString::CPair](#cpair). Se o mapa estiver vazio, o valor será NULO.

### <a name="remarks"></a>Comentários

Chame esta função para retornar um ponteiro o primeiro elemento no objeto do mapa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#73](../../mfc/codesnippet/cpp/cmapstringtostring-class_1.cpp)]

## <a name="cmapstringtostringpgetnextassoc"></a><a name="pgetnextassoc"></a>CMapStringToString::PGetNextAssoc

Recupera o elemento mapa apontado por *pAssocRec*.

```
const CPair *PGetNextAssoc(const CPair* pAssoc) const;

CPair *PGetNextAssoc(const CPair* pAssoc);
```

### <a name="parameters"></a>Parâmetros

*pAssoc*<br/>
Aponta para uma entrada de mapa retornada por uma chamada [PGetNextAssoc](#pgetnextassoc) anterior ou [PGetFirstAssoc.](#pgetfirstassoc)

### <a name="return-value"></a>Valor retornado

Um ponteiro para a próxima entrada no mapa; consulte [CMapStringToString::CPair](#cpair). Se o elemento for o último no mapa, o valor é NULO.

### <a name="remarks"></a>Comentários

Chame este método para iterar através de todos os elementos do mapa. Recupere o primeiro elemento `PGetFirstAssoc` com uma chamada e, em `PGetNextAssoc`seguida, iterar através do mapa com chamadas sucessivas para .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMapStringToString::PGetFirstAssoc](#pgetfirstassoc).

## <a name="cmapstringtostringplookup"></a><a name="plookup"></a>CMapStringToString::PLookup

Olha o valor mapeado para uma determinada chave.

```
const CPair* PLookup(LPCTSTR key) const;

CPair* PLookup(LPCTSTR key);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Um ponteiro para a chave para o elemento a ser pesquisado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a tecla especificada.

### <a name="remarks"></a>Comentários

Chame este método para procurar um elemento de mapa com uma chave que corresponda exatamente à chave dada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#74](../../mfc/codesnippet/cpp/cmapstringtostring-class_2.cpp)]

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
