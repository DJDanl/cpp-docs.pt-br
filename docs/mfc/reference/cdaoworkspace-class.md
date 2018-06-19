---
title: Classe CDaoWorkspace | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoWorkspace
- AFXDAO/CDaoWorkspace
- AFXDAO/CDaoWorkspace::CDaoWorkspace
- AFXDAO/CDaoWorkspace::Append
- AFXDAO/CDaoWorkspace::BeginTrans
- AFXDAO/CDaoWorkspace::Close
- AFXDAO/CDaoWorkspace::CommitTrans
- AFXDAO/CDaoWorkspace::CompactDatabase
- AFXDAO/CDaoWorkspace::Create
- AFXDAO/CDaoWorkspace::GetDatabaseCount
- AFXDAO/CDaoWorkspace::GetDatabaseInfo
- AFXDAO/CDaoWorkspace::GetIniPath
- AFXDAO/CDaoWorkspace::GetIsolateODBCTrans
- AFXDAO/CDaoWorkspace::GetLoginTimeout
- AFXDAO/CDaoWorkspace::GetName
- AFXDAO/CDaoWorkspace::GetUserName
- AFXDAO/CDaoWorkspace::GetVersion
- AFXDAO/CDaoWorkspace::GetWorkspaceCount
- AFXDAO/CDaoWorkspace::GetWorkspaceInfo
- AFXDAO/CDaoWorkspace::Idle
- AFXDAO/CDaoWorkspace::IsOpen
- AFXDAO/CDaoWorkspace::Open
- AFXDAO/CDaoWorkspace::RepairDatabase
- AFXDAO/CDaoWorkspace::Rollback
- AFXDAO/CDaoWorkspace::SetDefaultPassword
- AFXDAO/CDaoWorkspace::SetDefaultUser
- AFXDAO/CDaoWorkspace::SetIniPath
- AFXDAO/CDaoWorkspace::SetIsolateODBCTrans
- AFXDAO/CDaoWorkspace::SetLoginTimeout
- AFXDAO/CDaoWorkspace::m_pDAOWorkspace
dev_langs:
- C++
helpviewer_keywords:
- CDaoWorkspace [MFC], CDaoWorkspace
- CDaoWorkspace [MFC], Append
- CDaoWorkspace [MFC], BeginTrans
- CDaoWorkspace [MFC], Close
- CDaoWorkspace [MFC], CommitTrans
- CDaoWorkspace [MFC], CompactDatabase
- CDaoWorkspace [MFC], Create
- CDaoWorkspace [MFC], GetDatabaseCount
- CDaoWorkspace [MFC], GetDatabaseInfo
- CDaoWorkspace [MFC], GetIniPath
- CDaoWorkspace [MFC], GetIsolateODBCTrans
- CDaoWorkspace [MFC], GetLoginTimeout
- CDaoWorkspace [MFC], GetName
- CDaoWorkspace [MFC], GetUserName
- CDaoWorkspace [MFC], GetVersion
- CDaoWorkspace [MFC], GetWorkspaceCount
- CDaoWorkspace [MFC], GetWorkspaceInfo
- CDaoWorkspace [MFC], Idle
- CDaoWorkspace [MFC], IsOpen
- CDaoWorkspace [MFC], Open
- CDaoWorkspace [MFC], RepairDatabase
- CDaoWorkspace [MFC], Rollback
- CDaoWorkspace [MFC], SetDefaultPassword
- CDaoWorkspace [MFC], SetDefaultUser
- CDaoWorkspace [MFC], SetIniPath
- CDaoWorkspace [MFC], SetIsolateODBCTrans
- CDaoWorkspace [MFC], SetLoginTimeout
- CDaoWorkspace [MFC], m_pDAOWorkspace
ms.assetid: 64f60de6-4df1-4d4a-a65b-c489b5257d52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b249f8069ba12772d21d170b67236a5f013290ac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33377208"
---
# <a name="cdaoworkspace-class"></a>Classe CDaoWorkspace
Gerencia uma sessão de banco de dados nomeado e protegido por senha de logon para fazer logoff, por um único usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDaoWorkspace : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoWorkspace::CDaoWorkspace](#cdaoworkspace)|Constrói um objeto de espaço de trabalho. Em seguida, chamar **criar** ou **abrir**.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoWorkspace::Append](#append)|Acrescenta um espaço de trabalho recém-criado à coleção de espaços de trabalho do mecanismo de banco de dados.|  
|[CDaoWorkspace::BeginTrans](#begintrans)|Inicia uma nova transação, que se aplica a todos os bancos de dados abertos no espaço de trabalho.|  
|[CDaoWorkspace::Close](#close)|Fecha o espaço de trabalho e todos os objetos que ele contém. As transações pendentes serão revertidas.|  
|[CDaoWorkspace::CommitTrans](#committrans)|Conclui a transação atual e salva as alterações.|  
|[CDaoWorkspace::CompactDatabase](#compactdatabase)|Compacta ou duplica um banco de dados.|  
|[CDaoWorkspace::Create](#create)|Cria um novo objeto de espaço de trabalho do DAO.|  
|[CDaoWorkspace::GetDatabaseCount](#getdatabasecount)|Retorna o número de objetos de banco de dados DAO na coleção de bancos de dados do espaço de trabalho.|  
|[CDaoWorkspace::GetDatabaseInfo](#getdatabaseinfo)|Retorna informações sobre um banco de dados DAO especificado definido na coleção de bancos de dados do espaço de trabalho.|  
|[CDaoWorkspace::GetIniPath](#getinipath)|Retorna o local do banco de dados Microsoft Jet configurações de inicialização do mecanismo no registro do Windows.|  
|[CDaoWorkspace::GetIsolateODBCTrans](#getisolateodbctrans)|Retorna um valor que indica se várias transações que envolvam a mesma fonte de dados ODBC são isoladas via forçado várias conexões com a fonte de dados.|  
|[CDaoWorkspace::GetLoginTimeout](#getlogintimeout)|Retorna o número de segundos antes que um erro ocorre quando o usuário tentar fazer logon um banco de dados ODBC.|  
|[CDaoWorkspace::GetName](#getname)|Retorna o nome definido pelo usuário para o objeto de espaço de trabalho.|  
|[CDaoWorkspace::GetUserName](#getusername)|Retorna que o nome de usuário especificado quando o espaço de trabalho foi criado. Esse é o nome do proprietário do espaço de trabalho.|  
|[CDaoWorkspace::GetVersion](#getversion)|Retorna uma cadeia de caracteres que contém a versão do mecanismo de banco de dados associado ao espaço de trabalho.|  
|[CDaoWorkspace::GetWorkspaceCount](#getworkspacecount)|Retorna o número de objetos de espaço de trabalho DAO na coleção de espaços de trabalho do mecanismo de banco de dados.|  
|[CDaoWorkspace::GetWorkspaceInfo](#getworkspaceinfo)|Retorna informações sobre um espaço de trabalho DAO especificado definido na coleção de espaços de trabalho do mecanismo de banco de dados.|  
|[CDaoWorkspace::Idle](#idle)|Permite que o mecanismo de banco de dados executar tarefas em segundo plano.|  
|[CDaoWorkspace::IsOpen](#isopen)|Retorna zero se o espaço de trabalho é aberta.|  
|[CDaoWorkspace::Open](#open)|Abre explicitamente um objeto de espaço de trabalho associado ao espaço de trabalho do DAO padrão.|  
|[CDaoWorkspace::RepairDatabase](#repairdatabase)|Tenta reparar um banco de dados.|  
|[CDaoWorkspace::Rollback](#rollback)|Finaliza a transação atual e não salvar as alterações.|  
|[CDaoWorkspace::SetDefaultPassword](#setdefaultpassword)|Define a senha que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.|  
|[CDaoWorkspace::SetDefaultUser](#setdefaultuser)|Define o nome de usuário que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.|  
|[CDaoWorkspace::SetIniPath](#setinipath)|Define o local do banco de dados Microsoft Jet configurações de inicialização do mecanismo no registro do Windows.|  
|[CDaoWorkspace::SetIsolateODBCTrans](#setisolateodbctrans)|Especifica se várias transações que envolvam a mesma fonte de dados ODBC são isoladas, forçando várias conexões com a fonte de dados.|  
|[CDaoWorkspace::SetLoginTimeout](#setlogintimeout)|Define o número de segundos antes que um erro ocorre quando o usuário tenta fazer logon uma fonte de dados ODBC.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoWorkspace::m_pDAOWorkspace](#m_pdaoworkspace)|Aponta para o objeto de espaço de trabalho DAO subjacente.|  
  
## <a name="remarks"></a>Comentários  
 Na maioria dos casos, você não precisará vários espaços de trabalho e você não precisará criar objetos de espaço de trabalho explícita; Quando você abrir objetos de banco de dados e o conjunto de registros, eles usam espaço de trabalho do DAO padrão. No entanto, se necessário, você pode executar várias sessões em um tempo criando objetos de espaço de trabalho adicional. Cada objeto de espaço de trabalho pode conter vários objetos de banco de dados aberto em sua própria coleção de bancos de dados. Em MFC, um espaço de trabalho é principalmente um Gerenciador de transações, especificando um conjunto de bancos de dados abertos todos na mesma "espaço de transação".  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm um prefixo de "CDao". Em geral, as classes do MFC com base em DAO são mais compatíveis com que as classes do MFC com base em ODBC. As classes com base em DAO acessar dados por meio do mecanismo de banco de dados Microsoft Jet, incluindo drivers ODBC. Eles também oferecem suporte a operações de Data Definition Language (DDL), como criação de bancos de dados e adicionar tabelas e campos por meio de classes, sem a necessidade de chamar DAO diretamente.  
  
## <a name="capabilities"></a>Capacidades  
 Classe `CDaoWorkspace` fornece o seguinte:  
  
-   Acesso explícito, se necessário, para um espaço de trabalho padrão, criado pela inicialização do mecanismo de banco de dados. Normalmente você usar espaço de trabalho do DAO padrão implicitamente criando objetos de banco de dados e o conjunto de registros.  
  
-   Abrir um espaço de transação na qual as transações se aplicam a todos os bancos de dados no espaço de trabalho. Você pode criar espaços de trabalho adicionais para gerenciar espaços de transação separada.  
  
-   Uma interface para várias propriedades do mecanismo de banco de dados do Microsoft Jet subjacente (consulte as funções de membro estático). Abrir ou criar um espaço de trabalho ou chamar uma função de membro estático antes de abrir ou criar, inicializa o mecanismo de banco de dados.  
  
-   Acesso à coleção de espaços de trabalho do mecanismo de banco de dados, que armazena todos os espaços de trabalho ativos que foi anexados a ele. Você também pode criar e trabalhar com espaços de trabalho sem acrescentá-los à coleção.  
  
## <a name="security"></a>Segurança  
 MFC não implementa as coleções de usuários e grupos em DAO, que são usados para controle de segurança. Se você precisar desses aspectos do DAO, você deve programá-las por conta própria por meio de chamadas diretas para DAO interfaces. Para obter informações, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
## <a name="usage"></a>Uso  
 Você pode usar a classe `CDaoWorkspace` para:  
  
-   Explicitamente, abra o espaço de trabalho padrão.  
  
     Geralmente, o uso do espaço de trabalho padrão é implícita — quando você abre novo [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objetos. Mas você pode precisar acessá-lo explicitamente — por exemplo, para propriedades de mecanismo de banco de dados do access ou a coleção de espaços de trabalho. Consulte "Uso implícito do espaço de trabalho padrão" abaixo.  
  
-   Crie novos espaços de trabalho. Chamar [Append](#append) se você quiser adicioná-los à coleção de espaços de trabalho.  
  
-   Abra um espaço de trabalho existente na coleção de espaços de trabalho.  
  
 Criar um novo espaço de trabalho que ainda não existir em espaços de trabalho que coleta é descrita no [criar](#create) função de membro. Objetos de espaço de trabalho não persistem de qualquer forma entre as sessões do mecanismo de datababase. Se seu aplicativo estiver MFC vinculado estaticamente, encerrando o aplicativo uninitializes o mecanismo de banco de dados. Se seu aplicativo estiver vinculado com MFC dinamicamente, o mecanismo de banco de dados não foi inicializado quando a DLL do MFC é descarregada.  
  
 Explicitamente abrindo o espaço de trabalho padrão, ou abrir um espaço de trabalho existente na coleção de espaços de trabalho, descrita no [abrir](#open) função de membro.  
  
 Encerrar uma sessão do espaço de trabalho fechando o espaço de trabalho com o [fechar](#close) função de membro. **Fechar** fecha qualquer banco de dados que não tenha fechado anteriormente, revertendo transações não confirmadas.  
  
## <a name="transactions"></a>Transações  
 DAO gerencia transações no nível do espaço de trabalho; Portanto, as transações em um espaço de trabalho com vários bancos de dados abertos se aplicam a todos os bancos de dados. Por exemplo, se dois bancos de dados têm atualizações não confirmadas e você chamar [CommitTrans](#committrans), todas as atualizações são confirmadas. Se você quiser limitar a transações para um único banco de dados, você precisa de um objeto de espaço de trabalho separado para ele.  
  
## <a name="implicit-use-of-the-default-workspace"></a>Uso implícito do espaço de trabalho padrão  
 MFC usa o espaço de trabalho do DAO padrão implicitamente nas seguintes circunstâncias:  
  
-   Se você criar um novo `CDaoDatabase` do objeto, mas não faça isso por meio de uma existente `CDaoWorkspace` objeto MFC cria um objeto de espaço de trabalho temporário para você, que corresponde ao espaço de trabalho do DAO padrão. Se você fizer isso para vários bancos de dados, todos os objetos de banco de dados são associados ao espaço de trabalho padrão. Você pode acessar o espaço de trabalho de um banco de dados por meio de um `CDaoDatabase` membro de dados.  
  
-   Da mesma forma, se você criar um `CDaoRecordset` objeto sem fornecer um ponteiro para um `CDaoDatabase` objeto MFC cria um objeto de banco de dados temporário e, por extensão, um objeto de espaço de trabalho temporário. Você pode acessar o banco de dados de um conjunto de registros e indiretamente seu espaço de trabalho, por meio de um `CDaoRecordset` membro de dados.  
  
## <a name="other-operations"></a>Outras operações  
 Outras operações de banco de dados também são fornecidas, como reparar um banco de dados corrompido ou a compactação de um banco de dados.  
  
 Para obter informações sobre chamando DAO diretamente e segurança DAO, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDaoWorkspace`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="append"></a>  CDaoWorkspace::Append  
 Chamar essa função de membro depois de chamar [criar](#create).  
  
```  
virtual void Append();
```  
  
### <a name="remarks"></a>Comentários  
 **Acrescentar** anexa um objeto de espaço de trabalho recém-criado à coleção de espaços de trabalho do mecanismo de banco de dados. Espaços de trabalho não persiste entre sessões do mecanismo de banco de dados; elas são armazenadas apenas na memória, não no disco. Você não precisa acrescentar um espaço de trabalho; Se você não fizer isso, você ainda pode usá-lo.  
  
 Um espaço de trabalho anexado permanece na coleção de espaços de trabalho, em um ativo, em estado aberto, até que você chame seu [fechar](#close) função de membro.  
  
 Para obter informações relacionadas, consulte o tópico "Acrescentar Method" na Ajuda do DAO.  
  
##  <a name="begintrans"></a>  CDaoWorkspace::BeginTrans  
 Chame essa função de membro para iniciar uma transação.  
  
```  
void BeginTrans();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar **BeginTrans**, as atualizações feitas para sua estrutura de dados ou banco de dados entram em vigor quando você confirma a transação. Como o espaço de trabalho define o espaço em uma única transação, a transação se aplica a todos os bancos de dados abertos no espaço de trabalho. Há duas maneiras de concluir a transação:  
  
-   Chamar o [CommitTrans](#committrans) função de membro para confirmar a transação e salvar as alterações para a fonte de dados.  
  
-   Ou ligue para o [reversão](#rollback) função de membro para cancelar a transação.  
  
 Fechar o objeto de espaço de trabalho ou um objeto de banco de dados enquanto uma transação está pendente reverte todas as transações pendentes.  
  
 Se você precisar isolar as transações em uma fonte de dados ODBC daquelas em outra fonte de dados ODBC, consulte o [SetIsolateODBCTrans](#setisolateodbctrans) função de membro.  
  
##  <a name="cdaoworkspace"></a>  CDaoWorkspace::CDaoWorkspace  
 Constrói um objeto `CDaoWorkspace`.  
  
```  
CDaoWorkspace();
```  
  
### <a name="remarks"></a>Comentários  
 Após a criação do objeto de C++, você tem duas opções:  
  
-   Chamar o objeto [abrir](#open) função de membro para abrir o espaço de trabalho padrão ou para abrir um objeto existente na coleção de espaços de trabalho.  
  
-   Ou ligue para o objeto [criar](#create) função de membro para criar um novo objeto de espaço de trabalho DAO. Isso inicia explicitamente uma nova sessão de espaço de trabalho, você pode consultar por meio de `CDaoWorkspace` objeto. Depois de chamar **criar**, você pode chamar [Append](#append) se você deseja adicionar o espaço de trabalho para a coleção de espaços de trabalho do mecanismo de banco de dados.  
  
 Consulte a visão geral da classe para [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) para obter informações sobre quando você precisa criar explicitamente uma `CDaoWorkspace` objeto. Normalmente, você pode usar espaços de trabalho criados implicitamente quando você abre um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto sem especificar um espaço de trabalho ou quando você abre um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto sem especificar um objeto de banco de dados. Objetos MFC DAO criados dessa maneira usam espaço de trabalho padrão do DAO, que é criado uma vez e reutilizado.  
  
 Para liberar um espaço de trabalho e seus objetos contidos, ligue para o objeto de espaço de trabalho [fechar](#close) função de membro.  
  
##  <a name="close"></a>  CDaoWorkspace::Close  
 Chame essa função de membro para fechar o objeto de espaço de trabalho.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Fechar um objeto de espaço de trabalho aberta libera o objeto DAO subjacente e, se o espaço de trabalho é um membro da coleção de espaços de trabalho, o remove da coleção. Chamando **fechar** é uma boa prática de programação.  
  
> [!CAUTION]
>  Fechar um objeto de espaço de trabalho fecha qualquer banco de dados aberto no espaço de trabalho. Isso resulta em qualquer aberto de conjuntos de registros nos bancos de dados que está sendo fechado bem e quaisquer edições pendentes ou atualizações são revertidas. Para obter informações relacionadas, consulte o [CDaoDatabase::Close](../../mfc/reference/cdaodatabase-class.md#close), [CDaoRecordset::Close](../../mfc/reference/cdaorecordset-class.md#close), [CDaoTableDef::Close](../../mfc/reference/cdaotabledef-class.md#close), e [CDaoQueryDef::Close](../../mfc/reference/cdaoquerydef-class.md#close) funções de membro.  
  
 Objetos de espaço de trabalho não são permanentes; elas só existem enquanto existir referências a eles. Isso significa que quando termina a sessão do mecanismo de banco de dados, o espaço de trabalho e sua coleção de bancos de dados não persistirão. Você deve recriá-los para a próxima sessão abrindo o espaço de trabalho e os bancos de dados novamente.  
  
 Para obter informações relacionadas, consulte o tópico "Método Close" na Ajuda do DAO.  
  
##  <a name="committrans"></a>  CDaoWorkspace::CommitTrans  
 Chamar essa função de membro para confirmar uma transação, salvar um grupo de edições e atualizações para um ou mais bancos de dados no espaço de trabalho.  
  
```  
void CommitTrans();
```  
  
### <a name="remarks"></a>Comentários  
 Uma transação consiste em uma série de alterações de dados de dados do banco ou sua estrutura, começando com uma chamada para [BeginTrans](#begintrans). Quando você concluir a transação, o confirma ou reverte-(Cancelar as alterações) com [reversão](#rollback). Por padrão, sem transações, as atualizações dos registros são confirmadas imediatamente. Chamando **BeginTrans** faz com que o compromisso de atualizações deve ser atrasada até que você chame **CommitTrans**.  
  
> [!CAUTION]
>  Dentro de um espaço de trabalho, as transações são sempre globais para o espaço de trabalho e não estão limitadas a apenas um banco de dados ou conjunto de registros. Se você executar operações em mais de um banco de dados ou conjunto de registros em uma transação de espaço de trabalho, **CommitTrans** confirmações todas as atualizações, pendentes e **reversão** restaura todas as operações nesses bancos de dados e conjuntos de registros.  
  
 Quando você fechar um banco de dados ou o espaço de trabalho com transações pendentes, as transações são todas revertidas.  
  
> [!NOTE]
>  Isso não é um mecanismo de confirmação de duas fases. Se uma atualização não for confirmada, outros ainda serão confirmada.  
  
##  <a name="compactdatabase"></a>  CDaoWorkspace::CompactDatabase  
 Chamar essa função de membro para compactar um Microsoft Jet especificado (. Banco de dados MDB).  
  
```  
static void PASCAL CompactDatabase(
    LPCTSTR lpszSrcName,  
    LPCTSTR lpszDestName,  
    LPCTSTR lpszLocale = dbLangGeneral,  
    int nOptions = 0);

 
static void PASCAL CompactDatabase(
    LPCTSTR lpszSrcName,  
    LPCTSTR lpszDestName,  
    LPCTSTR lpszLocale,  
    int nOptions,  
    LPCTSTR lpszPassword);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSrcName`  
 O nome de um objeto existente, fechado o banco de dados. Ele pode ser um caminho completo e nome de arquivo, como "c:\\\MYDB. MDB". Se o nome do arquivo tem uma extensão, você deve especificar isto. Se sua rede der suporte a uniform naming convention (UNC), você pode também especificar um caminho de rede, como "\\\\\\\MYSERVER\\\MYSHARE\\\MYDIR\\\MYDB. MDB". (Barras invertidas duplas são necessárias em cadeias de caracteres da caminho como "\\" é o caractere de escape de C++.)  
  
 `lpszDestName`  
 O caminho completo do banco de dados compactado que você está criando. Você também pode especificar um caminho de rede, como com `lpszSrcName`. Não é possível usar o `lpszDestName` argumento para especificar o mesmo arquivo de banco de dados como `lpszSrcName`.  
  
 `lpszPassword`  
 Uma senha, usada quando você deseja compactar um banco de dados protegido por senha. Observe que, se você usar a versão do `CompactDatabase` que usa uma senha, você deve fornecer todos os parâmetros. Além disso, como este é um parâmetro de conexão, ela requer formatação especial, como segue:; PWD = `lpszPassword`. Por exemplo:; PWD = "Bom". (O ponto e vírgula à esquerda é necessário).  
  
 `lpszLocale`  
 Uma expressão de cadeia de caracteres usada para especificar a ordem de agrupamento para a criação de `lpszDestName`. Se você omitir esse argumento ao aceitar o valor padrão de **dbLangGeneral** (veja abaixo), a localidade do novo banco de dados é o mesmo que o antigo banco de dados. Os possíveis valores são:  
  
- **dbLangGeneral** inglês, alemão, francês, português, italiano e espanhol moderno  
  
- **dbLangArabic** árabe  
  
- **dbLangCyrillic** russo  
  
- **dbLangCzech** tcheco  
  
- **dbLangDutch** holandês  
  
- **dbLangGreek** grego  
  
- **dbLangHebrew** hebraico  
  
- **dbLangHungarian** húngaro  
  
- **dbLangIcelandic** Islandês  
  
- **dbLangNordic** Idiomas nórdicos (Microsoft Jet database engine somente a versão 1.0)  
  
- **dbLangNorwdan** norueguês e dinamarquês  
  
- **dbLangPolish** polonês  
  
- **dbLangSpanish** espanhol tradicional  
  
- **dbLangSwedfin** sueco e finlandês  
  
- **dbLangTurkish** turco  
  
 `nOptions`  
 Indica uma ou mais opções para o banco de dados de destino, `lpszDestName`. Se você omitir esse argumento ao aceitar o valor padrão, o `lpszDestName` terá a mesma criptografia e a mesma versão `lpszSrcName`. Você pode combinar o **dbEncrypt** ou **dbDecrypt** opção com uma das opções de versão usando o operador OR bit a bit. Os valores possíveis, que especifica um formato de banco de dados, não uma versão de mecanismo de banco de dados, são:  
  
- **dbEncrypt** criptografar o banco de dados durante a compactação.  
  
- **dbDecrypt** descriptografar o banco de dados durante a compactação.  
  
- **dbVersion10** criar um banco de dados que usa a versão 1.0 do mecanismo de banco de dados Microsoft Jet durante a compactação.  
  
- **dbVersion11** criar um banco de dados que usa a versão 1.1 do mecanismo de banco de dados Microsoft Jet durante a compactação.  
  
- **dbVersion20** criar um banco de dados que usa a versão 2.0 do mecanismo de banco de dados Microsoft Jet durante a compactação.  
  
- **dbVersion30** criar um banco de dados que usa a versão 3.0 do mecanismo de banco de dados Microsoft Jet durante a compactação.  
  
 Você pode usar **dbEncrypt** ou **dbDecrypt** no argumento Opções para especificar se é para criptografar ou descriptografar o banco de dados conforme ele é compactado. Se você omitir uma constante de criptografia ou se você incluir **dbDecrypt** e **dbEncrypt**, `lpszDestName` terá a mesma criptografia como `lpszSrcName`. Você pode usar uma das constantes de versão no argumento Opções para especificar a versão do formato de dados para o banco de dados compactado. Esta constante afeta somente a versão do formato de dados de `lpszDestName`. Você pode especificar apenas uma constante de versão. Se você omitir uma constante de versão, `lpszDestName` terão a mesma versão `lpszSrcName`. Você pode compactar `lpszDestName` apenas para uma versão igual ou posterior do `lpszSrcName`.  
  
> [!CAUTION]
>  Se um banco de dados não for criptografado, é possível, mesmo se você implementar a segurança de senha do usuário, para ler diretamente o arquivo de disco binário que constituem o banco de dados.  
  
### <a name="remarks"></a>Comentários  
 Como alterar dados em um banco de dados, o arquivo de banco de dados pode se tornar fragmentado e usar mais espaço em disco necessário. Periodicamente, você deve compactar seu banco de dados para desfragmentar o arquivo de banco de dados. O banco de dados compactado é geralmente menor. Você também pode optar por alterar a ordem de agrupamento, a criptografia ou a versão do formato de dados enquanto você copia e compacta o banco de dados.  
  
> [!CAUTION]
>  O `CompactDatabase` função de membro não corretamente converterá um banco de dados do Microsoft Access completo de uma versão para outra. O formato de dados é convertido. Microsoft acesso definido objetos, como formulários e relatórios, não são convertidos. No entanto, os dados são convertidos corretamente.  
  
> [!TIP]
>  Você também pode usar `CompactDatabase` para copiar um arquivo de banco de dados.  
  
 Para obter mais informações sobre compactação de bancos de dados, consulte o tópico "Método CompactDatabase" na Ajuda do DAO.  
  
##  <a name="create"></a>  CDaoWorkspace::Create  
 Chamar essa função de membro para criar um novo objeto de espaço de trabalho DAO e associá-lo com o MFC `CDaoWorkspace` objeto.  
  
```  
virtual void Create(
    LPCTSTR lpszName,  
    LPCTSTR lpszUserName,  
    LPCTSTR lpszPassword);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Uma cadeia de caracteres com até 14 caracteres exclusivamente nomeia o novo objeto de espaço de trabalho. Você deve fornecer um nome. Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 *lpszUserName*  
 O nome de usuário do proprietário do espaço de trabalho. Para requisitos, consulte o `lpszDefaultUser` parâmetro para o [SetDefaultUser](#setdefaultuser) função de membro. Para obter informações relacionadas, consulte o tópico "Propriedade de nome de usuário" na Ajuda do DAO.  
  
 `lpszPassword`  
 A senha para o novo objeto de espaço de trabalho. Uma senha pode ter até 14 caracteres e pode conter qualquer caractere, exceto ASCII 0 (nulo). As senhas diferenciam maiúsculas de minúsculas. Para obter informações relacionadas, consulte o tópico "Propriedade de senha" na Ajuda do DAO.  
  
### <a name="remarks"></a>Comentários  
 O processo geral de criação é:  
  
1.  Construir um [CDaoWorkspace](#cdaoworkspace) objeto.  
  
2.  Chamar o objeto **criar** função de membro para criar o espaço de trabalho DAO subjacente. Você deve especificar um nome de espaço de trabalho.  
  
3.  Opcionalmente, chame [Append](#append) se você deseja adicionar o espaço de trabalho para a coleção de espaços de trabalho do mecanismo de banco de dados. Você pode trabalhar com o espaço de trabalho sem acrescentá-lo.  
  
 Após o **criar** chamada, o objeto de espaço de trabalho está em um estado aberto, pronto para uso. Você não chama **abrir** depois **criar**. Você não chama **criar** se o espaço de trabalho já existe na coleção de espaços de trabalho. **Criar** inicializa o mecanismo de banco de dados se ele já não foi inicializado para seu aplicativo.  
  
##  <a name="getdatabasecount"></a>  CDaoWorkspace::GetDatabaseCount  
 Chamar essa função de membro para recuperar o número de objetos de banco de dados DAO na coleção de bancos de dados do espaço de trabalho — o número de bancos de dados abertos no espaço de trabalho.  
  
```  
short GetDatabaseCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bancos de dados abertos no espaço de trabalho.  
  
### <a name="remarks"></a>Comentários  
 `GetDatabaseCount` é útil se você precisa executar um loop através de todos os bancos de dados definidos na coleção de bancos de dados do espaço de trabalho. Para obter informações sobre um determinado banco de dados na coleção, consulte [GetDatabaseInfo](#getdatabaseinfo). Uso típico é chamar `GetDatabaseCount` para o número de bancos de dados abertos, em seguida, use esse número como um índice de loop para chamadas repetidas para `GetDatabaseInfo`.  
  
##  <a name="getdatabaseinfo"></a>  CDaoWorkspace::GetDatabaseInfo  
 Chame essa função de membro para obter vários tipos de informações sobre um banco de dados aberto no espaço de trabalho.  
  
```  
void GetDatabaseInfo(
    int nIndex,  
    CDaoDatabaseInfo& dbinfo,  
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

 
void GetDatabaseInfo(
    LPCTSTR lpszName,  
    CDaoDatabaseInfo& dbinfo,  
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice com base em zero do objeto de banco de dados na coleção de bancos de dados do espaço de trabalho, pesquisa por índice.  
  
 `dbinfo`  
 Uma referência a um [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) objeto que retorna as informações solicitadas.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o banco de dados para recuperar. As opções disponíveis são listadas aqui, junto com o que eles fazer com que a função retornar:  
  
- `AFX_DAO_PRIMARY_INFO` (Padrão) Nome, atualizável, transações  
  
- `AFX_DAO_SECONDARY_INFO` Adição de informações principais: tempo limite de consulta de versão, ordem de agrupamento  
  
- `AFX_DAO_ALL_INFO` Adição de informações de primárias e secundárias: conectar-se  
  
 `lpszName`  
 O nome do objeto de banco de dados, para a pesquisa por nome. O nome é uma cadeia de caracteres com até 14 caracteres exclusivamente nomeia o novo objeto de espaço de trabalho.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um banco de dados por índice. A outra versão permite pesquisar por nome de um banco de dados.  
  
 Para obter uma descrição das informações retornadas em `dbinfo`, consulte o [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição do `dwInfoOptions`. Quando você solicita informações em um nível, você obtém informações de todos os níveis anteriores também.  
  
##  <a name="getinipath"></a>  CDaoWorkspace::GetIniPath  
 Chame essa função de membro para obter o local do banco de dados Microsoft Jet configurações de inicialização do mecanismo no registro do Windows.  
  
```  
static CString PASCAL GetIniPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o local do registro.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o local para obter informações sobre as configurações para o mecanismo de banco de dados. As informações retornadas são, na verdade, o nome de uma subchave de registro.  
  
 Para obter informações relacionadas, consulte os tópicos "Propriedade IniPath" e "Personalizando Windows registro configurações de acesso a dados" na Ajuda do DAO.  
  
##  <a name="getisolateodbctrans"></a>  CDaoWorkspace::GetIsolateODBCTrans  
 Chame essa função de membro para obter o valor atual da propriedade IsolateODBCTrans DAO para o espaço de trabalho.  
  
```  
BOOL GetIsolateODBCTrans();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se transações ODBC são isoladas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Em algumas situações, você precisará ter várias transações simultâneas pendentes no mesmo banco de dados ODBC. Para fazer isso, você precisa abrir um espaço de trabalho separado para cada transação. Tenha em mente que, embora cada espaço de trabalho pode ter sua própria conexão ODBC para o banco de dados, isso reduz o desempenho do sistema. Porque o isolamento de transação normalmente não é necessário, as conexões ODBC de vários objetos de espaço de trabalho abertos pelo mesmo usuário são compartilhadas por padrão.  
  
 Alguns servidores ODBC, como o Microsoft SQL Server, não permitem transações simultâneas em uma única conexão. Se você precisar ter mais de uma transação pendente por vez em relação a um banco de dados, defina a propriedade de IsolateODBCTrans como **TRUE** em cada espaço de trabalho, assim como você abri-lo. Isso força uma conexão ODBC separada para cada espaço de trabalho.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade IsolateODBCTrans" na Ajuda do DAO.  
  
##  <a name="getlogintimeout"></a>  CDaoWorkspace::GetLoginTimeout  
 Chame essa função de membro para obter o valor atual da propriedade LoginTimeout DAO para o espaço de trabalho.  
  
```  
static short PASCAL GetLoginTimeout();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de segundos antes que um erro ocorre quando você tenta fazer logon um banco de dados ODBC.  
  
### <a name="remarks"></a>Comentários  
 Esse valor representa o número de segundos antes que um erro ocorre quando você tenta fazer logon um banco de dados ODBC. A configuração de LoginTimeout padrão é 20 segundos. Quando LoginTimeout é definido como 0, não haverá tempo limite e a comunicação com a fonte de dados pode parar de responder.  
  
 Quando você está tentando fazer logon um banco de dados ODBC, como o Microsoft SQL Server, a conexão pode falhar como resultado de erros de rede ou porque o servidor não está em execução. Em vez de esperar o padrão 20 segundos para se conectar, você pode especificar quanto tempo o mecanismo de banco de dados aguarda antes de ele produz um erro. Logon servidor acontece implicitamente como parte de um número de eventos diferentes, como a execução de uma consulta em um banco de dados de servidor externo.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade LoginTimeout" na Ajuda do DAO.  
  
##  <a name="getname"></a>  CDaoWorkspace::GetName  
 Chamar essa função de membro para obter o nome definido pelo usuário DAO espaço de trabalho objeto subjacente a `CDaoWorkspace` objeto.  
  
```  
CString GetName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o nome definido pelo usuário do objeto DAO espaço de trabalho.  
  
### <a name="remarks"></a>Comentários  
 O nome é útil para acessar o objeto de espaço de trabalho DAO na coleção de espaços de trabalho do mecanismo de banco de dados por nome.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
##  <a name="getusername"></a>  CDaoWorkspace::GetUserName  
 Chame essa função de membro para obter o nome do proprietário do espaço de trabalho.  
  
```  
CString GetUserName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que representa o proprietário do objeto de espaço de trabalho.  
  
### <a name="remarks"></a>Comentários  
 Para obter ou definir as permissões para o proprietário do espaço de trabalho, chamar DAO diretamente para verificar a configuração de propriedade de permissões; Isso determina quais permissões o usuário tem. Para trabalhar com as permissões, você precisa de um sistema. Arquivo MDA.  
  
 Para obter informações sobre chamando DAO diretamente, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md). Para obter informações relacionadas, consulte o tópico "Propriedade de nome de usuário" na Ajuda do DAO.  
  
##  <a name="getversion"></a>  CDaoWorkspace::GetVersion  
 Chame essa função de membro para determinar a versão do mecanismo de banco de dados Microsoft Jet em uso.  
  
```  
static CString PASCAL GetVersion();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que indica a versão do mecanismo de banco de dados associado ao objeto.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado representa o número de versão no formato "principal"; Por exemplo, "3.0". O número de versão do produto (por exemplo, 3.0) consiste em número de versão (3), um período e o número de versão (0).  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Version" na Ajuda do DAO.  
  
##  <a name="getworkspacecount"></a>  CDaoWorkspace::GetWorkspaceCount  
 Chame essa função de membro para recuperar o número de objetos de espaço de trabalho DAO na coleção de espaços de trabalho do mecanismo de banco de dados.  
  
```  
short GetWorkspaceCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de espaços de trabalho abertos na coleção de espaços de trabalho.  
  
### <a name="remarks"></a>Comentários  
 Essa contagem não inclui espaços de trabalho abertos não é acrescentados à coleção. `GetWorkspaceCount` é útil se você precisa executar um loop através de todos os espaços de trabalho definidos na coleção de espaços de trabalho. Para obter informações sobre um determinado espaço de trabalho na coleção, consulte [GetWorkspaceInfo](#getworkspaceinfo). Uso típico é chamar `GetWorkspaceCount` para o número de espaços de trabalho abertos, em seguida, use esse número como um índice de loop para chamadas repetidas para `GetWorkspaceInfo`.  
  
##  <a name="getworkspaceinfo"></a>  CDaoWorkspace::GetWorkspaceInfo  
 Chame essa função de membro para obter vários tipos de informações sobre como abrir um espaço de trabalho na sessão.  
  
```  
void GetWorkspaceInfo(
    int nIndex,  
    CDaoWorkspaceInfo& wkspcinfo,  
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

 
void GetWorkspaceInfo(
    LPCTSTR lpszName,  
    CDaoWorkspaceInfo& wkspcinfo,  
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice com base em zero do objeto de banco de dados na coleção de espaços de trabalho, pesquisa por índice.  
  
 `wkspcinfo`  
 Uma referência a um [CDaoWorkspaceInfo](../../mfc/reference/cdaoworkspaceinfo-structure.md) objeto que retorna as informações solicitadas.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o espaço de trabalho para recuperar. As opções disponíveis são listadas aqui, junto com o que eles fazer com que a função retornar:  
  
- `AFX_DAO_PRIMARY_INFO` (Padrão) Nome  
  
- `AFX_DAO_SECONDARY_INFO` Adição de informações principais: nome de usuário  
  
- `AFX_DAO_ALL_INFO` Adição de informações de primárias e secundárias: isolar ODBCTrans  
  
 `lpszName`  
 O nome do objeto de espaço de trabalho, pesquisa por nome. O nome é uma cadeia de caracteres com até 14 caracteres exclusivamente nomeia o novo objeto de espaço de trabalho.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição das informações retornadas em `wkspcinfo`, consulte o [CDaoWorkspaceInfo](../../mfc/reference/cdaoworkspaceinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição do `dwInfoOptions`. Quando você solicita informações em um nível, você pode obter informações para os níveis anteriores.  
  
##  <a name="idle"></a>  CDaoWorkspace::Idle  
 Chamar **ocioso** para fornecer o mecanismo de banco de dados com a oportunidade de realizar tarefas em segundo plano que podem não estar atualizadas devido ao intenso processamento de dados.  
  
```  
static void PASCAL Idle(int nAction = dbFreeLocks);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAction`  
 Uma ação a ser tomada durante o processamento ocioso. Atualmente a ação só é válida é **dbFreeLocks**.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente é verdadeiro em ambientes de multitarefa multiusuário, no qual não há tempo suficiente processamento em segundo plano para manter todos os registros em um conjunto de registros atual.  
  
> [!NOTE]
>  Chamando **ocioso** não é necessário com bancos de dados criados com a versão 3.0 do mecanismo de banco de dados Microsoft Jet. Use **ocioso** apenas para bancos de dados criados com versões anteriores.  
  
 Normalmente, os bloqueios são removidos de leitura e dados em objetos de conjunto de registros do tipo dynaset locais é atualizado somente quando nenhuma outra ação (inclusive movimentos do mouse) está ocorrendo. Se você chamar periodicamente **ocioso**, você fornece o mecanismo de banco de dados com tempo atualizado em segundo plano, o processamento de tarefas, liberando os bloqueios de leitura desnecessários. Especificando o **dbFreeLocks** constante como um argumento retardará o processamento até que todos os bloqueios de leitura são liberados.  
  
 Essa função de membro não é necessário em ambientes de usuário único, a menos que estiver executando várias instâncias de um aplicativo. O **ocioso** função de membro pode aumentar o desempenho em um ambiente multiusuário porque força o mecanismo de banco de dados para liberar dados para o disco, liberando os bloqueios na memória. Você também pode liberar bloqueios de leitura fazendo parte de operações de uma transação.  
  
 Para obter informações relacionadas, consulte o tópico "Ocioso Method" na Ajuda do DAO.  
  
##  <a name="isopen"></a>  CDaoWorkspace::IsOpen  
 Chamar essa função de membro para determinar se o `CDaoWorkspace` objeto está aberto — ou seja, se o objeto MFC foi inicializado por uma chamada para [abrir](#open) ou uma chamada para [criar](#create).  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto de espaço de trabalho está aberto. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar qualquer do membro de funções de um espaço de trabalho que está no estado aberto.  
  
##  <a name="m_pdaoworkspace"></a>  CDaoWorkspace::m_pDAOWorkspace  
 Um ponteiro para o objeto de espaço de trabalho DAO subjacente.  
  
### <a name="remarks"></a>Comentários  
 Use este membro de dados se você precisa de acesso direto a objeto DAO subjacente. Você pode chamar interfaces do objeto DAO por este ponteiro.  
  
 Para obter informações sobre como acessar objetos DAO diretamente, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
##  <a name="open"></a>  CDaoWorkspace::Open  
 Abre explicitamente um objeto de espaço de trabalho associado ao espaço de trabalho do DAO padrão.  
  
```  
virtual void Open(LPCTSTR lpszName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 O nome do objeto DAO espaço de trabalho para abrir — uma cadeia de caracteres com até 14 caracteres exclusivamente nomeia o espaço de trabalho. Aceite o valor padrão **nulo** explicitamente abrir o espaço de trabalho padrão. Para requisitos de nomenclatura, consulte o `lpszName` parâmetro [criar](#create). Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `CDaoWorkspace` de objeto, chame essa função de membro para fazer o seguinte:  
  
-   Explicitamente, abra o espaço de trabalho padrão. Passar **nulo** para `lpszName`.  
  
-   Abra um existente `CDaoWorkspace` , e um membro da coleção de espaços de trabalho, por nome de objeto. Passe um nome válido para um objeto de espaço de trabalho existente.  
  
 **Abra** coloca o objeto de espaço de trabalho em um estado aberto e também inicializa o mecanismo de banco de dados se ele já não foi inicializado para seu aplicativo.  
  
 Embora muitos `CDaoWorkspace` membro funções só podem ser chamadas depois que o espaço de trabalho foi aberto, as seguintes funções de membro, que operam no mecanismo de banco de dados, estão disponíveis após a construção do objeto C++, mas antes de uma chamada para **aberto** :  
  
||||  
|-|-|-|  
|[Criar](#create)|[GetVersion](#getversion)|[SetDefaultUser](#setdefaultuser)|  
|[GetIniPath](#getinipath)|[Idle](#idle)|[SetIniPath](#setinipath)|  
|[GetLoginTimeout](#getlogintimeout)|[SetDefaultPassword](#setdefaultpassword)|[SetLoginTimeout](#setlogintimeout)|  
  
##  <a name="repairdatabase"></a>  CDaoWorkspace::RepairDatabase  
 Chame essa função de membro, se você precisar tentar reparar um banco de dados corrompido que acessa o mecanismo de banco de dados Microsoft Jet.  
  
```  
static void PASCAL RepairDatabase(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 O caminho e nome de arquivo para um arquivo de banco de dados existente do mecanismo do Microsoft Jet. Se você omitir o caminho, somente o diretório atual é pesquisado. Se o sistema oferece suporte a uniform naming convention (UNC), você pode também especificar um caminho de rede, como: "\\\\\\\MYSERVER\\\MYSHARE\\\MYDIR\\\MYDB. MDB". (Barras invertidas duplas são necessárias na cadeia de caracteres de caminho, como "\\" é o caractere de escape de C++.)  
  
### <a name="remarks"></a>Comentários  
 Você deve fechar o banco de dados especificado por `lpszName` antes de corrigi-lo. Em um ambiente multiusuário, outros usuários não podem ter `lpszName` abrir enquanto você estiver reparando-lo. Se `lpszName` não está fechado ou não está disponível para uso exclusivo, ocorrerá um erro.  
  
 Essa função de membro tenta reparar um banco de dados foi marcado como possivelmente danificado por uma operação de gravação incompleta. Isso pode ocorrer se um aplicativo usando o mecanismo de banco de dados Microsoft Jet for fechado inesperadamente devido a um problema de hardware de computador ou interrupção de energia. Se você concluir a operação e a chamada a [fechar](../../mfc/reference/cdaodatabase-class.md#close) função de membro ou sair do aplicativo de maneira normal, o banco de dados não será marcado como possivelmente danificado.  
  
> [!NOTE]
>  Depois de corrigir um banco de dados, também é uma boa ideia compactá-lo usando o [CompactDatabase](#compactdatabase) função de membro para desfragmentar o arquivo e para recuperar espaço em disco.  
  
 Para obter mais informações sobre como reparar bancos de dados, consulte o tópico "Método RepairDatabase" na Ajuda do DAO.  
  
##  <a name="rollback"></a>  CDaoWorkspace::Rollback  
 Chame essa função de membro para encerrar a transação atual e restaurar todos os bancos de dados no espaço de trabalho para sua condição antes da transação foi iniciada.  
  
```  
void Rollback();
```  
  
### <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Dentro de um objeto de espaço de trabalho, as transações são sempre globais para o espaço de trabalho e não estão limitadas a apenas um banco de dados ou conjunto de registros. Se você executar operações em mais de um banco de dados ou conjunto de registros em uma transação de espaço de trabalho, **reversão** restaura todas as operações em todos os bancos de dados e conjuntos de registros.  
  
 Se você fechar um objeto de espaço de trabalho sem salvar ou reverter todas as transações pendentes, as transações serão automaticamente revertidas. Se você chamar [CommitTrans](#committrans) ou **reversão** sem primeiro chamar [BeginTrans](#begintrans), ocorrerá um erro.  
  
> [!NOTE]
>  Quando você iniciar uma transação, o mecanismo de banco de dados registra as operações em um arquivo mantido no diretório especificado pela variável de ambiente TEMP na estação de trabalho. Se o arquivo de log de transações esgotar o espaço disponível em sua unidade TEMP, o mecanismo de banco de dados fará com que a MFC lançar um `CDaoException` (erro DAO 2004). Neste ponto, se você chamar **CommitTrans**, um número indeterminado de operações é confirmado, mas as operações não concluídas restantes serão perdidas e a operação deve ser reiniciado. Chamando **reversão** libera o log de transações e reverte todas as operações na transação.  
  
##  <a name="setdefaultpassword"></a>  CDaoWorkspace::SetDefaultPassword  
 Chame essa função de membro para definir a senha padrão que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.  
  
```  
static void PASCAL SetDefaultPassword(LPCTSTR lpszPassword);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPassword`  
 A senha padrão. Uma senha pode ter até 14 caracteres e pode conter qualquer caractere, exceto ASCII 0 (nulo). As senhas diferenciam maiúsculas de minúsculas.  
  
### <a name="remarks"></a>Comentários  
 A senha padrão que você definiu se aplica a novos espaços de trabalho que você criar após a chamada. Ao criar espaços de trabalho subsequentes, você não precisa especificar uma senha no [criar](#create) chamar.  
  
 Para usar essa função de membro:  
  
1.  Construir um `CDaoWorkspace` do objeto, mas não chame **criar**.  
  
2.  Chamar `SetDefaultPassword` e, se desejar, [SetDefaultUser](#setdefaultuser).  
  
3.  Chamar **criar** para esse objeto de espaço de trabalho ou os demais, sem especificar uma senha.  
  
 Por padrão, a propriedade DefaultUser é definida como "admin" e a propriedade DefaultPassword é definida como uma cadeia de caracteres vazia ("").  
  
 Para obter mais informações sobre segurança, consulte o tópico "Propriedade permissões" na Ajuda do DAO. Para obter informações relacionadas, consulte os tópicos "DefaultPassword propriedades" e "DefaultUser" na Ajuda do DAO.  
  
##  <a name="setdefaultuser"></a>  CDaoWorkspace::SetDefaultUser  
 Chame essa função de membro para definir o nome de usuário padrão que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.  
  
```  
static void PASCAL SetDefaultUser(LPCTSTR lpszDefaultUser);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszDefaultUser`  
 O nome de usuário padrão. Um nome de usuário pode ter de 1 a 20 caracteres e incluir caracteres alfabéticos, caracteres acentuados, números, espaços e símbolos, exceto para: "(aspas) / (barra), \ (barra invertida), \[ \] (parênteses): (dois-pontos), &#124; ( pipe), \< (menos-sinal), > (maior-sinal), + (sinal de adição) = (sinal de igual), (ponto e vírgula), (vírgula), (ponto de interrogação), * (asterisco), os espaços e caracteres de controle (ASCII 00 a ASCII 31). Para obter informações relacionadas, consulte o tópico "Propriedade de nome de usuário" na Ajuda do DAO.  
  
### <a name="remarks"></a>Comentários  
 O nome de usuário padrão que você define se aplica a novos espaços de trabalho que você criar após a chamada. Quando você criar espaços de trabalho subsequentes, você não precisa especificar um nome de usuário no [criar](#create) chamar.  
  
 Para usar essa função de membro:  
  
1.  Construir um `CDaoWorkspace` do objeto, mas não chame **criar**.  
  
2.  Chamar `SetDefaultUser` e, se desejar, [SetDefaultPassword](#setdefaultpassword).  
  
3.  Chamar **criar** para esse objeto de espaço de trabalho ou os demais, sem especificar um nome de usuário.  
  
 Por padrão, a propriedade DefaultUser é definida como "admin" e a propriedade DefaultPassword é definida como uma cadeia de caracteres vazia ("").  
  
 Para obter informações relacionadas, consulte os tópicos "DefaultUser propriedades" e "DefaultPassword" na Ajuda do DAO.  
  
##  <a name="setinipath"></a>  CDaoWorkspace::SetIniPath  
 Chame essa função de membro para especificar o local das configurações de registro do Windows para o mecanismo de banco de dados Microsoft Jet.  
  
```  
static void PASCAL SetIniPath(LPCTSTR lpszRegistrySubKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszRegistrySubkey*  
 Uma cadeia de caracteres que contém o nome de uma subchave de registro do Windows para o local de configurações do mecanismo de banco de dados Microsoft Jet ou parâmetros necessários para bancos de dados ISAM instaláveis.  
  
### <a name="remarks"></a>Comentários  
 Chamar `SetIniPath` somente se você precisar especificar configurações especiais. Para obter mais informações, consulte o tópico "Propriedade IniPath" na Ajuda do DAO.  
  
> [!NOTE]
>  Chamar `SetIniPath` durante a instalação do aplicativo, não quando o aplicativo é executado. `SetIniPath` deve ser chamado antes de abrir qualquer espaços de trabalho, os bancos de dados ou os conjuntos de registros; Caso contrário, o MFC gera uma exceção.  
  
 Você pode usar esse mecanismo para configurar o mecanismo de banco de dados com as configurações de registro fornecida pelo usuário. O escopo desse atributo é limitado ao seu aplicativo e não pode ser alterado sem reiniciar o aplicativo.  
  
##  <a name="setisolateodbctrans"></a>  CDaoWorkspace::SetIsolateODBCTrans  
 Chame essa função de membro para definir o valor da propriedade IsolateODBCTrans DAO do espaço de trabalho.  
  
```  
void SetIsolateODBCTrans(BOOL bIsolateODBCTrans);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bIsolateODBCTrans*  
 Passar **TRUE** se você deseja começar a isolar transações ODBC. Passar **FALSE** se você deseja interromper o isolamento de transações ODBC.  
  
### <a name="remarks"></a>Comentários  
 Em algumas situações, você precisará ter várias transações simultâneas pendentes no mesmo banco de dados ODBC. Para fazer isso, você precisa abrir um espaço de trabalho separado para cada transação. Embora cada espaço de trabalho pode ter sua própria conexão ODBC para o banco de dados, isso reduz o desempenho do sistema. Porque o isolamento de transação normalmente não é necessário, as conexões ODBC de vários objetos de espaço de trabalho abertos pelo mesmo usuário são compartilhadas por padrão.  
  
 Alguns servidores ODBC, como o Microsoft SQL Server, não permitem transações simultâneas em uma única conexão. Se você precisar ter mais de uma transação pendente por vez em relação a um banco de dados, defina a propriedade de IsolateODBCTrans como **TRUE** em cada espaço de trabalho, assim como você abri-lo. Isso força uma conexão ODBC separada para cada espaço de trabalho.  
  
##  <a name="setlogintimeout"></a>  CDaoWorkspace::SetLoginTimeout  
 Chame essa função de membro para definir o valor da propriedade LoginTimeout DAO do espaço de trabalho.  
  
```  
static void PASCAL SetLoginTimeout(short nSeconds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSeconds`  
 O número de segundos antes que um erro ocorre quando você tenta fazer logon um banco de dados ODBC.  
  
### <a name="remarks"></a>Comentários  
 Esse valor representa o número de segundos antes que um erro ocorre quando você tenta fazer logon um banco de dados ODBC. A configuração de LoginTimeout padrão é 20 segundos. Quando LoginTimeout é definido como 0, não haverá tempo limite e a comunicação com a fonte de dados pode parar de responder.  
  
 Quando você está tentando fazer logon um banco de dados ODBC, como o Microsoft SQL Server, a conexão pode falhar como resultado de erros de rede ou porque o servidor não está em execução. Em vez de esperar o padrão 20 segundos para se conectar, você pode especificar quanto tempo o mecanismo de banco de dados aguarda antes de ele produz um erro. Fazer logon no servidor acontece implicitamente como parte de um número de eventos diferentes, como a execução de uma consulta em um banco de dados de servidor externo. O valor de tempo limite é determinado pela configuração atual da propriedade LoginTimeout.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade LoginTimeout" na Ajuda do DAO.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
