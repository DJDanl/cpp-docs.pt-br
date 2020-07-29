---
title: Classe CDaoException
ms.date: 09/17/2019
f1_keywords:
- CDaoException
- AFXDAO/CDaoException
- AFXDAO/CDaoException::CDaoException
- AFXDAO/CDaoException::GetErrorCount
- AFXDAO/CDaoException::GetErrorInfo
- AFXDAO/CDaoException::m_nAfxDaoError
- AFXDAO/CDaoException::m_pErrorInfo
- AFXDAO/CDaoException::m_scode
helpviewer_keywords:
- CDaoException [MFC], CDaoException
- CDaoException [MFC], GetErrorCount
- CDaoException [MFC], GetErrorInfo
- CDaoException [MFC], m_nAfxDaoError
- CDaoException [MFC], m_pErrorInfo
- CDaoException [MFC], m_scode
ms.assetid: b2b01fa9-7ce2-42a1-842e-40f13dc50da4
ms.openlocfilehash: fcbd88e8a9ef632b61096ac2577d7a1a7094d4b5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231839"
---
# <a name="cdaoexception-class"></a>Classe CDaoException

Representa uma condição de exceção resultante das classes de banco de dados MFC baseadas em DAO (Data Access Objects). O DAO 3,6 é a versão final e é considerado obsoleto.

## <a name="syntax"></a>Sintaxe

