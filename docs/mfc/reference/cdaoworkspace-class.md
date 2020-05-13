---
title: Classe CDaoWorkspace
ms.date: 11/04/2016
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
ms.openlocfilehash: c492c806d64b1cfe0e4f73b3bb880ec7bd0a7e80
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754664"
---
# <a name="cdaoworkspace-class"></a>Classe CDaoWorkspace

Gerencia uma sessão de banco de dados nomeada e protegida por senha de login a logoff, por um único usuário. O DAO é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta.

## <a name="syntax"></a>Sintaxe

```
class CDaoWorkspace : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoWorkspace::CDaoWorkspace](#cdaoworkspace)|Constrói um objeto de espaço de trabalho. Depois, ligue `Create` `Open`ou.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoWorkspace::Apêndice](#append)|Anexa um espaço de trabalho recém-criado à coleção Workspaces do mecanismo de banco de dados.|
|[CDaoWorkspace::BeginTrans](#begintrans)|Começa uma nova transação, que se aplica a todos os bancos de dados abertos no espaço de trabalho.|
|[CDaoWorkspace::Close](#close)|Fecha o espaço de trabalho e todos os objetos que ele contém. As transações pendentes são revertidas.|
|[CDaoWorkspace::CommitTrans](#committrans)|Completa a transação atual e salva as alterações.|
|[CDaoWorkspace::CompactDatabase](#compactdatabase)|Compacta (ou duplica) um banco de dados.|
|[CDaoWorkspace::Criar](#create)|Cria um novo objeto DEespaço de trabalho DAO.|
|[CDaoWorkspace::GetDatabaseCount](#getdatabasecount)|Retorna o número de objetos de banco de dados DAO na coleção de bancos de dados do espaço de trabalho.|
|[CDaoWorkspace::GetDatabaseInfo](#getdatabaseinfo)|Retorna informações sobre um banco de dados DAO especificado definido na coleção de bancos de dados do espaço de trabalho.|
|[CDaoWorkspace::GetIniPath](#getinipath)|Retorna a localização das configurações de inicialização do mecanismo de banco de dados Microsoft Jet no registro do Windows.|
|[CDaoWorkspace::GetIsolateODBCTrans](#getisolateodbctrans)|Retorna um valor que indica se várias transações que envolvem a mesma fonte de dados ODBC são isoladas por meio de múltiplas conexões forçadas à fonte de dados.|
|[CDaoWorkspace::GetLoginTimeout](#getlogintimeout)|Retorna o número de segundos antes que ocorra um erro quando o usuário tenta fazer login em um banco de dados ODBC.|
|[CDaoWorkspace::GetName](#getname)|Retorna o nome definido pelo usuário para o objeto do espaço de trabalho.|
|[CDaoWorkspace::GetUserName](#getusername)|Retorna o nome de usuário especificado quando o espaço de trabalho foi criado. Este é o nome do dono do espaço de trabalho.|
|[CDaoWorkspace::GetVersion](#getversion)|Retorna uma seqüência que contém a versão do mecanismo de banco de dados associada ao espaço de trabalho.|
|[CDaoWorkspace::GetWorkspaceCount](#getworkspacecount)|Retorna o número de objetos de espaço de trabalho DAO na coleção Workspaces do mecanismo de banco de dados.|
|[CDaoWorkspace::GetWorkspaceInfo](#getworkspaceinfo)|Retorna informações sobre um espaço de trabalho DAO especificado definido na coleção Workspaces do mecanismo de banco de dados.|
|[CDaoWorkspace::Idle](#idle)|Permite que o mecanismo de banco de dados execute tarefas em segundo plano.|
|[CDaoWorkspace::IsOpen](#isopen)|Retorna não zero se o espaço de trabalho estiver aberto.|
|[CDaoWorkspace::Open](#open)|Abre explicitamente um objeto de espaço de trabalho associado ao espaço de trabalho padrão do DAO.|
|[CDaoWorkspace::RepairDatabase](#repairdatabase)|Tentativas de reparar um banco de dados danificado.|
|[CDaoWorkspace::Reversão](#rollback)|Termina a transação atual e não salva as alterações.|
|[CDaoWorkspace::SetDefaultPassword](#setdefaultpassword)|Define a senha que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.|
|[CDaoWorkspace::SetDefaultUser](#setdefaultuser)|Define o nome de usuário que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.|
|[CDaoWorkspace::SetIniPath](#setinipath)|Define a localização das configurações de inicialização do mecanismo de banco de dados Microsoft Jet no registro do Windows.|
|[CDaoWorkspace::SetIsolateODBCTrans](#setisolateodbctrans)|Especifica se várias transações que envolvem a mesma fonte de dados ODBC estão isoladas forçando várias conexões à fonte de dados.|
|[CDaoWorkspace::SetLoginTimeout](#setlogintimeout)|Define o número de segundos antes que ocorra um erro quando o usuário tenta fazer login em uma fonte de dados ODBC.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoWorkspace::m_pDAOWorkspace](#m_pdaoworkspace)|Aponta para o objeto daespaço de trabalho DAO subjacente.|

## <a name="remarks"></a>Comentários

Na maioria dos casos, você não precisará de vários espaços de trabalho e não precisará criar objetos explícitos de espaço de trabalho; quando você abre objetos de banco de dados e conjunto de registros, eles usam o espaço de trabalho padrão do DAO. No entanto, se necessário, você pode executar várias sessões ao mesmo tempo criando objetos adicionais de espaço de trabalho. Cada objeto de espaço de trabalho pode conter vários objetos de banco de dados abertos em sua própria coleção de bancos de dados. No MFC, um espaço de trabalho é principalmente um gerenciador de transações, especificando um conjunto de bancos de dados abertos todos no mesmo "espaço de transação".

> [!NOTE]
> As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm um prefixo "CDao". Em geral, as classes de MFC baseadas em DAO são mais capazes do que as classes MFC baseadas no ODBC. As classes baseadas em DAO acessam dados através do mecanismo de banco de dados Microsoft Jet, incluindo drivers ODBC. Eles também suportam operações ddl (Data Definition Language, linguagem de definição de dados), como criar bancos de dados e adicionar tabelas e campos através das classes, sem ter que ligar diretamente para o DAO.

## <a name="capabilities"></a>Funcionalidades

A `CDaoWorkspace` classe fornece o seguinte:

- Acesso explícito, se necessário, a um espaço de trabalho padrão, criado pela inicialização do mecanismo de banco de dados. Normalmente, você usa o espaço de trabalho padrão do DAO implicitamente criando objetos de banco de dados e conjunto de registros.

- Um espaço de transações no qual as transações se aplicam a todos os bancos de dados abertos no espaço de trabalho. Você pode criar espaços de trabalho adicionais para gerenciar espaços de transação separados.

- Uma interface para muitas propriedades do mecanismo de banco de dados Microsoft Jet subjacente (veja as funções de membro estático). Abrir ou criar um espaço de trabalho, ou chamar uma função de membro estático antes de abrir ou criar, inicializa o mecanismo do banco de dados.

- Acesso à coleção Workspaces do mecanismo de banco de dados, que armazena todos os espaços de trabalho ativos que foram anexados a ele. Você também pode criar e trabalhar com espaços de trabalho sem apendice-os à coleção.

## <a name="security"></a>Segurança

O MFC não implementa as coleções de Usuários e Grupos no DAO, que são usadas para controle de segurança. Se você precisa desses aspectos do DAO, você deve programá-los você mesmo através de chamadas diretas para interfaces DAO. Para obter informações, consulte [Nota Técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="usage"></a>Uso

Você pode `CDaoWorkspace` usar a classe para:

- Abra explicitamente o espaço de trabalho padrão.

   Normalmente, o uso do espaço de trabalho padrão está implícito — quando você abre novos objetos [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ou [CDaoRecordset.](../../mfc/reference/cdaorecordset-class.md) Mas você pode precisar acessá-lo explicitamente — por exemplo, para acessar propriedades do mecanismo do banco de dados ou a coleção Workspaces. Consulte "Uso implícito do espaço de trabalho padrão" abaixo.

- Crie novos espaços de trabalho. Ligue para [o Append](#append) se quiser adicioná-los à coleção Workspaces.

- Abra um espaço de trabalho existente na coleção Workspaces.

A criação de um novo espaço de trabalho que ainda não existe na coleção Espaços de Trabalho é descrita sob a função [Criar](#create) membro. Os objetos de espaço de trabalho não persistem de forma alguma entre as sessões do mecanismo datababase. Se o aplicativo vínculo mfc estáticamente, o término do aplicativo não inicializa o mecanismo do banco de dados. Se o aplicativo se vincula ao MFC dinamicamente, o mecanismo do banco de dados não será inicializado quando o DLL do MFC for descarregado.

Abrir explicitamente o espaço de trabalho padrão ou abrir um espaço de trabalho existente na coleção Workspaces é descrito sob a função [Open](#open) member.

Termine uma sessão de espaço de trabalho fechando o espaço de trabalho com a função [Close](#close) member. `Close`fecha quaisquer bancos de dados que você não tenha fechado anteriormente, revertendo quaisquer transações não comprometidas.

## <a name="transactions"></a>Transactions

O DAO gerencia transações no nível do espaço de trabalho; portanto, transações em um espaço de trabalho com vários bancos de dados abertos se aplicam a todos os bancos de dados. Por exemplo, se dois bancos de dados tiverem atualizações não comprometidas e você ligar para [o CommitTrans,](#committrans)todas as atualizações serão comprometidas. Se você quiser limitar transações a um único banco de dados, você precisa de um objeto de espaço de trabalho separado para ele.

## <a name="implicit-use-of-the-default-workspace"></a>Uso implícito do espaço de trabalho padrão

O MFC usa o espaço de trabalho padrão do DAO implicitamente nas seguintes circunstâncias:

- Se você criar `CDaoDatabase` um novo objeto, mas não `CDaoWorkspace` o fizer por meio de um objeto existente, o MFC criará um objeto de espaço de trabalho temporário para você, que corresponde ao espaço de trabalho padrão do DAO. Se você fizer isso para vários bancos de dados, todos os objetos do banco de dados estão associados ao espaço de trabalho padrão. Você pode acessar o espaço de `CDaoDatabase` trabalho de um banco de dados através de um membro de dados.

- Da mesma forma, `CDaoRecordset` se você criar um `CDaoDatabase` objeto sem fornecer um ponteiro a um objeto, o MFC criará um objeto de banco de dados temporário e, por extensão, um objeto de espaço de trabalho temporário. Você pode acessar o banco de dados de um conjunto `CDaoRecordset` de registros e, indiretamente, seu espaço de trabalho, através de um membro de dados.

## <a name="other-operations"></a>Outras Operações

Outras operações de banco de dados também são fornecidas, como reparar um banco de dados corrompido ou compactar um banco de dados.

Para obter informações sobre como ligar para o DAO diretamente e sobre a segurança da DAO, consulte [nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDaoWorkspace`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaoworkspaceappend"></a><a name="append"></a>CDaoWorkspace::Apêndice

