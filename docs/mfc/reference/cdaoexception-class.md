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
ms.openlocfilehash: a8a789f4dba06ffe376d8a8e955b026bb23af924
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369009"
---
# <a name="cdaoexception-class"></a>Classe CDaoException

Representa uma condição de exceção decorrente das classes de banco de dados MFC com base em objetos de acesso a dados (DAO). DAO 3.6 é a versão final, e é considerada obsoleta.

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
|[CDaoException::GetErrorInfo](#geterrorinfo)|Retorna informações de erro sobre um objeto de erro específico na coleção Erros.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoException::m_nAfxDaoError](#m_nafxdaoerror)|Contém um código de erro estendido para qualquer erro nas classes DAO do MFC.|
|[CDaoException::m_pErrorInfo](#m_perrorinfo)|Um ponteiro para um objeto [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) que contém informações sobre um objeto de erro DAO.|
|[CDaoException::m_scode](#m_scode)|O valor [SCODE](#m_scode) associado ao erro.|

## <a name="remarks"></a>Comentários

A classe inclui membros de dados públicos que você pode usar para determinar a causa da exceção. `CDaoException`objetos são construídos e jogados pelas funções dos membros das classes de banco de dados DAO.

> [!NOTE]
> As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados oDBC com as classes DAO. Em geral, as classes de MFC baseadas em DAO são mais capazes do que as classes MFC baseadas no ODBC; as classes baseadas em DAO podem acessar dados, inclusive através de drivers ODBC, através de seu próprio mecanismo de banco de dados. As classes baseadas em DAO também suportam operações DDL (Data Definition Language, linguagem de definição de dados), como adicionar tabelas através das classes, sem ter que ligar diretamente para dao. Para obter informações sobre exceções lançadas pelas classes ODBC, consulte [CDBException](../../mfc/reference/cdbexception-class.md).

Você pode acessar objetos de exceção no escopo de uma expressão [CATCH.](../../mfc/reference/exception-processing.md#catch) Você também `CDaoException` pode jogar objetos do seu próprio código com a função global [AfxThrowDaoException.](../../mfc/reference/exception-processing.md#afxthrowdaoexception)

No MFC, todos os erros de DAO `CDaoException`são expressos como exceções, do tipo . Quando você captura uma exceção desse `CDaoException` tipo, você pode usar funções de membro para recuperar informações de quaisquer objetos de erro DAO armazenados na coleção de erros do mecanismo de banco de dados. À medida que cada erro ocorre, um ou mais objetos de erro são colocados na coleção Erros. (Normalmente, a coleção contém apenas um objeto de erro; se você estiver usando uma fonte de dados ODBC, é mais provável que obtenha vários objetos de erro.) Quando outra operação DAO gera um erro, a coleta de erros é limpa e o novo objeto de erro é colocado na coleção Erros. As operações de DAO que não geram um erro não têm efeito na coleta de erros.

Para obter códigos de erro DAO, consulte o arquivo DAOERR. H. Para obter informações relacionadas, consulte o tópico "Erros de acesso a dados trappable" na Ajuda da DAO.

Para obter mais informações sobre o `CDaoException` tratamento de exceções em geral ou sobre objetos, consulte os artigos [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md) e [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md). O segundo artigo contém código de exemplo que ilustra o tratamento de exceções no DAO.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`CDaoException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaoexceptioncdaoexception"></a><a name="cdaoexception"></a>CDaoException::CDaoException

Constrói um objeto `CDaoException`.

```
CDaoException();
```

### <a name="remarks"></a>Comentários

Normalmente, a estrutura cria objetos de exceção quando seu código lança uma exceção. Você raramente precisa construir um objeto de exceção explicitamente. Se você quiser `CDaoException` jogar um de seu próprio código, chame a função global [AfxThrowDaoException](../../mfc/reference/exception-processing.md#afxthrowdaoexception).

No entanto, você pode querer criar explicitamente um objeto de exceção se estiver fazendo chamadas diretas para dao através dos ponteiros de interface DAO que as classes MFC encapsulam. Nesse caso, você pode precisar recuperar informações de erro do DAO. Suponha que ocorra um erro no DAO quando você chama um método DAO através da interface DAODatabases para a coleção de bancos de dados de um espaço de trabalho.

##### <a name="to-retrieve-the-dao-error-information"></a>Para recuperar as informações de erro do DAO

1. Construa `CDaoException` um objeto.

1. Ligue para a função de membro [GetErrorCount](#geterrorcount) do objeto de exceção para determinar quantos objetos de erro estão na coleção de erros do mecanismo de banco de dados. (Normalmente apenas um, a menos que você esteja usando uma fonte de dados ODBC.)

1. Chame a função de membro [GetErrorInfo](#geterrorinfo) do objeto de exceção para recuperar um objeto de erro específico por vez, por índice na coleção, através do objeto de exceção. Pense no objeto de exceção como um proxy para um objeto de erro DAO.

1. Examine a estrutura [cdaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) atual que `GetErrorInfo` retorna no membro de dados [m_pErrorInfo.](#m_perrorinfo) Seus membros fornecem informações sobre o erro da DAO.

1. No caso de uma fonte de dados ODBC, repita as etapas 3 e 4 conforme necessário, para obter mais objetos de erro.

1. Se você construiu o objeto de exceção no heap, exclua-o com o operador **de exclusão** quando terminar.

Para obter mais informações sobre erros de manuseio nas classes DAO do MFC, consulte o artigo [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).

## <a name="cdaoexceptiongeterrorcount"></a><a name="geterrorcount"></a>CDaoException::GetErrorCount

Ligue para esta função de membro para recuperar o número de objetos de erro DAO na coleção de erros do mecanismo de banco de dados.

```
short GetErrorCount();
```

### <a name="return-value"></a>Valor retornado

O número de objetos de erro DAO na coleção erros do mecanismo de banco de dados.

### <a name="remarks"></a>Comentários

Essas informações são úteis para looping através da coleção Erros para recuperar cada um ou mais objetos de erro DAO na coleção. Para recuperar um objeto de erro por índice ou por número de erro DAO, ligue para a função [membro GetErrorInfo.](#geterrorinfo)

> [!NOTE]
> Normalmente, há apenas um objeto de erro na coleção Erros. Se você está trabalhando com uma fonte de dados ODBC, no entanto, pode haver mais de um.

## <a name="cdaoexceptiongeterrorinfo"></a><a name="geterrorinfo"></a>CDaoException::GetErrorInfo

Retorna informações de erro sobre um objeto de erro específico na coleção Erros.

```
void GetErrorInfo(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice das informações de erro na coleta de erros do mecanismo de banco de dados, para busca por índice.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para obter os seguintes tipos de informações sobre a exceção:

- Código do erro

- Fonte

- Descrição

- Arquivo de ajuda

- Contexto de ajuda

`GetErrorInfo`armazena as informações no membro `m_pErrorInfo` de dados do objeto de exceção. Para obter uma breve descrição das informações devolvidas, consulte [m_pErrorInfo](#m_perrorinfo). Se você pegar uma `CDaoException` exceção do `m_pErrorInfo` tipo lançado pelo MFC, o membro já será preenchido. Se você optar por chamar dao diretamente, você `GetErrorInfo` deve chamar `m_pErrorInfo`a função de membro do objeto de exceção para preencher . Para obter uma descrição mais detalhada, consulte a estrutura [CDaoErrorInfo.](../../mfc/reference/cdaoerrorinfo-structure.md)

Para obter informações sobre exceções de DAO e código de exemplo, consulte o artigo [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).

## <a name="cdaoexceptionm_nafxdaoerror"></a><a name="m_nafxdaoerror"></a>CDaoException::m_nAfxDaoError

Contém um código de erro estendido MFC.

### <a name="remarks"></a>Comentários

Este código é fornecido nos casos em que um componente específico das classes DAO do MFC errou.

Os valores possíveis são:

- NO_AFX_DAO_ERROR A operação mais recente não resultou em um erro estendido do MFC. No entanto, a operação pode ter produzido outros erros do DAO ou o OLE, por isso você deve verificar [m_pErrorInfo](#m_perrorinfo) e possivelmente [m_scode](#m_scode).

- AFX_DAO_ERROR_ENGINE_INITIALIZATION MFC não conseguiu inicializar o mecanismo de banco de dados microsoft jet. OLE pode ter falhado na inicialização, ou pode ter sido impossível criar uma instância do objeto do mecanismo de banco de dados DAO. Esses problemas geralmente sugerem uma instalação ruim de DAO ou OLE.

- AFX_DAO_ERROR_DFX_BIND Um endereço usado em uma chamada de função DFX (Record Record Exchange, troca de campo de registro da DAO) não existe ou é inválido (o endereço não foi usado para vincular dados). Você pode ter passado um endereço ruim em uma chamada DFX, ou o endereço pode ter se tornado inválido entre as operações de DFX.

- AFX_DAO_ERROR_OBJECT_NOT_OPEN Você tentou abrir um conjunto de registros com base em um querydef ou um objeto tabledef que não estava em estado aberto.

## <a name="cdaoexceptionm_perrorinfo"></a><a name="m_perrorinfo"></a>CDaoException::m_pErrorInfo

Contém um ponteiro `CDaoErrorInfo` para uma estrutura que fornece informações sobre o objeto de erro DAO que você recuperou pela última vez chamando [GetErrorInfo](#geterrorinfo).

### <a name="remarks"></a>Comentários

Este objeto contém as seguintes informações:

|Membro do CDaoErrorInfo|Informações|Significado|
|--------------------------|-----------------|-------------|
|`m_lErrorCode`|Código do Erro|O código de erro DAO|
|`m_strSource`|Fonte|O nome do objeto ou aplicativo que originalmente gerou o erro|
|`m_strDescription`|Descrição|Uma seqüência descritiva associada ao erro|
|`m_strHelpFile`|Arquivo de ajuda|Um caminho para um arquivo de ajuda do Windows no qual o usuário pode obter informações sobre o problema|
|`m_lHelpContext`|Contexto de ajuda|O ID de contexto para um tópico no arquivo DAO Help|

Para obter detalhes completos `CDaoErrorInfo` sobre as informações contidas no objeto, consulte a estrutura [CDaoErrorInfo.](../../mfc/reference/cdaoerrorinfo-structure.md)

## <a name="cdaoexceptionm_scode"></a><a name="m_scode"></a>CDaoException::m_scode

Contém um valor `SCODE` de tipo que descreve o erro.

### <a name="remarks"></a>Comentários

Este é um código OLE. Você raramente precisará usar esse valor porque, em quase todos os casos, informações de `CDaoException` erro mfc ou DAO mais específicas estão disponíveis nos outros membros de dados.

Para obter informações sobre o SCODE, consulte a [estrutura de tópicos de códigos de erro OLE](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows. O tipo de dados SCODE mapeia para o tipo de dados HRESULT.

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