```
class CDaoException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoException::CDaoException](#cdaoexception)|Constrói um objeto `CDaoException`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoException::GetErrorCount](#geterrorcount)|Retorna o número de erros na coleção de erros do mecanismo de banco de dados.|
|[CDaoException:: GetErrorInfo](#geterrorinfo)|Retorna informações de erro sobre um objeto de erro específico na coleção de erros.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoException:: m_nAfxDaoError](#m_nafxdaoerror)|Contém um código de erro estendido para qualquer erro nas classes do MFC DAO.|
|[CDaoException:: m_pErrorInfo](#m_perrorinfo)|Um ponteiro para um objeto [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) que contém informações sobre um objeto de erro DAO.|
|[CDaoException:: m_scode](#m_scode)|O valor de [SCODE](#m_scode) associado ao erro.|

## <a name="remarks"></a>Comentários

A classe inclui membros de dados públicos que você pode usar para determinar a causa da exceção. `CDaoException`os objetos são construídos e lançados por funções de membro das classes de banco de dados DAO.

> [!NOTE]
> As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC baseadas no DAO são mais compatíveis do que as classes do MFC baseadas no ODBC; as classes baseadas em DAO podem acessar dados, incluindo por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. As classes baseadas em DAO também oferecem suporte a operações DDL (linguagem de definição de dados), como a adição de tabelas por meio de classes, sem a necessidade de chamar o DAO diretamente. Para obter informações sobre exceções geradas pelas classes ODBC, consulte [CDBException](../../mfc/reference/cdbexception-class.md).

Você pode acessar objetos de exceção dentro do escopo de uma expressão [Catch](../../mfc/reference/exception-processing.md#catch) . Você também pode lançar `CDaoException` objetos de seu próprio código com a função global [AfxThrowDaoException](../../mfc/reference/exception-processing.md#afxthrowdaoexception) .

No MFC, todos os erros DAO são expressos como exceções, do tipo `CDaoException` . Ao capturar uma exceção desse tipo, você pode usar funções de `CDaoException` membro para recuperar informações de quaisquer objetos de erro do DAO armazenados na coleção de erros do mecanismo de banco de dados. Como ocorre cada erro, um ou mais objetos de erro são colocados na coleção de erros. (Normalmente, a coleção contém apenas um objeto de erro; se você estiver usando uma fonte de dados ODBC, será mais provável que você obtenha vários objetos de erro.) Quando outra operação DAO gera um erro, a coleção de erros é desmarcada e o novo objeto de erro é colocado na coleção de erros. As operações DAO que não geram um erro não têm nenhum efeito na coleção de erros.

Para códigos de erro do DAO, consulte o arquivo DAOERR. T. Para obter informações relacionadas, consulte o tópico "erros de acesso a dados interceptáveis" na ajuda do DAO.

Para obter mais informações sobre manipulação de exceção em geral ou sobre `CDaoException` objetos, consulte os artigos tratamento de exceções [(MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md). O segundo artigo contém um código de exemplo que ilustra o tratamento de exceção no DAO.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CDaoException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="cdaoexceptioncdaoexception"></a><a name="cdaoexception"></a>CDaoException::CDaoException

Constrói um objeto `CDaoException`.

```
CDaoException();
```

### <a name="remarks"></a>Comentários

Normalmente, a estrutura cria objetos de exceção quando seu código gera uma exceção. Raramente você precisa construir um objeto de exceção explicitamente. Se você quiser lançar um `CDaoException` de seu próprio código, chame a função global [AfxThrowDaoException](../../mfc/reference/exception-processing.md#afxthrowdaoexception).

No entanto, talvez você queira criar explicitamente um objeto de exceção se estiver fazendo chamadas diretas para o DAO por meio dos ponteiros de interface DAO que o MFC classes encapsular. Nesse caso, talvez seja necessário recuperar informações de erro do DAO. Suponha que ocorra um erro no DAO quando você chamar um método DAO por meio da interface DAODatabases para a coleção de bancos de dados de um espaço de trabalho.

##### <a name="to-retrieve-the-dao-error-information"></a>Para recuperar as informações de erro do DAO

1. Construa um `CDaoException` objeto.

1. Chame a função de membro [GetErrorCount](#geterrorcount) do objeto de exceção para determinar quantos objetos de erro estão na coleção de erros do mecanismo de banco de dados. (Normalmente, apenas uma, a menos que você esteja usando uma fonte de dados ODBC.)

1. Chame a função de membro [GetErrorInfo](#geterrorinfo) do objeto de exceção para recuperar um objeto de erro específico por vez, por índice na coleção, por meio do objeto de exceção. Considere o objeto de exceção como um proxy para um objeto de erro DAO.

1. Examine a estrutura [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) atual que `GetErrorInfo` retorna no membro de dados [m_pErrorInfo](#m_perrorinfo) . Seus membros fornecem informações sobre o erro do DAO.

1. No caso de uma fonte de dados ODBC, repita as etapas 3 e 4, conforme necessário, para obter mais objetos de erro.

1. Se você tiver construído o objeto de exceção no heap, exclua-o com o **`delete`** operador quando terminar.

Para obter mais informações sobre como lidar com erros nas classes do MFC DAO, consulte o artigo [Exceptions: Database Exceptions](../../mfc/exceptions-database-exceptions.md).

## <a name="cdaoexceptiongeterrorcount"></a><a name="geterrorcount"></a>CDaoException::GetErrorCount

Chame essa função de membro para recuperar o número de objetos de erro do DAO na coleção de erros do mecanismo de banco de dados.

```
short GetErrorCount();
```

### <a name="return-value"></a>Valor retornado

O número de objetos de erro do DAO na coleção de erros do mecanismo de banco de dados.

### <a name="remarks"></a>Comentários

Essas informações são úteis para executar um loop pela coleção de erros para recuperar cada um ou mais objetos de erro do DAO na coleção. Para recuperar um objeto de erro por índice ou por número de erro DAO, chame a função de membro [GetErrorInfo](#geterrorinfo) .

> [!NOTE]
> Normalmente, há apenas um objeto de erro na coleção de erros. No entanto, se você estiver trabalhando com uma fonte de dados ODBC, pode haver mais de um.

## <a name="cdaoexceptiongeterrorinfo"></a><a name="geterrorinfo"></a>CDaoException:: GetErrorInfo

Retorna informações de erro sobre um objeto de erro específico na coleção de erros.

```cpp
void GetErrorInfo(int nIndex);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice das informações de erro na coleção de erros do mecanismo de banco de dados, para pesquisa por índice.

### <a name="remarks"></a>Comentários

Chame essa função de membro para obter os seguintes tipos de informações sobre a exceção:

- Código do erro

- Fonte

- Descrição

- Arquivo de ajuda