Ligue para esta função de membro depois de chamar [Criar](#create).

```
virtual void Append();
```

### <a name="remarks"></a>Comentários

`Append`anexa um objeto de espaço de trabalho recém-criado para a coleção Workspaces do mecanismo de banco de dados. Os espaços de trabalho não persistem entre as sessões do mecanismo de banco de dados; eles são armazenados apenas na memória, não no disco. Você não precisa anexar um espaço de trabalho; se você não fizer isso, você ainda pode usá-lo.

Um espaço de trabalho anexado permanece na coleção Workspaces, em um estado ativo e aberto, até que você chame sua função de membro [Close.](#close)

Para obter informações relacionadas, consulte o tópico "Método de apêndice" no DAO Help.

## <a name="cdaoworkspacebegintrans"></a><a name="begintrans"></a>CDaoWorkspace::BeginTrans

Ligue para esta função de membro para iniciar uma transação.

```cpp
void BeginTrans();
```

### <a name="remarks"></a>Comentários

Depois de `BeginTrans`ligar, as atualizações que você faz para seus dados ou estrutura de banco de dados fazem efeito quando você comete a transação. Como o espaço de trabalho define um único espaço de transação, a transação se aplica a todos os bancos de dados abertos no espaço de trabalho. Existem duas maneiras de concluir a transação:

- Ligue para a função de membro [commitTrans](#committrans) para cometer a transação e salvar alterações na fonte de dados.

- Ou ligue para a função [membro Rollback](#rollback) para cancelar a transação.

Fechar o objeto do espaço de trabalho ou um objeto de banco de dados enquanto uma transação está pendente reverte todas as transações pendentes.

Se você precisar isolar transações em uma fonte de dados ODBC daquelas em outra fonte de dados ODBC, consulte a função membro [do SetIsolateODBCTrans.](#setisolateodbctrans)

## <a name="cdaoworkspacecdaoworkspace"></a><a name="cdaoworkspace"></a>CDaoWorkspace::CDaoWorkspace

Constrói um objeto `CDaoWorkspace`.

```
CDaoWorkspace();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto C++, você tem duas opções:

- Chame a função de membro [Aberto](#open) do objeto para abrir o espaço de trabalho padrão ou para abrir um objeto existente na coleção Espaços de trabalho.

- Ou chame a função [Criar](#create) membro do objeto para criar um novo objeto de espaço de trabalho DAO. Isso inicia explicitamente uma nova sessão de espaço de `CDaoWorkspace` trabalho, a qual você pode se referir através do objeto. Depois `Create`de ligar, você pode ligar para o [Append](#append) se quiser adicionar o espaço de trabalho à coleção Workspaces do mecanismo de banco de dados.

Consulte a visão geral da classe do [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) para `CDaoWorkspace` obter informações sobre quando você precisa criar explicitamente um objeto. Normalmente, você usa espaços de trabalho criados implicitamente quando você abre um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) sem especificar um espaço de trabalho ou quando você abre um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) sem especificar um objeto de banco de dados. Os objetos DAO do MFC criados dessa forma usam o espaço de trabalho padrão do DAO, que é criado uma vez e reutilizado.

Para liberar um espaço de trabalho e seus objetos contidos, chame a função de membro [Close](#close) do objeto do espaço de trabalho.

## <a name="cdaoworkspaceclose"></a><a name="close"></a>CDaoWorkspace::Fechar

Chame esta função de membro para fechar o objeto do espaço de trabalho.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

O fechamento de um objeto de espaço de trabalho aberto libera o objeto DAO subjacente e, se o espaço de trabalho for um membro da coleção Workspaces, remove-o da coleção. Ligar `Close` é uma boa prática de programação.

> [!CAUTION]
> Fechar um objeto de espaço de trabalho fecha quaisquer bancos de dados abertos no espaço de trabalho. Isso resulta em quaisquer conjuntos de registros abertos nas bases de dados sendo fechadas também, e quaisquer edições ou atualizações pendentes são revertidas. Para obter informações relacionadas, consulte o [CDaoDatabase::Close](../../mfc/reference/cdaodatabase-class.md#close), [CDaoRecordset::Close](../../mfc/reference/cdaorecordset-class.md#close), [CDaoTableDef::Close](../../mfc/reference/cdaotabledef-class.md#close)e [CDaoQueryDef::Funções de](../../mfc/reference/cdaoquerydef-class.md#close) membro próximo.

Objetos de espaço de trabalho não são permanentes; eles só existem enquanto as referências a eles existem. Isso significa que, quando a sessão do mecanismo de banco de dados termina, o espaço de trabalho e sua coleção de bancos de dados não persistem. Você deve recriá-los para a próxima sessão abrindo seu espaço de trabalho e banco de dados novamente.

Para obter informações relacionadas, consulte o tópico "Close Method" no DAO Help.

## <a name="cdaoworkspacecommittrans"></a><a name="committrans"></a>CDaoWorkspace::CommitTrans

Ligue para essa função de membro para cometer uma transação — salve um grupo de edições e atualizações em um ou mais bancos de dados no espaço de trabalho.

```cpp
void CommitTrans();
```

### <a name="remarks"></a>Comentários

Uma transação consiste em uma série de alterações nos dados do banco de dados ou em sua estrutura, começando com uma chamada para [BeginTrans](#begintrans). Quando você concluir a transação, comprometa-a ou reverta-a (cancele as alterações) com [reversão](#rollback). Por padrão, sem transações, as atualizações dos registros são cometidas imediatamente. A `BeginTrans` chamada faz com que o compromisso `CommitTrans`das atualizações seja adiado até que você ligue .

> [!CAUTION]
> Dentro de um espaço de trabalho, as transações são sempre globais para o espaço de trabalho e não se limitam a apenas um banco de dados ou conjunto de registros. Se você executar operações em mais de um banco `CommitTrans` de dados ou conjunto `Rollback` de registros dentro de uma transação de espaço de trabalho, comprometerá todas as atualizações pendentes e restaurará todas as operações nesses bancos de dados e conjuntos de registros.

Quando você fecha um banco de dados ou espaço de trabalho com transações pendentes, as transações são todas revertidas.

> [!NOTE]
> Este não é um mecanismo de compromisso em duas fases. Se uma atualização não se comprometer, outras ainda se comprometerão.

## <a name="cdaoworkspacecompactdatabase"></a><a name="compactdatabase"></a>CDaoWorkspace::CompactDatabase

Chame esta função de membro para compactar um Microsoft Jet especificado (. MDB) banco de dados.

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

*lpszSrcName*<br/>
O nome de um banco de dados fechado existente. Pode ser um caminho completo e nome de\\arquivo, como "C: \MYDB. MDB". Se o nome do arquivo tiver uma extensão, você deve especá-lo. Se sua rede suportar a convenção de nomeação uniforme (UNC),\\\\\\você também\\poderá\\especificar\\um caminho de rede, como " \MYSERVER \MYSHARE \MYDIR \MYDB. MDB". (Barras traseiras duplas são necessárias nas\\strings do caminho porque " é o caractere de fuga C++.)

*lpszDestName*<br/>
O caminho completo do banco de dados compactado que você está criando. Você também pode especificar um caminho de rede como com *lpszSrcName*. Não é possível usar o argumento *lpszDestName* para especificar o mesmo arquivo de banco de dados *do lpszSrcName*.

*lpszPassword*<br/>
Uma senha, usada quando você deseja compactar um banco de dados protegido por senha. Observe que se você `CompactDatabase` usar a versão do que precisa de uma senha, você deve fornecer todos os parâmetros. Além disso, por se trata de um parâmetro de conexão, requer formatação especial, como segue: ; PWD= *lpszPassword*. Por exemplo: ; PWD="Feliz". (O ponto e vírgula principal é necessário.)

*lpszLocale*<br/>
Uma expressão de string usada para especificar ordem de coletânea para criar *lpszDestName*. Se você omitir esse argumento `dbLangGeneral` aceitando o valor padrão de (veja abaixo), a localização do novo banco de dados é a mesma do banco de dados antigo. Os valores possíveis são:

- `dbLangGeneral`Inglês, alemão, francês, português, italiano e espanhol moderno

- `dbLangArabic`Árabe

- `dbLangCyrillic`Russo

- `dbLangCzech`Tcheco

- `dbLangDutch`Holandês

- `dbLangGreek`Grego

- `dbLangHebrew`Hebraico

- `dbLangHungarian`Húngaro

- `dbLangIcelandic`Islandês

- `dbLangNordic`Idiomas nórdicos (apenas a versão 1.0 do mecanismo de banco de dados microsoft jet)

- `dbLangNorwdan`Norueguês e dinamarquês

- `dbLangPolish`Polonês

- `dbLangSpanish`Espanhol tradicional

- `dbLangSwedfin`Sueco e finlandês

- `dbLangTurkish`Turco

*nOpções*<br/>
Indica uma ou mais opções para o banco de dados de destino, *lpszDestName*. Se você omitir esse argumento aceitando o valor padrão, o *lpszDestName* terá a mesma criptografia e a mesma versão *que lpszSrcName*. Você pode `dbEncrypt` combinar `dbDecrypt` a ou opção com uma das opções de versão usando o operador bitwise-OR. Os valores possíveis, que especificam um formato de banco de dados, não uma versão do mecanismo de banco de dados, são:

- `dbEncrypt`Criptografe o banco de dados enquanto compacta.

- `dbDecrypt`Descriptografar o banco de dados enquanto compacta.

- `dbVersion10`Crie um banco de dados que use a versão 1.0 do mecanismo de banco de dados do Microsoft Jet durante a compactação.

- `dbVersion11`Crie um banco de dados que use a versão 1.1 do mecanismo de banco de dados do Microsoft Jet durante a compactação.

- `dbVersion20`Crie um banco de dados que use a versão 2.0 do mecanismo de banco de dados do Microsoft Jet durante a compactação.

- `dbVersion30`Crie um banco de dados que use a versão 3.0 do mecanismo de banco de dados do Microsoft Jet durante a compactação.

Você pode `dbEncrypt` `dbDecrypt` usar ou no argumento de opções para especificar se criptografar ou descriptografar o banco de dados à medida que ele é compactado. Se você omite uma constante `dbDecrypt` de `dbEncrypt`criptografia ou se você incluir ambos e , *lpszDestName* terá a mesma criptografia que *lpszSrcName*. Você pode usar uma das constantes de versão no argumento de opções para especificar a versão do formato de dados para o banco de dados compactado. Essa constante afeta apenas a versão do formato de dados do *lpszDestName*. Você pode especificar apenas uma constante de versão. Se você omite uma constante de versão, *lpszDestName* terá a mesma versão *que lpszSrcName*. Você pode compactar *lpszDestName* apenas para uma versão que seja a mesma ou posterior da *lpszSrcName*.

> [!CAUTION]
> Se um banco de dados não for criptografado, é possível, mesmo que você implemente a segurança de usuário/senha, ler diretamente o arquivo de disco binário que constitui o banco de dados.

### <a name="remarks"></a>Comentários

À medida que você altera dados em um banco de dados, o arquivo do banco de dados pode se fragmentar e usar mais espaço em disco do que o necessário. Periodicamente, você deve compactar seu banco de dados para desfragmentar o arquivo do banco de dados. O banco de dados compactado é geralmente menor. Você também pode optar por alterar a ordem de colagem, a criptografia ou a versão do formato de dados enquanto você copia e compacta o banco de dados.

> [!CAUTION]
> A `CompactDatabase` função member não converterá corretamente um banco de dados completo do Microsoft Access de uma versão para outra. Apenas o formato de dados é convertido. Objetos definidos pelo Microsoft Access, como formulários e relatórios, não são convertidos. No entanto, os dados são corretamente convertidos.

> [!TIP]
> Você também `CompactDatabase` pode usar para copiar um arquivo de banco de dados.

Para obter mais informações sobre a compactação de bancos de dados, consulte o tópico "Método CompactDatabase" no DAO Help.

## <a name="cdaoworkspacecreate"></a><a name="create"></a>CDaoWorkspace::Criar

Chame essa função de membro para criar um novo objeto `CDaoWorkspace` DEESPAÇO DE TRABALHO DAO e associá-lo com o objeto MFC.

```
virtual void Create(
    LPCTSTR lpszName,
    LPCTSTR lpszUserName,
    LPCTSTR lpszPassword);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma seqüência com até 14 caracteres que nomeie exclusivamente o novo objeto do espaço de trabalho. Você deve fornecer um nome. Para obter informações relacionadas, consulte o tópico "Propriedade de nome" no DAO Help.

*lpszUserName*<br/>
O nome de usuário do dono do espaço de trabalho. Para os requisitos, consulte o parâmetro *lpszDefaultUser* na função [SetDefaultUser](#setdefaultuser) member. Para obter informações relacionadas, consulte o tópico "Propriedade nome do usuário" na Ajuda da DAO.

*lpszPassword*<br/>
A senha do novo objeto do espaço de trabalho. Uma senha pode ter até 14 caracteres de comprimento e pode conter qualquer caractere, exceto ASCII 0 (nulo). As senhas diferenciam maiúsculas de minúsculas. Para obter informações relacionadas, consulte o tópico "Propriedade de senha" na Ajuda da DAO.

### <a name="remarks"></a>Comentários

O processo de criação global é:

1. Construa um objeto [CDaoWorkspace.](#cdaoworkspace)

1. Chame a função `Create` de membro do objeto para criar o espaço de trabalho DAO subjacente. Você deve especificar um nome de espaço de trabalho.

1. Opcionalmente ligue para [o Apêndice](#append) se quiser adicionar o espaço de trabalho à coleção Workspaces do mecanismo de banco de dados. Você pode trabalhar com o espaço de trabalho sem aprovi-lo.

Após `Create` a chamada, o objeto do espaço de trabalho está em estado aberto, pronto para uso. Você não `Open` liga `Create`depois. Você não `Create` liga se o espaço de trabalho já existe na coleção Workspaces. `Create`inicializa o mecanismo do banco de dados se ele ainda não tiver sido inicializado para sua aplicação.

## <a name="cdaoworkspacegetdatabasecount"></a><a name="getdatabasecount"></a>CDaoWorkspace::GetDatabaseCount

Ligue para essa função de membro para recuperar o número de objetos de banco de dados DAO na coleção de bancos de dados do espaço de trabalho — o número de bancos de dados abertos no espaço de trabalho.

```
short GetDatabaseCount();
```

### <a name="return-value"></a>Valor retornado

O número de bancos de dados abertos no espaço de trabalho.

### <a name="remarks"></a>Comentários

`GetDatabaseCount`é útil se você precisar fazer loop através de todos os bancos de dados definidos na coleção de bancos de dados do espaço de trabalho. Para obter informações sobre um determinado banco de dados na coleção, consulte [GetDatabaseInfo](#getdatabaseinfo). O uso típico `GetDatabaseCount` é chamar o número de bancos de dados abertos `GetDatabaseInfo`e, em seguida, usar esse número como um índice de loop para chamadas repetidas para .

## <a name="cdaoworkspacegetdatabaseinfo"></a><a name="getdatabaseinfo"></a>CDaoWorkspace::GetDatabaseInfo

Ligue para esta função de membro para obter vários tipos de informações sobre um banco de dados aberto no espaço de trabalho.

```cpp
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

*nIndex*<br/>
O índice baseado em zero do objeto de banco de dados na coleção de bancos de dados do espaço de trabalho, para busca por índice.

*dbinfo*<br/>
Uma referência a um objeto [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o banco de dados a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne:

- nome AFX_DAO_PRIMARY_INFO (Padrão), Updatable, Transações

- AFX_DAO_SECONDARY_INFO informações primárias mais: Versão, Ordem de Colisão, Tempo de Consulta

- AFX_DAO_ALL_INFO informações primárias e secundárias mais: Conectar

*lpszName*<br/>
O nome do objeto do banco de dados, para procurar pelo nome. O nome é uma string com até 14 caracteres que nomeiam exclusivamente o novo objeto do espaço de trabalho.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você procure um banco de dados por índice. A outra versão permite que você procure um banco de dados pelo nome.

Para obter uma descrição das informações retornadas no *dbinfo,* consulte a estrutura [CDaoDatabaseInfo.](../../mfc/reference/cdaodatabaseinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Quando você solicita informações em um nível, você recebe informações para quaisquer níveis anteriores também.

## <a name="cdaoworkspacegetinipath"></a><a name="getinipath"></a>CDaoWorkspace::GetIniPath

Ligue para esta função de membro para obter a localização das configurações de inicialização do mecanismo de banco de dados Microsoft Jet no registro do Windows.

```
static CString PASCAL GetIniPath();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o local do registro.

### <a name="remarks"></a>Comentários

Você pode usar o local para obter informações sobre as configurações do mecanismo do banco de dados. A informação retornada é na verdade o nome de uma subchave de registro.

Para obter informações relacionadas, consulte os tópicos "IniPath Property" e "Personalização das configurações de registro do Windows para acesso a dados" na Ajuda da DAO.

## <a name="cdaoworkspacegetisolateodbctrans"></a><a name="getisolateodbctrans"></a>CDaoWorkspace::GetIsolateODBCTrans

Ligue para esta função de membro para obter o valor atual da propriedade DAO IsolateODBCTrans para o espaço de trabalho.

```
BOOL GetIsolateODBCTrans();
```

### <a name="return-value"></a>Valor retornado

Não zero se as transações ODBC forem isoladas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Em algumas situações, você pode precisar ter várias transações simultâneas pendentes no mesmo banco de dados ODBC. Para fazer isso, você precisa abrir um espaço de trabalho separado para cada transação. Tenha em mente que, embora cada espaço de trabalho possa ter sua própria conexão ODBC com o banco de dados, isso retarda o desempenho do sistema. Como o isolamento de transações normalmente não é necessário, as conexões ODBC de vários objetos de espaço de trabalho abertos pelo mesmo usuário são compartilhadas por padrão.

Alguns servidores ODBC, como o Microsoft SQL Server, não permitem transações simultâneas em uma única conexão. Se você precisar ter mais de uma transação por vez pendente contra esse banco de dados, defina a propriedade IsolateODBCTrans como TRUE em cada espaço de trabalho assim que você abri-la. Isso força uma conexão ODBC separada para cada espaço de trabalho.

Para obter informações relacionadas, consulte o tópico "Propriedade IsolateODBCTrans" na Ajuda da DAO.

## <a name="cdaoworkspacegetlogintimeout"></a><a name="getlogintimeout"></a>CDaoWorkspace::GetLoginTimeout

Ligue para esta função de membro para obter o valor atual da propriedade DAO LoginTimeout para o espaço de trabalho.

```
static short PASCAL GetLoginTimeout();
```

### <a name="return-value"></a>Valor retornado

O número de segundos antes de um erro ocorre quando você tenta fazer login em um banco de dados ODBC.

### <a name="remarks"></a>Comentários

Esse valor representa o número de segundos antes que ocorra um erro quando você tenta fazer login em um banco de dados ODBC. A configuração de LoginTimeout padrão é de 20 segundos. Quando o LoginTimeout é definido como 0, não ocorre um intervalo e a comunicação com a fonte de dados pode parar de responder.

Quando você está tentando fazer login em um banco de dados ODBC, como o Microsoft SQL Server, a conexão pode falhar como resultado de erros de rede ou porque o servidor não está sendo executado. Em vez de esperar os 20 segundos padrão para se conectar, você pode especificar quanto tempo o mecanismo do banco de dados espera antes de produzir um erro. O login no servidor acontece implicitamente como parte de uma série de eventos diferentes, como a execução de uma consulta em um banco de dados de servidor externo.

Para obter informações relacionadas, consulte o tópico "LoginTimeout Property" no DAO Help.

## <a name="cdaoworkspacegetname"></a><a name="getname"></a>CDaoWorkspace::GetName

Chame esta função de membro para obter o nome definido pelo `CDaoWorkspace` usuário do objeto DAO workspace subjacente ao objeto.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o nome definido pelo usuário do objeto daárea de trabalho DAO.

### <a name="remarks"></a>Comentários

O nome é útil para acessar o objeto DAO workspace na coleção Workspaces do mecanismo de banco de dados pelo nome.

Para obter informações relacionadas, consulte o tópico "Propriedade de nome" no DAO Help.

## <a name="cdaoworkspacegetusername"></a><a name="getusername"></a>CDaoWorkspace::GetUserName

Ligue para esta função de membro para obter o nome do proprietário do espaço de trabalho.

```
CString GetUserName();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que representa o proprietário do objeto do espaço de trabalho.

### <a name="remarks"></a>Comentários

Para obter ou definir as permissões para o proprietário do espaço de trabalho, ligue diretamente para o DAO para verificar a configuração da propriedade Permissões; isso determina quais permissões esse usuário tem. Para trabalhar com permissões, você precisa de um SISTEMA. Arquivo MDA.

Para obter informações sobre como ligar diretamente para o DAO, consulte [nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md). Para obter informações relacionadas, consulte o tópico "Propriedade nome do usuário" na Ajuda da DAO.

## <a name="cdaoworkspacegetversion"></a><a name="getversion"></a>CDaoWorkspace::GetVersion

Ligue para esta função de membro para determinar a versão do mecanismo de banco de dados Microsoft Jet em uso.

```
static CString PASCAL GetVersion();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que indica a versão do mecanismo de banco de dados associado ao objeto.

### <a name="remarks"></a>Comentários

O valor retornado representa o número da versão no formulário "major.minor"; por exemplo, "3.0". O número da versão do produto (por exemplo, 3.0) consiste no número da versão (3), um período, e no número de lançamento (0).

Para obter informações relacionadas, consulte o tópico "Version Property" no DAO Help.

## <a name="cdaoworkspacegetworkspacecount"></a><a name="getworkspacecount"></a>CDaoWorkspace::GetWorkspaceCount

Ligue para esta função de membro para recuperar o número de objetos de espaço de trabalho DAO na coleção Workspaces do mecanismo de banco de dados.

```
short GetWorkspaceCount();
```

### <a name="return-value"></a>Valor retornado

O número de espaços de trabalho abertos na coleção Workspaces.

### <a name="remarks"></a>Comentários

Esta contagem não inclui quaisquer espaços de trabalho abertos não anexados à coleção. `GetWorkspaceCount`é útil se você precisar fazer loop em todos os espaços de trabalho definidos na coleção Workspaces. Para obter informações sobre um determinado espaço de trabalho na coleção, consulte [GetWorkspaceInfo](#getworkspaceinfo). O uso típico `GetWorkspaceCount` é chamar o número de espaços de trabalho abertos e, em seguida, usar esse número como um índice de loop para chamadas repetidas para `GetWorkspaceInfo`.

## <a name="cdaoworkspacegetworkspaceinfo"></a><a name="getworkspaceinfo"></a>CDaoWorkspace::GetWorkspaceInfo

Ligue para esta função de membro para obter vários tipos de informações sobre um espaço de trabalho aberto na sessão.

```cpp
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

*nIndex*<br/>
O índice baseado em zero do objeto de banco de dados na coleção Workspaces, para busca por índice.

*wkspcinfo*<br/>
Uma referência a um objeto [CDaoWorkspaceInfo](../../mfc/reference/cdaoworkspaceinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o espaço de trabalho a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne:

- nome AFX_DAO_PRIMARY_INFO (Padrão)

- AFX_DAO_SECONDARY_INFO informações primárias mais: Nome do usuário

- AFX_DAO_ALL_INFO informações primárias e secundárias mais: Isolar ODBCTrans

*lpszName*<br/>
O nome do objeto do espaço de trabalho, para procurar pelo nome. O nome é uma string com até 14 caracteres que nomeiam exclusivamente o novo objeto do espaço de trabalho.

### <a name="remarks"></a>Comentários

Para obter uma descrição das informações retornadas em *wkspcinfo,* consulte a estrutura [CDaoWorkspaceInfo.](../../mfc/reference/cdaoworkspaceinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Quando você solicita informações em um nível, você também recebe informações para níveis anteriores.

## <a name="cdaoworkspaceidle"></a><a name="idle"></a>CDaoWorkspace::Ocioso

Chamada `Idle` para fornecer ao mecanismo de banco de dados a oportunidade de executar tarefas em segundo plano que podem não estar atualizadas devido ao intenso processamento de dados.

```
static void PASCAL Idle(int nAction = dbFreeLocks);
```

### <a name="parameters"></a>Parâmetros

*nAction*<br/>
Uma ação a ser tomada durante o processamento ocioso. Atualmente, a única `dbFreeLocks`ação válida é .

### <a name="remarks"></a>Comentários

Isso é frequentemente verdade em ambientes multiuso e multitarefa em que não há tempo suficiente de processamento de fundo para manter todos os registros em uma corrente de registro.

> [!NOTE]
> A `Idle` chamada não é necessária com bancos de dados criados com a versão 3.0 do mecanismo de banco de dados Microsoft Jet. Use `Idle` apenas para bancos de dados criados com versões anteriores.

Normalmente, as fechaduras de leitura são removidas e os dados em objetos locais do tipo dynaset são atualizados apenas quando nenhuma outra ação (incluindo os movimentos do mouse) estão ocorrendo. Se você ligar `Idle`periodicamente, você fornece ao mecanismo do banco de dados tempo para acompanhar as tarefas de processamento de antecedentes, liberando bloqueios de leitura desnecessários. Especificar `dbFreeLocks` a constante como argumento atrasa o processamento até que todos os bloqueios de leitura sejam liberados.

Essa função de membro não é necessária em ambientes de um único usuário, a menos que várias instâncias de um aplicativo estejam sendo executados. A `Idle` função de membro pode aumentar o desempenho em um ambiente multiusuário porque força o mecanismo do banco de dados a lavar dados em disco, liberando bloqueios na memória. Você também pode liberar bloqueios de leitura fazendo as operações parte de uma transação.

Para obter informações relacionadas, consulte o tópico "Método Ocioso" no DAO Help.

## <a name="cdaoworkspaceisopen"></a><a name="isopen"></a>CDaoWorkspace::IsOpen

Ligue para esta função `CDaoWorkspace` de membro para determinar se o objeto está aberto — ou seja, se o objeto MFC foi inicializado por uma chamada para [Abrir](#open) ou uma chamada para [Criar](#create).

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o objeto do espaço de trabalho estiver aberto; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode chamar qualquer uma das funções de membro de um espaço de trabalho que está em um estado aberto.

## <a name="cdaoworkspacem_pdaoworkspace"></a><a name="m_pdaoworkspace"></a>CDaoWorkspace::m_pDAOWorkspace

Um ponteiro para o objeto daespaço de trabalho DAO subjacente.

### <a name="remarks"></a>Comentários

Use este membro de dados se precisar de acesso direto ao objeto DAO subjacente. Você pode chamar as interfaces do objeto DAO através deste ponteiro.

Para obter informações sobre como acessar objetos DAO diretamente, consulte [Nota Técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="cdaoworkspaceopen"></a><a name="open"></a>CDaoWorkspace::Aberto

Abre explicitamente um objeto de espaço de trabalho associado ao espaço de trabalho padrão do DAO.

```
virtual void Open(LPCTSTR lpszName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome do objeto espaço de trabalho DAO para abrir — uma seqüência com até 14 caracteres que nomeiam exclusivamente o espaço de trabalho. Aceite o valor padrão NULL para abrir explicitamente o espaço de trabalho padrão. Para os requisitos de nomeação, consulte o parâmetro *lpszName* para [Criar](#create). Para obter informações relacionadas, consulte o tópico "Propriedade de nome" no DAO Help.

### <a name="remarks"></a>Comentários

Depois de `CDaoWorkspace` construir um objeto, chame esta função de membro para fazer uma das seguintes:

- Abra explicitamente o espaço de trabalho padrão. Passe NULL para *lpszName*.

- Abra um `CDaoWorkspace` objeto existente, um membro da coleção Workspaces, pelo nome. Passe um nome válido para um objeto de espaço de trabalho existente.

`Open`coloca o objeto de espaço de trabalho em um estado aberto e também inicializa o mecanismo do banco de dados se ele ainda não tiver sido inicializado para o seu aplicativo.

Embora `CDaoWorkspace` muitas funções de membro só possam ser chamadas após a abertura do espaço de trabalho, as seguintes funções de membro, que operam no mecanismo do banco de dados, estão disponíveis após a construção do objeto C++, mas antes de uma chamada para: `Open`

||||
|-|-|-|
|[Criar](#create)|[GetVersion](#getversion)|[SetDefaultUser](#setdefaultuser)|
|[GetIniPath](#getinipath)|[Idle](#idle)|[SetIniPath](#setinipath)|
|[GetLoginTimeout](#getlogintimeout)|[SetDefaultPassword](#setdefaultpassword)|[SetLoginTimeout](#setlogintimeout)|

## <a name="cdaoworkspacerepairdatabase"></a><a name="repairdatabase"></a>CDaoWorkspace::Reparaçãobanco de dados

Ligue para essa função de membro se você precisar tentar reparar um banco de dados corrompido que acessa o mecanismo de banco de dados microsoft jet.

```
static void PASCAL RepairDatabase(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O caminho e o nome do arquivo para um arquivo de banco de dados do motor Microsoft Jet existente. Se você omite o caminho, apenas o diretório atual é pesquisado. Se o sistema suportar a convenção de nomeação uniforme (UNC), você\\\\\\também\\poderá especificar um caminho de rede, como: " \MYSERVER \MYSHARE\\\MYDIR\\\MYDB. MDB". (Barras traseiras duplas são necessárias\\na seqüência de caminhoporque " " é o caractere de fuga C++.)

### <a name="remarks"></a>Comentários

Você deve fechar o banco de dados especificado pelo *lpszName* antes de repará-lo. Em um ambiente multiusuário, outros usuários não podem ter *lpszName* aberto enquanto você estiver reparando-o. Se *lpszName* não estiver fechado ou não estiver disponível para uso exclusivo, ocorrerá um erro.

Esta função membro tenta reparar um banco de dados que foi marcado como possivelmente corrompido por uma operação de gravação incompleta. Isso pode ocorrer se um aplicativo usando o mecanismo de banco de dados Microsoft Jet for fechado inesperadamente devido a uma queda de energia ou problema de hardware de computador. Se você concluir a operação e chamar a função De membro [Próximo](../../mfc/reference/cdaodatabase-class.md#close) ou sair do aplicativo de forma usual, o banco de dados não será marcado como possivelmente corrompido.

> [!NOTE]
> Depois de reparar um banco de dados, também é uma boa ideia compactá-lo usando a função de membro [CompactDatabase](#compactdatabase) para desfragmentar o arquivo e recuperar espaço em disco.

Para obter mais informações sobre como reparar bancos de dados, consulte o tópico "RepairDatabase Method" no DAO Help.

## <a name="cdaoworkspacerollback"></a><a name="rollback"></a>CDaoWorkspace::Reversão

Ligue para essa função de membro para encerrar a transação atual e restaurar todos os bancos de dados no espaço de trabalho para sua condição antes que a transação seja iniciada.

```cpp
void Rollback();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Dentro de um objeto de espaço de trabalho, as transações são sempre globais para o espaço de trabalho e não se limitam a apenas um banco de dados ou conjunto de registros. Se você executar operações em mais de um banco `Rollback` de dados ou conjunto de registros dentro de uma transação de espaço de trabalho, restaurará todas as operações em todos esses bancos de dados e conjuntos de registros.

Se você fechar um objeto de espaço de trabalho sem salvar ou reverter quaisquer transações pendentes, as transações serão automaticamente revertidas. Se você chamar o [CommitTrans](#committrans) ou `Rollback` sem primeiro chamar [BeginTrans](#begintrans), ocorrerá um erro.

> [!NOTE]
> Quando você inicia uma transação, o mecanismo do banco de dados registra suas operações em um arquivo mantido no diretório especificado pela variável de ambiente TEMP na estação de trabalho. Se o arquivo de registro de transações esgotar o armazenamento disponível na `CDaoException` unidade TEMP, o mecanismo do banco de dados fará com que o MFC lance um (erro DAO 2004). Neste ponto, se `CommitTrans`você chamar, um número indeterminado de operações são cometidos, mas as operações restantes não concluídas são perdidas, e a operação tem que ser reiniciada. A `Rollback` chamada libera o registro de transações e reverte todas as operações da transação.

## <a name="cdaoworkspacesetdefaultpassword"></a><a name="setdefaultpassword"></a>CDaoWorkspace::SetDefaultPassword

Ligue para esta função de membro para definir a senha padrão que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.

```
static void PASCAL SetDefaultPassword(LPCTSTR lpszPassword);
```

### <a name="parameters"></a>Parâmetros

*lpszPassword*<br/>
A senha padrão. Uma senha pode ter até 14 caracteres de comprimento e pode conter qualquer caractere, exceto ASCII 0 (nulo). As senhas diferenciam maiúsculas de minúsculas.

### <a name="remarks"></a>Comentários

A senha padrão definida se aplica a novos espaços de trabalho criados após a chamada. Ao criar espaços de trabalho subseqüentes, não é necessário especificar uma senha na chamada [Criar.](#create)

Para usar esta função de membro:

1. Construa `CDaoWorkspace` um objeto, `Create`mas não chame.

1. Ligue `SetDefaultPassword` e, se quiser, [SetDefaultUser](#setdefaultuser).

1. Ligue `Create` para este objeto de espaço de trabalho ou subsequentes, sem especificar uma senha.

Por padrão, a propriedade DefaultUser é definida como "admin" e a propriedade DefaultPassword é definida como uma seqüência de string vazia ("").

Para obter mais informações sobre segurança, consulte o tópico "Propriedade de Permissões" no DAO Help. Para obter informações relacionadas, consulte os tópicos "Propriedade defaultPassword" e "Propriedade padrão do usuário" na Ajuda da DAO.

## <a name="cdaoworkspacesetdefaultuser"></a><a name="setdefaultuser"></a>CDaoWorkspace::SetDefaultUser

Chame essa função de membro para definir o nome de usuário padrão que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.

```
static void PASCAL SetDefaultUser(LPCTSTR lpszDefaultUser);
```

### <a name="parameters"></a>Parâmetros

*lpszDefaultUser*<br/>
O nome de usuário padrão. Um nome de usuário pode ter de 1 a 20 caracteres e incluir caracteres alfabéticos, caracteres acentuados, números, \[ \] espaços e símbolos, exceto por: " (aspas), / (barra para frente), \ (barra invertida), (suportes), : (cólon), &#124; (tubo), \< (sinal inferior), > (sinal maior que o sinal), + (sinal mais), = (sinal igual), ; (ponto e vírgula), (vírgula), (ponto de interrogação), \* (asterisco), espaços de liderança e caracteres de controle (ASCII 00 a ASCII 31). Para obter informações relacionadas, consulte o tópico "Propriedade nome do usuário" na Ajuda da DAO.

### <a name="remarks"></a>Comentários

O nome de usuário padrão que você define se aplica a novos espaços de trabalho criados após a chamada. Ao criar espaços de trabalho subseqüentes, você não precisa especificar um nome de usuário na chamada [Criar.](#create)

Para usar esta função de membro:

1. Construa `CDaoWorkspace` um objeto, `Create`mas não chame.

1. Ligue `SetDefaultUser` e, se quiser, [SetDefaultPassword](#setdefaultpassword).

1. Chame `Create` este objeto de espaço de trabalho ou subsequente, sem especificar um nome de usuário.

Por padrão, a propriedade DefaultUser é definida como "admin" e a propriedade DefaultPassword é definida como uma seqüência de string vazia ("").

Para obter informações relacionadas, consulte os tópicos "Propriedade padrão do usuário" e "Propriedade defaultPassword" na ajuda daO.

## <a name="cdaoworkspacesetinipath"></a><a name="setinipath"></a>CDaoWorkspace::SetIniPath

Ligue para esta função de membro para especificar a localização das configurações de registro do Windows para o mecanismo de banco de dados Microsoft Jet.

```
static void PASCAL SetIniPath(LPCTSTR lpszRegistrySubKey);
```

### <a name="parameters"></a>Parâmetros

*lpszRegistrySubkey*<br/>
Uma string contendo o nome de uma subchave de registro do Windows para a localização das configurações ou parâmetros do mecanismo de banco de dados microsoft jet necessários para bancos de dados ISAM instalados.

### <a name="remarks"></a>Comentários

Ligue `SetIniPath` somente se precisar especificar configurações especiais. Para obter mais informações, consulte o tópico "IniPath Property" no DAO Help.

> [!NOTE]
> Ligue `SetIniPath` durante a instalação do aplicativo, não quando o aplicativo for executado. `SetIniPath`deve ser chamado antes de abrir quaisquer espaços de trabalho, bancos de dados ou conjuntos de registros; caso contrário, mfc lança uma exceção.

Você pode usar esse mecanismo para configurar o mecanismo do banco de dados com configurações de registro fornecidas pelo usuário. O escopo deste atributo está limitado ao seu aplicativo e não pode ser alterado sem reiniciar sua aplicação.

## <a name="cdaoworkspacesetisolateodbctrans"></a><a name="setisolateodbctrans"></a>CDaoWorkspace::SetIsolateODBCTrans

Ligue para esta função de membro para definir o valor da propriedade DAO IsolateODBCTrans para o espaço de trabalho.

```cpp
void SetIsolateODBCTrans(BOOL bIsolateODBCTrans);
```

### <a name="parameters"></a>Parâmetros

*bIsolateODBCTrans*<br/>
Passe TRUE se quiser começar a isolar transações ODBC. Passe FALSO se quiser parar de isolar transações ODBC.

### <a name="remarks"></a>Comentários

Em algumas situações, você pode precisar ter várias transações simultâneas pendentes no mesmo banco de dados ODBC. Para fazer isso, você precisa abrir um espaço de trabalho separado para cada transação. Embora cada espaço de trabalho possa ter sua própria conexão ODBC com o banco de dados, isso retarda o desempenho do sistema. Como o isolamento de transações normalmente não é necessário, as conexões ODBC de vários objetos de espaço de trabalho abertos pelo mesmo usuário são compartilhadas por padrão.

Alguns servidores ODBC, como o Microsoft SQL Server, não permitem transações simultâneas em uma única conexão. Se você precisar ter mais de uma transação por vez pendente contra esse banco de dados, defina a propriedade IsolateODBCTrans como TRUE em cada espaço de trabalho assim que você abri-la. Isso força uma conexão ODBC separada para cada espaço de trabalho.

## <a name="cdaoworkspacesetlogintimeout"></a><a name="setlogintimeout"></a>CDaoWorkspace::SetLoginTimeout

Ligue para esta função de membro para definir o valor da propriedade DAO LoginTimeout para o espaço de trabalho.

```
static void PASCAL SetLoginTimeout(short nSeconds);
```

### <a name="parameters"></a>Parâmetros

*nSeconds*<br/>
O número de segundos antes de um erro ocorre quando você tenta fazer login em um banco de dados ODBC.

### <a name="remarks"></a>Comentários

Esse valor representa o número de segundos antes que ocorra um erro quando você tenta fazer login em um banco de dados ODBC. A configuração de LoginTimeout padrão é de 20 segundos. Quando o LoginTimeout é definido como 0, não ocorre um intervalo e a comunicação com a fonte de dados pode parar de responder.

Quando você está tentando fazer login em um banco de dados ODBC, como o Microsoft SQL Server, a conexão pode falhar como resultado de erros de rede ou porque o servidor não está sendo executado. Em vez de esperar os 20 segundos padrão para se conectar, você pode especificar quanto tempo o mecanismo do banco de dados espera antes de produzir um erro. O logon no servidor acontece implicitamente como parte de uma série de eventos diferentes, como a execução de uma consulta em um banco de dados de servidor externo. O valor de tempo é determinado pela configuração atual da propriedade LoginTimeout.

Para obter informações relacionadas, consulte o tópico "LoginTimeout Property" no DAO Help.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
