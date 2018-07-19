---
title: Classe CDaoException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoException
- AFXDAO/CDaoException
- AFXDAO/CDaoException::CDaoException
- AFXDAO/CDaoException::GetErrorCount
- AFXDAO/CDaoException::GetErrorInfo
- AFXDAO/CDaoException::m_nAfxDaoError
- AFXDAO/CDaoException::m_pErrorInfo
- AFXDAO/CDaoException::m_scode
dev_langs:
- C++
helpviewer_keywords:
- CDaoException [MFC], CDaoException
- CDaoException [MFC], GetErrorCount
- CDaoException [MFC], GetErrorInfo
- CDaoException [MFC], m_nAfxDaoError
- CDaoException [MFC], m_pErrorInfo
- CDaoException [MFC], m_scode
ms.assetid: b2b01fa9-7ce2-42a1-842e-40f13dc50da4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fbcabd0659e98d25cbe28ce233b89dccc3585d61
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37336180"
---
# <a name="cdaoexception-class"></a>Classe CDaoException
Representa uma condição de exceção decorrente das classes de banco de dados MFC com base em objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDaoException : public CException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoException::CDaoException](#cdaoexception)|Constrói um objeto `CDaoException`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoException::GetErrorCount](#geterrorcount)|Retorna o número de erros na coleção de erros do mecanismo de banco de dados.|  
|[CDaoException::GetErrorInfo](#geterrorinfo)|Retorna informações de erro sobre um objeto de erro específico na coleção de erros.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoException::m_nAfxDaoError](#m_nafxdaoerror)|Contém um código de erro estendidas para qualquer erro nas classes DAO MFC.|  
|[CDaoException::m_pErrorInfo](#m_perrorinfo)|Um ponteiro para um [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) objeto que contém informações sobre um objeto de erro do DAO.|  
|[CDaoException::m_scode](#m_scode)|O [SCODE](#m_scode) valor associado com o erro.|  
  
## <a name="remarks"></a>Comentários  
 A classe inclui os membros de dados públicos, que você pode usar para determinar a causa da exceção. `CDaoException` objetos são construídos e gerados pelas funções de membro das classes de banco de dados DAO.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC com base em DAO são mais capacitadas que as classes do MFC com base em ODBC; as classes com base em DAO podem acessar dados, incluindo por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. As classes com base em DAO também dão suporte a operações de linguagem de definição de dados (DDL), como adicionar tabelas por meio de classes, sem a necessidade de chamar diretamente o DAO. Para obter informações sobre as exceções geradas pelas classes de ODBC, consulte [CDBException](../../mfc/reference/cdbexception-class.md).  
  
 Você pode acessar objetos de exceção dentro do escopo de um [CATCH](../../mfc/reference/exception-processing.md#catch) expressão. Você também pode lançar `CDaoException` objetos do seu próprio código com o [AfxThrowDaoException](../../mfc/reference/exception-processing.md#afxthrowdaoexception) função global.  
  
 No MFC, todos os erros DAO são expressos como exceções, do tipo `CDaoException`. Quando você capturar uma exceção desse tipo, você pode usar `CDaoException` funções de membro para recuperar informações de quaisquer objetos de erro DAO armazenados na coleção de erros do mecanismo de banco de dados. Ocorre a cada erro, um ou mais objetos de erro são colocados na coleção de erros. (Normalmente a coleção contém apenas um objeto de erro; se você estiver usando uma fonte de dados ODBC, você provavelmente mais obter vários objetos de erro). Quando outra operação DAO gera um erro, a coleção de erros está desmarcada e o novo objeto de erro é colocado na coleção de erros. Operações de DAO que não geram um erro não têm efeito sobre a coleção de erros.  
  
 Para códigos de erro do DAO, consulte o arquivo DAOERR. H. Para obter informações relacionadas, consulte o tópico "Dados acesso erros interceptáveis" na Ajuda do DAO.  
  
 Para obter mais informações sobre o tratamento de exceção no geral, ou cerca `CDaoException` objetos, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md). O segundo artigo contém código de exemplo que ilustra o tratamento de exceções em DAO.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CDaoException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="cdaoexception"></a>  CDaoException::CDaoException  
 Constrói um objeto `CDaoException`.  
  
```  
CDaoException();
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, a estrutura cria objetos de exceção quando seu código gera uma exceção. Você raramente precisa construir um objeto de exceção explicitamente. Se você quiser lançar uma `CDaoException` de seu próprio código, chame a função global [AfxThrowDaoException](../../mfc/reference/exception-processing.md#afxthrowdaoexception).  
  
 No entanto, você talvez queira criar explicitamente um objeto de exceção, se você estiver fazendo chamadas diretas para DAO por meio de ponteiros de interface do DAO que encapsulam as classes do MFC. Nesse caso, talvez você precise recuperar informações de erro do DAO. Suponha que um erro ocorre em DAO quando você chama um método DAO por meio da interface DAODatabases à coleção de bancos de dados do espaço de trabalho.  
  
##### <a name="to-retrieve-the-dao-error-information"></a>Para recuperar as informações de erro do DAO  
  
1.  Construir um `CDaoException` objeto.  
  
2.  Chamar o objeto de exceção [GetErrorCount](#geterrorcount) a função de membro para determinar quantos objetos de erro estão na coleção de erros do mecanismo de banco de dados. (Normalmente apenas uma, a menos que você estiver usando uma fonte de dados ODBC.)  
  
3.  Chamar o objeto de exceção [GetErrorInfo](#geterrorinfo) a função de membro para recuperar um objeto de erro específico ao mesmo tempo, por índice na coleção, através do objeto de exceção. Considere o objeto de exceção como um proxy para um objeto de erro do DAO.  
  
4.  Examinar o atual [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) estrutura que `GetErrorInfo` retorna o [m_pErrorInfo](#m_perrorinfo) membro de dados. Seus membros fornecem informações sobre o erro DAO.  
  
5.  No caso de uma fonte de dados ODBC, repita as etapas 3 e 4 conforme necessário, para obter mais objetos de erro.  
  
6.  Se você construiu o objeto de exceção no heap, excluí-la com o **excluir** operador quando terminar.  
  
 Para obter mais informações sobre como lidar com erros nas classes DAO MFC, consulte o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  
  
##  <a name="geterrorcount"></a>  CDaoException::GetErrorCount  
 Chame essa função de membro para recuperar o número de objetos de erro do DAO na coleção de erros do mecanismo de banco de dados.  
  
```  
short GetErrorCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de objetos de erro do DAO na coleção de erros do mecanismo de banco de dados.  
  
### <a name="remarks"></a>Comentários  
 Essas informações são úteis para executar um loop através da coleção de erros para recuperar cada um dos objetos de erro um ou mais DAO na coleção. Para recuperar um objeto de erro por índice ou por número de erro do DAO, chame o [GetErrorInfo](#geterrorinfo) função de membro.  
  
> [!NOTE]
>  Normalmente, há apenas um objeto de erro na coleção de erros. Se você estiver trabalhando com uma fonte de dados ODBC, no entanto, pode haver mais de um.  
  
##  <a name="geterrorinfo"></a>  CDaoException::GetErrorInfo  
 Retorna informações de erro sobre um objeto de erro específico na coleção de erros.  
  
```  
void GetErrorInfo(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 O índice das informações de erro na coleção de erros do mecanismo de banco de dados, para a pesquisa por índice.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para obter os seguintes tipos de informações sobre a exceção:  
  
-   Código de erro  
  
-   Origem  
  
-   Descrição  
  
-   Arquivo de ajuda  
  
-   Contexto da Ajuda  
  
 `GetErrorInfo` armazena as informações no objeto de exceção `m_pErrorInfo` membro de dados. Para obter uma breve descrição das informações retornadas, consulte [m_pErrorInfo](#m_perrorinfo). Se você capturar uma exceção do tipo `CDaoException` gerada pelo MFC, o `m_pErrorInfo` membro já será preenchido. Se você optar por chamar diretamente o DAO, você deve chamar o objeto de exceção `GetErrorInfo` função de membro por conta própria para preencher `m_pErrorInfo`. Para obter uma descrição mais detalhada, consulte o [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) estrutura.  
  
 Para obter informações sobre o código de exemplo e exceções do DAO, consulte o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  
  
##  <a name="m_nafxdaoerror"></a>  CDaoException::m_nAfxDaoError  
 Contém um código de erro estendido de MFC.  
  
### <a name="remarks"></a>Comentários  
 Esse código é fornecido em casos em que um componente específico das classes DAO MFC tem tiver.  
  
 Os possíveis valores são:  
  
- A operação mais recente não resultou em um MFC de NO_AFX_DAO_ERROR erro estendido. No entanto, a operação pode ter produzida outros erros de DAO ou OLE, portanto, você deve verificar [m_pErrorInfo](#m_perrorinfo) e possivelmente [m_scode](#m_scode).  
  
- AFX_DAO_ERROR_ENGINE_INITIALIZATION MFC não foi possível inicializar o mecanismo de banco de dados Microsoft Jet. OLE pode ter falhado ao inicializar, ou pode ter sido Impossível criar uma instância do objeto de mecanismo de banco de dados DAO. Geralmente, esses problemas sugerem uma instalação incorreta de DAO ou OLE.  
  
- AFX_DAO_ERROR_DFX_BIND um endereço usado em uma chamada de função exchange (DFX) DAO campos de registro não existe ou é inválido (o endereço não foi usado para associar dados). Você pode passar um endereço inválido em uma chamada DFX ou o endereço talvez se tornarão inválido entre operações de DFX.  
  
- AFX_DAO_ERROR_OBJECT_NOT_OPEN você tentou abrir um conjunto de registros com base em um querydef ou um objeto tabledef que não estava em um estado aberto.  
  
##  <a name="m_perrorinfo"></a>  CDaoException::m_pErrorInfo  
 Contém um ponteiro para um `CDaoErrorInfo` estrutura que fornece informações sobre o objeto de erro do DAO recuperada pela última vez chamando [GetErrorInfo](#geterrorinfo).  
  
### <a name="remarks"></a>Comentários  
 Esse objeto contém as seguintes informações:  
  
|Membro de CDaoErrorInfo|Informações|Significado|  
|--------------------------|-----------------|-------------|  
|`m_lErrorCode`|Código do erro|O código de erro do DAO|  
|`m_strSource`|Origem|O nome do objeto ou aplicativo que originalmente gerou o erro|  
|`m_strDescription`|Descrição|Uma cadeia de caracteres descritiva associada ao erro|  
|`m_strHelpFile`|Arquivo de ajuda|Um caminho para um arquivo de Ajuda do Windows na qual o usuário pode obter informações sobre o problema|  
|`m_lHelpContext`|Contexto da Ajuda|A ID de contexto para um tópico no arquivo de Ajuda do DAO|  
  
 Para obter detalhes completos sobre as informações contidas na `CDaoErrorInfo` do objeto, consulte a [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) estrutura.  
  
##  <a name="m_scode"></a>  CDaoException::m_scode  
 Contém um valor do tipo `SCODE` que descreve o erro.  
  
### <a name="remarks"></a>Comentários  
 Esse é um código OLE. Raramente você precisará usar esse valor, porque, em quase todos os casos, mais específicas sobre o erro MFC ou DAO está disponível na outra `CDaoException` membros de dados.  
  
 Para obter informações sobre SCODE, consulte o tópico [estrutura de OLE códigos de erro](http://msdn.microsoft.com/library/windows/desktop/ms690088) no SDK do Windows. O tipo de dados SCODE mapeia para o tipo de dados HRESULT.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)