- Contexto de ajuda

`GetErrorInfo`armazena as informações no membro de dados do objeto de exceção `m_pErrorInfo` . Para obter uma breve descrição das informações retornadas, consulte [m_pErrorInfo](#m_perrorinfo). Se você capturar uma exceção do tipo `CDaoException` lançado pelo MFC, o `m_pErrorInfo` membro já estará preenchido. Se você optar por chamar o DAO diretamente, deverá chamar a função de membro do objeto de exceção `GetErrorInfo` para preencher `m_pErrorInfo` . Para obter uma descrição mais detalhada, consulte a estrutura [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) .

Para obter informações sobre exceções do DAO e código de exemplo, consulte o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).

## <a name="cdaoexceptionm_nafxdaoerror"></a><a name="m_nafxdaoerror"></a>CDaoException:: m_nAfxDaoError

Contém um código de erro estendido do MFC.

### <a name="remarks"></a>Comentários

Esse código é fornecido nos casos em que um componente específico das classes do MFC DAO tem erramos.

Os valores possíveis são:

- NO_AFX_DAO_ERROR a operação mais recente não resultou em um erro estendido do MFC. No entanto, a operação pode ter produzido outros erros do DAO ou OLE, portanto, você deve verificar [m_pErrorInfo](#m_perrorinfo) e possivelmente [m_scode](#m_scode).

- AFX_DAO_ERROR_ENGINE_INITIALIZATION MFC não pôde inicializar o mecanismo de banco de dados do Microsoft Jet. O OLE pode ter falhado ao inicializar ou pode ter sido impossível criar uma instância do objeto do mecanismo de banco de dados DAO. Esses problemas geralmente sugerem uma instalação inadequada do DAO ou OLE.

- AFX_DAO_ERROR_DFX_BIND um endereço usado em uma chamada de função Exchange (DFX) de campo de registro DAO não existe ou é inválido (o endereço não foi usado para ligar dados). Você pode ter passado um endereço incorreto em uma chamada DFX ou o endereço pode ter se tornado inválido entre as operações DFX.

- AFX_DAO_ERROR_OBJECT_NOT_OPEN Você tentou abrir um conjunto de registros com base em um QueryDef ou um objeto tabledef que não estava em um estado aberto.

## <a name="cdaoexceptionm_perrorinfo"></a><a name="m_perrorinfo"></a>CDaoException:: m_pErrorInfo

Contém um ponteiro para uma `CDaoErrorInfo` estrutura que fornece informações sobre o objeto de erro DAO que você recuperou pela última vez chamando [GetErrorInfo](#geterrorinfo).

### <a name="remarks"></a>Comentários

Esse objeto contém as seguintes informações:

|Membro CDaoErrorInfo|Informações|Significado|
|--------------------------|-----------------|-------------|
|`m_lErrorCode`|Código do Erro|O código de erro do DAO|
|`m_strSource`|Fonte|O nome do objeto ou aplicativo que originalmente gerou o erro|
|`m_strDescription`|Descrição|Uma cadeia de caracteres descritiva associada ao erro|
|`m_strHelpFile`|Arquivo de ajuda|Um caminho para um arquivo de ajuda do Windows no qual o usuário pode obter informações sobre o problema|
|`m_lHelpContext`|Contexto de ajuda|A ID de contexto para um tópico no arquivo de ajuda do DAO|

Para obter detalhes completos sobre as informações contidas no `CDaoErrorInfo` objeto, consulte a estrutura [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) .

## <a name="cdaoexceptionm_scode"></a><a name="m_scode"></a>CDaoException:: m_scode

Contém um valor do tipo `SCODE` que descreve o erro.

### <a name="remarks"></a>Comentários

Este é um código OLE. Você raramente precisará usar esse valor porque, em quase todos os casos, informações de erro do MFC ou do DAO mais específicas estão disponíveis nos outros `CDaoException` membros de dados.

Para obter informações sobre SCODE, consulte a [estrutura de tópicos de códigos de erro OLE](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows. O tipo de dados SCODE é mapeado para o tipo de dados HRESULT.

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
