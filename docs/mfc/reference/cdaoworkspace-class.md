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
ms.openlocfilehash: eea3fb29f219890ebe596c5d8109257e9d422054
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839784"
---
# <a name="cdaoworkspace-class"></a>Classe CDaoWorkspace

Gerencia uma sessão de banco de dados nomeada e protegida por senha do logon para fazer logoff, por um único usuário. O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

## <a name="syntax"></a>Sintaxe

```
class CDaoWorkspace : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoWorkspace::CDaoWorkspace](#cdaoworkspace)|Constrói um objeto de espaço de trabalho. Depois, chame `Create` ou `Open` .|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoWorkspace:: Append](#append)|Anexa um espaço de trabalho recém-criado à coleção de espaços de trabalho do mecanismo de banco de dados.|
|[CDaoWorkspace::BeginTrans](#begintrans)|Inicia uma nova transação, que se aplica a todos os bancos de dados abertos no espaço de trabalho.|
|[CDaoWorkspace::Close](#close)|Fecha o espaço de trabalho e todos os objetos que ele contém. As transações pendentes são revertidas.|
|[CDaoWorkspace:: CommitTrans](#committrans)|Conclui a transação atual e salva as alterações.|
|[CDaoWorkspace::CompactDatabase](#compactdatabase)|Compacta (ou duplica) um banco de dados.|
|[CDaoWorkspace:: criar](#create)|Cria um novo objeto de espaço de trabalho DAO.|
|[CDaoWorkspace::GetDatabaseCount](#getdatabasecount)|Retorna o número de objetos de banco de dados DAO na coleção Databases do espaço de trabalho.|
|[CDaoWorkspace::GetDatabaseInfo](#getdatabaseinfo)|Retorna informações sobre um banco de dados DAO especificado definido na coleção de bancos de dados do espaço de trabalho.|
|[CDaoWorkspace::GetIniPath](#getinipath)|Retorna o local das configurações de inicialização do mecanismo de banco de dados do Microsoft Jet no registro do Windows.|
|[CDaoWorkspace::GetIsolateODBCTrans](#getisolateodbctrans)|Retorna um valor que indica se várias transações que envolvem a mesma fonte de dados ODBC são isoladas por meio de várias conexões forçadas com a fonte de dados.|
|[CDaoWorkspace::GetLoginTimeout](#getlogintimeout)|Retorna o número de segundos antes de ocorrer um erro quando o usuário tenta fazer logon em um banco de dados ODBC.|
|[CDaoWorkspace:: GetName](#getname)|Retorna o nome definido pelo usuário para o objeto de espaço de trabalho.|
|[CDaoWorkspace:: GetUserName](#getusername)|Retorna o nome de usuário especificado quando o espaço de trabalho foi criado. Este é o nome do proprietário do espaço de trabalho.|
|[CDaoWorkspace::GetVersion](#getversion)|Retorna uma cadeia de caracteres que contém a versão do mecanismo de banco de dados associada ao espaço de trabalho.|
|[CDaoWorkspace::GetWorkspaceCount](#getworkspacecount)|Retorna o número de objetos de espaço de trabalho DAO na coleção de espaços de trabalho do mecanismo de banco de dados.|
|[CDaoWorkspace::GetWorkspaceInfo](#getworkspaceinfo)|Retorna informações sobre um espaço de trabalho do DAO especificado definido na coleção de espaços de trabalho do mecanismo de banco de dados.|
|[CDaoWorkspace::Idle](#idle)|Permite que o mecanismo de banco de dados Execute tarefas em segundo plano.|
|[CDaoWorkspace::IsOpen](#isopen)|Retornará zero se o espaço de trabalho estiver aberto.|
|[CDaoWorkspace::Open](#open)|Abre explicitamente um objeto de espaço de trabalho associado ao espaço de trabalho padrão do DAO.|
|[CDaoWorkspace::RepairDatabase](#repairdatabase)|Tenta reparar um banco de dados danificado.|
|[CDaoWorkspace:: Rollback](#rollback)|Encerra a transação atual e não salva as alterações.|
|[CDaoWorkspace::SetDefaultPassword](#setdefaultpassword)|Define a senha que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.|
|[CDaoWorkspace::SetDefaultUser](#setdefaultuser)|Define o nome de usuário que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.|
|[CDaoWorkspace::SetIniPath](#setinipath)|Define o local das configurações de inicialização do mecanismo de banco de dados do Microsoft Jet no registro do Windows.|
|[CDaoWorkspace::SetIsolateODBCTrans](#setisolateodbctrans)|Especifica se várias transações que envolvem a mesma fonte de dados ODBC são isoladas forçando várias conexões com a fonte de dados.|
|[CDaoWorkspace::SetLoginTimeout](#setlogintimeout)|Define o número de segundos antes que um erro ocorra quando o usuário tenta fazer logon em uma fonte de dados ODBC.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoWorkspace::m_pDAOWorkspace](#m_pdaoworkspace)|Aponta para o objeto de espaço de trabalho DAO subjacente.|

## <a name="remarks"></a>Comentários

Na maioria dos casos, você não precisará de vários espaços de trabalho, e não será necessário criar objetos de espaço de trabalho explícitos; Quando você abre objetos de banco de dados e conjunto de registros, eles usam o espaço de trabalho padrão do DAO. No entanto, se necessário, você pode executar várias sessões por vez criando objetos de espaço de trabalho adicionais. Cada objeto de espaço de trabalho pode conter vários objetos Open Database em sua própria coleção de bancos de dados. No MFC, um espaço de trabalho é principalmente um Gerenciador de transações, especificando um conjunto de bancos de dados abertos no mesmo "espaço de transação".

> [!NOTE]
> As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm um prefixo "CDao". Em geral, as classes do MFC baseadas no DAO são mais compatíveis do que as classes do MFC baseadas no ODBC. As classes baseadas em DAO acessam dados por meio do mecanismo de banco de dados Microsoft Jet, incluindo drivers ODBC. Eles também oferecem suporte a operações DDL (linguagem de definição de dados), como a criação de bancos de dado e a adição de tabelas e campos por meio das classes, sem precisar chamar o DAO diretamente.

## <a name="capabilities"></a>Funcionalidades

`CDaoWorkspace`A classe fornece o seguinte:

- Acesso explícito, se necessário, a um espaço de trabalho padrão, criado inicializando o mecanismo de banco de dados. Normalmente, você usa o espaço de trabalho padrão do DAO implicitamente criando objetos de banco de dados e conjunto de registros.

- Um espaço de transação no qual as transações se aplicam a todos os bancos de dados abertos no espaço de trabalho. Você pode criar espaços de trabalho adicionais para gerenciar espaços de transação separados.

- Uma interface para muitas propriedades do mecanismo de banco de dados do Microsoft Jet subjacente (consulte as funções de membro estático). Abrir ou criar um espaço de trabalho, ou chamar uma função de membro estático antes de Open ou CREATE, inicializa o mecanismo de banco de dados.

- Acesso à coleção de espaços de trabalho do mecanismo de banco de dados, que armazena todos os espaços de trabalho ativos que foram anexados a ele. Você também pode criar e trabalhar com espaços de trabalho sem acrescentá-los à coleção.

## <a name="security"></a>Segurança

O MFC não implementa as coleções de usuários e grupos no DAO, que são usadas para controle de segurança. Se você precisar desses aspectos do DAO, deverá programá-los por conta própria por meio de chamadas diretas para interfaces do DAO. Para obter informações, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="usage"></a>Uso

Você pode usar `CDaoWorkspace` a classe para:

- Abra explicitamente o espaço de trabalho padrão.

   Geralmente, o uso do espaço de trabalho padrão é implícito — quando você abre novos objetos [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) . Mas talvez seja necessário acessá-lo explicitamente, por exemplo, para acessar propriedades do mecanismo de banco de dados ou a coleção de espaços de trabalho. Consulte "uso implícito do espaço de trabalho padrão" abaixo.

- Crie novos espaços de trabalho. Chame [Append](#append) se desejar adicioná-los à coleção de espaços de trabalho.

- Abra um espaço de trabalho existente na coleção de espaços de trabalho.

A criação de um novo espaço de trabalho que ainda não existe na coleção de espaços de trabalho é descrita na função [criar](#create) membro. Os objetos de espaço de trabalho não persistem de forma alguma entre as sessões do mecanismo banco. Se o aplicativo vincula o MFC estaticamente, finalizando o aplicativo, o mecanismo de banco de dados é desinicializado. Se seu aplicativo for vinculado dinamicamente ao MFC, o mecanismo de banco de dados não será inicializado quando a DLL do MFC for descarregada.

Abrir explicitamente o espaço de trabalho padrão ou abrir um espaço de trabalho existente na coleção de espaços de trabalho, é descrito na função de membro [Open](#open) .

Encerre uma sessão de espaço de trabalho fechando o espaço de trabalho com a função de membro [fechar](#close) . `Close` Fecha todos os bancos de dados que você não fechou anteriormente, revertendo as transações não confirmadas.

## <a name="transactions"></a>Transactions

O DAO gerencia transações no nível do espaço de trabalho; Portanto, as transações em um espaço de trabalho com vários bancos de dados abertos se aplicam a todos os bancos de dados. Por exemplo, se dois bancos de dados tiverem atualizações não confirmadas e você chamar o [CommitTrans](#committrans), todas as atualizações serão confirmadas. Se você quiser limitar as transações a um único banco de dados, precisará de um objeto espaço de trabalho separado para ele.

## <a name="implicit-use-of-the-default-workspace"></a>Uso implícito do espaço de trabalho padrão

O MFC usa o espaço de trabalho padrão do DAO implicitamente nas seguintes circunstâncias:

- Se você criar um novo `CDaoDatabase` objeto, mas não fizer isso por meio de um `CDaoWorkspace` objeto existente, o MFC criará um objeto de espaço de trabalho temporário para você, que corresponde ao espaço de trabalho padrão do DAO. Se você fizer isso para vários bancos de dados, todos os objetos de banco de dados serão associados ao espaço de trabalho padrão. Você pode acessar o espaço de trabalho de um banco de dados por meio de um `CDaoDatabase` membro de dado.

- Da mesma forma, se você criar um `CDaoRecordset` objeto sem fornecer um ponteiro para um `CDaoDatabase` objeto, o MFC criará um objeto de banco de dados temporário e, por extensão, um objeto de espaço de trabalho temporário. Você pode acessar um banco de dados do Recordset e, indiretamente, seu espaço de trabalho, por meio de um `CDaoRecordset` membro de dado.

## <a name="other-operations"></a>Outras operações

Outras operações de banco de dados também são fornecidas, como reparar um banco de dados corrompido ou compactar um banco de dados.

Para obter informações sobre como chamar o DAO diretamente e sobre a segurança do DAO, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoWorkspace`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="cdaoworkspaceappend"></a><a name="append"></a> CDaoWorkspace:: Append

Chame essa função de membro depois de chamar [Create](#create).

```
virtual void Append();
```

### <a name="remarks"></a>Comentários

`Append` anexa um objeto de espaço de trabalho recém-criado à coleção de espaços de trabalho do mecanismo de banco de dados. Os espaços de trabalho não persistem entre as sessões do mecanismo de banco de dados; Eles são armazenados somente na memória, não no disco. Você não precisa acrescentar um espaço de trabalho; Se você não fizer isso, ainda poderá usá-lo.

Um espaço de trabalho anexado permanece na coleção de espaços de trabalho, em um estado ativo, aberto, até que você chame sua função de membro de [fechamento](#close) .

Para obter informações relacionadas, consulte o tópico "Método Append" na ajuda do DAO.

## <a name="cdaoworkspacebegintrans"></a><a name="begintrans"></a> CDaoWorkspace:: BeginTrans

Chame essa função de membro para iniciar uma transação.

```cpp
void BeginTrans();
```

### <a name="remarks"></a>Comentários

Depois de chamar `BeginTrans` , as atualizações feitas para os dados ou a estrutura do banco de dados entrarão em vigor quando você confirmar a transação. Como o espaço de trabalho define um único espaço de transação, a transação se aplica a todos os bancos de dados abertos no espaço de trabalho. Há duas maneiras de concluir a transação:

- Chame a função de membro [CommitTrans](#committrans) para confirmar a transação e salvar as alterações na fonte de dados.

- Ou chame a função de membro [Rollback](#rollback) para cancelar a transação.

Fechar o objeto de espaço de trabalho ou um objeto de banco de dados enquanto uma transação está pendente reverte todas as transações pendentes.

Se você precisar isolar transações em uma fonte de dados ODBC daquelas em outra fonte de dados ODBC, consulte a função membro [SetIsolateODBCTrans](#setisolateodbctrans) .

## <a name="cdaoworkspacecdaoworkspace"></a><a name="cdaoworkspace"></a> CDaoWorkspace::CDaoWorkspace

Constrói um objeto `CDaoWorkspace`.

```
CDaoWorkspace();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto C++, você tem duas opções:

- Chame a função de membro [Open](#open) do objeto para abrir o espaço de trabalho padrão ou para abrir um objeto existente na coleção de espaços de trabalho.

- Ou chame a função de membro [Create](#create) do objeto para criar um novo objeto de espaço de trabalho DAO. Isso inicia explicitamente uma nova sessão de espaço de trabalho, que pode ser consultada por meio do `CDaoWorkspace` objeto. Depois de chamar `Create` , você pode chamar [Append](#append) se quiser adicionar o espaço de trabalho à coleção de espaços de trabalho do mecanismo de banco de dados.

Consulte a visão geral de classe para [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) para obter informações sobre quando você precisa criar um `CDaoWorkspace` objeto explicitamente. Normalmente, você usa espaços de trabalho criados implicitamente quando abre um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) sem especificar um espaço de trabalho ou quando você abre um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) sem especificar um objeto de banco de dados. Objetos DAO do MFC criados dessa maneira usam o espaço de trabalho padrão do DAO, que é criado uma vez e reutilizado.

Para liberar um espaço de trabalho e seus objetos contidos, chame a função de membro [Close](#close) do objeto de espaço de trabalho.

## <a name="cdaoworkspaceclose"></a><a name="close"></a> CDaoWorkspace:: fechar

Chame essa função de membro para fechar o objeto de espaço de trabalho.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Fechar um objeto de espaço de trabalho aberto libera o objeto DAO subjacente e, se o espaço de trabalho for um membro da coleção de espaços de trabalho, o o removerá da coleção. A chamada `Close` é uma boa prática de programação.

> [!CAUTION]
> Fechar um objeto de espaço de trabalho fecha todos os bancos de dados abertos no espaço de trabalho. Isso resulta em todos os conjuntos de registros abertos nos bancos de dados que estão sendo fechados também, e quaisquer edições ou atualizações pendentes são revertidas. Para obter informações relacionadas, consulte as funções de membro [CDaoDatabase:: Close](../../mfc/reference/cdaodatabase-class.md#close), [CDaoRecordset:: fechar](../../mfc/reference/cdaorecordset-class.md#close), [CDaoTableDef:: Close](../../mfc/reference/cdaotabledef-class.md#close)e [CDaoQueryDef:: Close](../../mfc/reference/cdaoquerydef-class.md#close) .

Os objetos do espaço de trabalho não são permanentes; Eles só existem enquanto houver referências a eles. Isso significa que, quando a sessão do mecanismo de banco de dados é encerrada, o espaço de trabalho e sua coleção Database não persistem. Você deve recriá-los para a próxima sessão abrindo o espaço de trabalho e os bancos de dados novamente.

Para obter informações relacionadas, consulte o tópico "Close Method" na ajuda do DAO.

## <a name="cdaoworkspacecommittrans"></a><a name="committrans"></a> CDaoWorkspace:: CommitTrans

Chame essa função de membro para confirmar uma transação — salve um grupo de edições e atualizações em um ou mais bancos de dados no espaço de trabalho.

```cpp
void CommitTrans();
```

### <a name="remarks"></a>Comentários

Uma transação consiste em uma série de alterações nos dados ou na estrutura do banco de dados, começando com uma chamada para [BeginTrans](#begintrans). Quando você concluir a transação, confirme-a ou reverta-a (cancele as alterações) com a [reversão](#rollback). Por padrão, sem transações, as atualizações dos registros são confirmadas imediatamente. `BeginTrans`A chamada faz com que o compromisso das atualizações seja atrasado até que você chame `CommitTrans` .

> [!CAUTION]
> Dentro de um espaço de trabalho, as transações são sempre globais para o espaço de trabalho e não são limitadas a apenas um banco de dados ou conjunto de registros. Se você executar operações em mais de um banco de dados ou conjunto de registros dentro de uma transação de espaço de trabalho, o `CommitTrans` confirmará todas as atualizações pendentes e `Rollback` restaurará todas as operações nesses bancos de dados e conjuntos de registros.

Quando você fecha um banco de dados ou espaço de trabalho com transações pendentes, as transações são todas revertidas.

> [!NOTE]
> Esse não é um mecanismo de confirmação de duas fases. Se uma atualização não for confirmada, outras ainda serão confirmadas.

## <a name="cdaoworkspacecompactdatabase"></a><a name="compactdatabase"></a> CDaoWorkspace:: CompactDatabase

Chame essa função de membro para compactar um Microsoft Jet especificado (. MDB).

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

### <a name="parameters"></a>parâmetros

*lpszSrcName*<br/>
O nome de um banco de dados existente e fechado. Pode ser um caminho completo e um nome de arquivo, como "C: \\ \MYDB. MDB ". Se o nome do arquivo tiver uma extensão, você deverá especificá-la. Se sua rede der suporte à UNC (Convenção de nomenclatura uniforme), você também poderá especificar um caminho de rede, como " \\ \\ \\ \MYSERVER \\ \MYSHARE \\ \MYDIR \\ \MYDB. MDB ". (As barras invertidas duplas são necessárias nas cadeias de caracteres de caminho porque " \\ " é o caractere de escape C++.)

*lpszDestName*<br/>
O caminho completo do banco de dados compactado que você está criando. Você também pode especificar um caminho de rede como com *lpszSrcName*. Você não pode usar o argumento *lpszDestName* para especificar o mesmo arquivo de banco de dados que *lpszSrcName*.

*lpszPassword*<br/>
Uma senha, usada quando você deseja compactar um banco de dados protegido por senha. Observe que, se você usar a versão do `CompactDatabase` que usa uma senha, deverá fornecer todos os parâmetros. Além disso, como esse é um parâmetro de conexão, ele requer formatação especial, da seguinte maneira:; PWD = *lpszPassword*. Por exemplo:; PWD = "feliz". (O ponto e vírgula à esquerda é necessário.)

*lpszLocale*<br/>
Uma expressão de cadeia de caracteres usada para especificar a ordem de agrupamento para criar *lpszDestName*. Se você omitir esse argumento aceitando o valor padrão de `dbLangGeneral` (veja abaixo), a localidade do novo banco de dados será a mesma do banco de dados antigo. Os valores possíveis são:

- `dbLangGeneral` Inglês, alemão, francês, Português, italiano e espanhol moderno

- `dbLangArabic` Árabe

- `dbLangCyrillic` Russo

- `dbLangCzech` Tcheco

- `dbLangDutch` Holandês

- `dbLangGreek` Grego

- `dbLangHebrew` Hebraico

- `dbLangHungarian` Húngaro

- `dbLangIcelandic` Islandês

- `dbLangNordic` Idiomas nórdico (somente versão 1,0 do mecanismo de banco de dados do Microsoft Jet)

- `dbLangNorwdan` Norueguês e dinamarquês

- `dbLangPolish` Polonês

- `dbLangSpanish` Espanhol tradicional

- `dbLangSwedfin` Sueco e finlandês

- `dbLangTurkish` Turco

*nOptions*<br/>
Indica uma ou mais opções para o banco de dados de destino, *lpszDestName*. Se você omitir esse argumento aceitando o valor padrão, o *lpszDestName* terá a mesma criptografia e a mesma versão que *lpszSrcName*. Você pode combinar a `dbEncrypt` `dbDecrypt` opção ou com uma das opções de versão usando o operador OR Os valores possíveis, que especificam um formato de banco de dados, não uma versão do mecanismo de banco de dados, são:

- `dbEncrypt` Criptografar o banco de dados durante a compactação.

- `dbDecrypt` Descriptografar o banco de dados durante a compactação.

- `dbVersion10` Crie um banco de dados que usa o mecanismo de banco de dados do Microsoft Jet versão 1,0 durante a compactação.

- `dbVersion11` Crie um banco de dados que usa o mecanismo de banco de dados do Microsoft Jet versão 1,1 durante a compactação.

- `dbVersion20` Crie um banco de dados que usa o mecanismo de banco de dados do Microsoft Jet versão 2,0 durante a compactação.

- `dbVersion30` Crie um banco de dados que usa o mecanismo de banco de dados do Microsoft Jet versão 3,0 durante a compactação.

Você pode usar `dbEncrypt` ou `dbDecrypt` no argumento options para especificar se deseja criptografar ou descriptografar o banco de dados conforme ele é compactado. Se você omitir uma constante de criptografia ou se incluir `dbDecrypt` e `dbEncrypt` , *lpszDestName* terá a mesma criptografia que *lpszSrcName*. Você pode usar uma das constantes de versão no argumento options para especificar a versão do formato de dados para o banco de dado compactado. Essa constante afeta apenas a versão do formato de dados de *lpszDestName*. Você pode especificar apenas uma constante de versão. Se você omitir uma constante de versão, *lpszDestName* terá a mesma versão que *lpszSrcName*. Você pode compactar *lpszDestName* apenas para uma versão igual ou posterior à do *lpszSrcName*.

> [!CAUTION]
> Se um banco de dados não estiver criptografado, é possível, mesmo se você implementar a segurança de usuário/senha, para ler diretamente o arquivo de disco binário que constitui o banco de dados.

### <a name="remarks"></a>Comentários

À medida que você altera os dados em um banco de dado, o arquivo de dados pode ficar fragmentado e usar mais espaço em disco do que o necessário. Periodicamente, você deve compactar seu banco de dados para desfragmentar o arquivo de banco de dados Normalmente, o banco de dados compactado é menor. Você também pode optar por alterar a ordem de agrupamento, a criptografia ou a versão do formato de dados enquanto copia e compacta o banco de dado.

> [!CAUTION]
> A `CompactDatabase` função de membro não converterá corretamente um banco de dados completo do Microsoft Access de uma versão para outra. Somente o formato de dados é convertido. Objetos definidos pelo Microsoft Access, como formulários e relatórios, não são convertidos. No entanto, os dados são convertidos corretamente.

> [!TIP]
> Você também pode usar `CompactDatabase` para copiar um arquivo de banco de dados.

Para obter mais informações sobre como compactar bancos de dados, consulte o tópico "Método CompactDatabase" na ajuda do DAO.

## <a name="cdaoworkspacecreate"></a><a name="create"></a> CDaoWorkspace:: criar

Chame essa função de membro para criar um novo objeto de espaço de trabalho DAO e associá-lo ao `CDaoWorkspace` objeto MFC.

```
virtual void Create(
    LPCTSTR lpszName,
    LPCTSTR lpszUserName,
    LPCTSTR lpszPassword);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Uma cadeia de caracteres com até 14 caracteres que nomeia exclusivamente o novo objeto de espaço de trabalho. Você deve fornecer um nome. Para obter informações relacionadas, consulte o tópico "propriedade de nome" na ajuda do DAO.

*lpszUserName*<br/>
O nome de usuário do proprietário do espaço de trabalho. Para obter os requisitos, consulte o parâmetro *lpszDefaultUser* para a função de membro [SetDefaultUser](#setdefaultuser) . Para obter informações relacionadas, consulte o tópico "propriedade de nome de usuário" na ajuda do DAO.

*lpszPassword*<br/>
A senha para o novo objeto de espaço de trabalho. Uma senha pode ter até 14 caracteres e pode conter qualquer caractere, exceto o ASCII 0 (nulo). As senhas diferenciam maiúsculas de minúsculas. Para obter informações relacionadas, consulte o tópico "propriedade de senha" na ajuda do DAO.

### <a name="remarks"></a>Comentários

O processo de criação geral é:

1. Construa um objeto [CDaoWorkspace](#cdaoworkspace) .

1. Chame a função de `Create` membro do objeto para criar o espaço de trabalho DAO subjacente. Você deve especificar um nome de espaço de trabalho.

1. Opcionalmente, chame [Append](#append) se você quiser adicionar o espaço de trabalho à coleção de espaços de trabalho do mecanismo de banco de dados. Você pode trabalhar com o espaço de trabalho sem acrescentá-lo.

Após a `Create` chamada, o objeto de espaço de trabalho está em um estado aberto, pronto para uso. Você não chama `Open` após `Create` . Você não chamará `Create` se o espaço de trabalho já existir na coleção de espaços de trabalho. `Create` Inicializa o mecanismo de banco de dados se ele ainda não tiver sido inicializado para seu aplicativo.

## <a name="cdaoworkspacegetdatabasecount"></a><a name="getdatabasecount"></a> CDaoWorkspace::GetDatabaseCount

Chame essa função de membro para recuperar o número de objetos de banco de dados DAO na coleção Databases do espaço de trabalho.

```
short GetDatabaseCount();
```

### <a name="return-value"></a>Valor Retornado

O número de bancos de dados abertos no espaço de trabalho.

### <a name="remarks"></a>Comentários

`GetDatabaseCount` será útil se você precisar executar um loop por todos os bancos de dados definidos na coleção de bancos de dados do espaço de trabalho. Para obter informações sobre um determinado banco de dados na coleção, consulte [GetDatabaseInfo](#getdatabaseinfo). O uso típico é para chamar `GetDatabaseCount` o número de bancos de dados abertos e, em seguida, usar esse número como um índice de loop para chamadas repetidas para `GetDatabaseInfo` .

## <a name="cdaoworkspacegetdatabaseinfo"></a><a name="getdatabaseinfo"></a> CDaoWorkspace::GetDatabaseInfo

Chame essa função de membro para obter vários tipos de informações sobre um banco de dados aberto no espaço de trabalho.

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

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do objeto de banco de dados na coleção Databases do espaço de trabalho, para pesquisa por índice.

*dbinfo*<br/>
Uma referência a um objeto [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o banco de dados recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne:

- AFX_DAO_PRIMARY_INFO (padrão) nome, atualizável, transações

- AFX_DAO_SECONDARY_INFO Informações primárias mais: versão, ordem de agrupamento, tempo limite de consulta

- AFX_DAO_ALL_INFO Informações primárias e secundárias mais: conectar

*lpszName*<br/>
O nome do objeto de banco de dados, para pesquisa por nome. O nome é uma cadeia de caracteres com até 14 caracteres que nomeia exclusivamente o novo objeto de espaço de trabalho.

### <a name="remarks"></a>Comentários

Uma versão da função permite pesquisar um banco de dados por índice. A outra versão permite pesquisar um banco de dados por nome.

Para obter uma descrição das informações retornadas em *DbInfo*, consulte a estrutura [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Ao solicitar informações em um nível, você obtém informações para todos os níveis anteriores também.

## <a name="cdaoworkspacegetinipath"></a><a name="getinipath"></a> CDaoWorkspace::GetIniPath

Chame essa função de membro para obter o local das configurações de inicialização do mecanismo de banco de dados do Microsoft Jet no registro do Windows.

```
static CString PASCAL GetIniPath();
```

### <a name="return-value"></a>Valor Retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o local do registro.

### <a name="remarks"></a>Comentários

Você pode usar o local para obter informações sobre as configurações do mecanismo de banco de dados. As informações retornadas são, na verdade, o nome de uma subchave do registro.

Para obter informações relacionadas, consulte os tópicos "Propriedade IniPath" e "Personalizando as configurações do registro do Windows para acesso a dados" na ajuda do DAO.

## <a name="cdaoworkspacegetisolateodbctrans"></a><a name="getisolateodbctrans"></a> CDaoWorkspace::GetIsolateODBCTrans

Chame essa função de membro para obter o valor atual da propriedade IsolateODBCTrans do DAO para o espaço de trabalho.

```
BOOL GetIsolateODBCTrans();
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se as transações ODBC forem isoladas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Em algumas situações, talvez seja necessário ter várias transações simultâneas pendentes no mesmo banco de dados ODBC. Para fazer isso, você precisa abrir um espaço de trabalho separado para cada transação. Tenha em mente que, embora cada espaço de trabalho possa ter sua própria conexão ODBC com o banco de dados, isso reduz o desempenho do sistema. Como o isolamento da transação normalmente não é necessário, as conexões ODBC de vários objetos de espaço de trabalho abertos pelo mesmo usuário são compartilhadas por padrão.

Alguns servidores ODBC, como Microsoft SQL Server, não permitem transações simultâneas em uma única conexão. Se você precisar ter mais de uma transação de cada vez pendentes em relação a esse banco de dados, defina a propriedade IsolateODBCTrans como TRUE em cada espaço de trabalho assim que abri-la. Isso força uma conexão ODBC separada para cada espaço de trabalho.

Para obter informações relacionadas, consulte o tópico "Propriedade IsolateODBCTrans" na ajuda do DAO.

## <a name="cdaoworkspacegetlogintimeout"></a><a name="getlogintimeout"></a> CDaoWorkspace::GetLoginTimeout

Chame essa função de membro para obter o valor atual da Propriedade LoginTimeout do DAO para o espaço de trabalho.

```
static short PASCAL GetLoginTimeout();
```

### <a name="return-value"></a>Valor Retornado

O número de segundos antes de ocorrer um erro quando você tenta fazer logon em um banco de dados ODBC.

### <a name="remarks"></a>Comentários

Esse valor representa o número de segundos antes de ocorrer um erro quando você tenta fazer logon em um banco de dados ODBC. A configuração padrão de LoginTimeout é de 20 segundos. Quando LoginTimeout é definido como 0, nenhum tempo limite ocorre e a comunicação com a fonte de dados pode parar de responder.

Quando você está tentando fazer logon em um banco de dados ODBC, como Microsoft SQL Server, a conexão pode falhar como resultado de erros de rede ou porque o servidor não está em execução. Em vez de esperar pelo padrão de 20 segundos para se conectar, você pode especificar quanto tempo o mecanismo de banco de dados aguarda antes de gerar um erro. O logon no servidor ocorre implicitamente como parte de vários eventos diferentes, como a execução de uma consulta em um banco de dados de servidor externo.

Para obter informações relacionadas, consulte o tópico "Propriedade LoginTimeout" na ajuda do DAO.

## <a name="cdaoworkspacegetname"></a><a name="getname"></a> CDaoWorkspace:: GetName

Chame essa função de membro para obter o nome definido pelo usuário do objeto de espaço de trabalho DAO subjacente ao `CDaoWorkspace` objeto.

```
CString GetName();
```

### <a name="return-value"></a>Valor Retornado

Uma [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o nome definido pelo usuário do objeto de espaço de trabalho DAO.

### <a name="remarks"></a>Comentários

O nome é útil para acessar o objeto de espaço de trabalho DAO na coleção de espaços de trabalho do mecanismo de banco de dados por nome.

Para obter informações relacionadas, consulte o tópico "propriedade de nome" na ajuda do DAO.

## <a name="cdaoworkspacegetusername"></a><a name="getusername"></a> CDaoWorkspace:: GetUserName

Chame essa função de membro para obter o nome do proprietário do espaço de trabalho.

```
CString GetUserName();
```

### <a name="return-value"></a>Valor Retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que representa o proprietário do objeto de espaço de trabalho.

### <a name="remarks"></a>Comentários

Para obter ou definir as permissões para o proprietário do espaço de trabalho, chame o DAO diretamente para verificar a configuração da propriedade Permissions; Isso determina quais permissões o usuário tem. Para trabalhar com permissões, você precisa de um sistema. Arquivo MDA.

Para obter informações sobre como chamar o DAO diretamente, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md). Para obter informações relacionadas, consulte o tópico "propriedade de nome de usuário" na ajuda do DAO.

## <a name="cdaoworkspacegetversion"></a><a name="getversion"></a> CDaoWorkspace:: GetVersion

Chame essa função de membro para determinar a versão do mecanismo de banco de dados Microsoft Jet em uso.

```
static CString PASCAL GetVersion();
```

### <a name="return-value"></a>Valor Retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que indica a versão do mecanismo de banco de dados associada ao objeto.

### <a name="remarks"></a>Comentários

O valor retornado representa o número de versão no formato "Major. Minor"; por exemplo, "3,0". O número de versão do produto (por exemplo, 3,0) consiste no número de versão (3), em um ponto e no número de versão (0).

Para obter informações relacionadas, consulte o tópico "propriedade da versão" na ajuda do DAO.

## <a name="cdaoworkspacegetworkspacecount"></a><a name="getworkspacecount"></a> CDaoWorkspace::GetWorkspaceCount

Chame essa função de membro para recuperar o número de objetos de espaço de trabalho DAO na coleção de espaços de trabalho do mecanismo de banco de dados.

```
short GetWorkspaceCount();
```

### <a name="return-value"></a>Valor Retornado

O número de espaços de trabalho abertos na coleção de espaços de trabalho.

### <a name="remarks"></a>Comentários

Essa contagem não inclui nenhum espaço de trabalho aberto não acrescentado à coleção. `GetWorkspaceCount` será útil se você precisar executar um loop por todos os espaços de trabalho definidos na coleção de espaços de trabalho. Para obter informações sobre um determinado espaço de trabalho na coleção, consulte [GetWorkspaceInfo](#getworkspaceinfo). O uso típico é para chamar `GetWorkspaceCount` o número de espaços de trabalho abertos e, em seguida, usar esse número como um índice de loop para chamadas repetidas para `GetWorkspaceInfo` .

## <a name="cdaoworkspacegetworkspaceinfo"></a><a name="getworkspaceinfo"></a> CDaoWorkspace::GetWorkspaceInfo

Chame essa função de membro para obter vários tipos de informações sobre um espaço de trabalho aberto na sessão.

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

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do objeto de banco de dados na coleção de espaços de trabalho, para pesquisa por índice.

*wkspcinfo*<br/>
Uma referência a um objeto [CDaoWorkspaceInfo](../../mfc/reference/cdaoworkspaceinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o espaço de trabalho recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne:

- Nome do AFX_DAO_PRIMARY_INFO (padrão)

- AFX_DAO_SECONDARY_INFO Informações primárias mais: nome de usuário

- AFX_DAO_ALL_INFO Informações primárias e secundárias mais: isolar ODBCTrans

*lpszName*<br/>
O nome do objeto de espaço de trabalho, para pesquisa por nome. O nome é uma cadeia de caracteres com até 14 caracteres que nomeia exclusivamente o novo objeto de espaço de trabalho.

### <a name="remarks"></a>Comentários

Para obter uma descrição das informações retornadas em *wkspcinfo*, consulte a estrutura [CDaoWorkspaceInfo](../../mfc/reference/cdaoworkspaceinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Ao solicitar informações em um nível, você também obtém informações para os níveis anteriores.

## <a name="cdaoworkspaceidle"></a><a name="idle"></a> CDaoWorkspace:: Idle

Chame `Idle` para fornecer ao mecanismo de banco de dados a oportunidade de executar tarefas em segundo plano que podem não estar atualizadas devido ao processamento intensivo de dados.

```
static void PASCAL Idle(int nAction = dbFreeLocks);
```

### <a name="parameters"></a>parâmetros

*nAction*<br/>
Uma ação a ser tomada durante o processamento de ociosidade. Atualmente, a única ação válida é `dbFreeLocks` .

### <a name="remarks"></a>Comentários

Isso geralmente é verdadeiro em ambientes multiusuários multitarefas em que não há tempo de processamento em segundo plano suficiente para manter todos os registros em um conjunto de registros atual.

> [!NOTE]
> `Idle`A chamada não é necessária com bancos de dados criados com a versão 3,0 do mecanismo de banco de dados do Microsoft Jet. Use `Idle` somente para bancos de dados criados com versões anteriores.

Normalmente, os bloqueios de leitura são removidos e os dados em objetos Recordset do tipo dynaset local são atualizados somente quando nenhuma outra ação (incluindo movimentos do mouse) está ocorrendo. Se você chamar periodicamente `Idle` , fornecerá ao mecanismo de banco de dados um tempo para acompanhar as tarefas de processamento em segundo plano liberando bloqueios de leitura desnecessários. A especificação da `dbFreeLocks` constante como um argumento atrasa o processamento até que todos os bloqueios de leitura sejam liberados.

Essa função de membro não é necessária em ambientes de usuário único, a menos que várias instâncias de um aplicativo estejam em execução. A `Idle` função de membro pode aumentar o desempenho em um ambiente multiusuário, pois força o mecanismo de banco de dados a liberar o disco, liberando os bloqueios na memória. Você também pode liberar bloqueios de leitura fazendo operações parte de uma transação.

Para obter informações relacionadas, consulte o tópico "método ocioso" na ajuda do DAO.

## <a name="cdaoworkspaceisopen"></a><a name="isopen"></a> CDaoWorkspace:: IsOpen

Chame essa função de membro para determinar se o `CDaoWorkspace` objeto está aberto — ou seja, se o objeto MFC foi inicializado por uma chamada para [Open](#open) ou uma chamada para [Create](#create).

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o objeto de espaço de trabalho estiver aberto; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode chamar qualquer uma das funções de membro de um espaço de trabalho que esteja em um estado aberto.

## <a name="cdaoworkspacem_pdaoworkspace"></a><a name="m_pdaoworkspace"></a> CDaoWorkspace:: m_pDAOWorkspace

Um ponteiro para o objeto de espaço de trabalho DAO subjacente.

### <a name="remarks"></a>Comentários

Use esse membro de dados se precisar de acesso direto ao objeto DAO subjacente. Você pode chamar as interfaces do objeto DAO por meio desse ponteiro.

Para obter informações sobre como acessar objetos DAO diretamente, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="cdaoworkspaceopen"></a><a name="open"></a> CDaoWorkspace:: abrir

Abre explicitamente um objeto de espaço de trabalho associado ao espaço de trabalho padrão do DAO.

```
virtual void Open(LPCTSTR lpszName = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
O nome do objeto de espaço de trabalho DAO a ser aberto — uma cadeia de caracteres com até 14 caracteres que nomeia exclusivamente o espaço de trabalho. Aceite o valor padrão NULL para abrir explicitamente o espaço de trabalho padrão. Para obter os requisitos de nomenclatura, consulte o parâmetro *lpszName* para [Create](#create). Para obter informações relacionadas, consulte o tópico "propriedade de nome" na ajuda do DAO.

### <a name="remarks"></a>Comentários

Depois de construir um `CDaoWorkspace` objeto, chame essa função de membro para executar um dos seguintes procedimentos:

- Abra explicitamente o espaço de trabalho padrão. Passe NULL para *lpszName*.

- Abra um `CDaoWorkspace` objeto existente, um membro da coleção de espaços de trabalho, por nome. Passe um nome válido para um objeto de espaço de trabalho existente.

`Open` coloca o objeto de espaço de trabalho em um estado aberto e também Inicializa o mecanismo de banco de dados se ele ainda não tiver sido inicializado para seu aplicativo.

Embora muitas `CDaoWorkspace` funções de membro só possam ser chamadas depois que o espaço de trabalho tiver sido aberto, as funções de membro a seguir, que operam no mecanismo de banco de dados, estarão disponíveis após a construção do objeto C++, mas antes de uma chamada para `Open` :

:::row:::
   :::column span="":::
      [Criada](#create)\
      [GetIniPath](#getinipath)\
      [GetLoginTimeout](#getlogintimeout)
   :::column-end:::
   :::column span="":::
      [Obter versão](#getversion)\
      [Idle](#idle)
   :::column-end:::
   :::column span="":::
      [SetDefaultPassword](#setdefaultpassword)\
      [SetDefaultUser](#setdefaultuser)
   :::column-end:::
   :::column span="":::
      [SetIniPath](#setinipath)\
      [SetLoginTimeout](#setlogintimeout)
   :::column-end:::
:::row-end:::

## <a name="cdaoworkspacerepairdatabase"></a><a name="repairdatabase"></a> CDaoWorkspace::RepairDatabase

Chame essa função de membro se precisar tentar reparar um banco de dados corrompido que acessa o mecanismo de banco de dados do Microsoft Jet.

```
static void PASCAL RepairDatabase(LPCTSTR lpszName);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
O caminho e o nome de arquivo de um banco de dados do mecanismo do Microsoft Jet existente. Se você omitir o caminho, somente o diretório atual será pesquisado. Se o seu sistema der suporte à UNC (Convenção de nomenclatura uniforme), você também poderá especificar um caminho de rede, como: " \\ \\ \\ \MYSERVER \\ \MYSHARE \\ \MYDIR \\ \MYDB. MDB ". (As barras invertidas duplas são necessárias na cadeia de caracteres do caminho porque " \\ " é o caractere de escape C++.)

### <a name="remarks"></a>Comentários

Você deve fechar o banco de dados especificado por *lpszName* antes de repará-lo. Em um ambiente multiusuário, outros usuários não podem ter o *lpszName* aberto enquanto você o está reparando. Se *lpszName* não estiver fechado ou não estiver disponível para uso exclusivo, ocorrerá um erro.

Essa função de membro tenta reparar um banco de dados que foi marcado como possivelmente corrompido por uma operação de gravação incompleta. Isso pode ocorrer se um aplicativo que usa o mecanismo de banco de dados Microsoft Jet for fechado inesperadamente devido a uma queda de energia ou um problema de hardware do computador. Se você concluir a operação e chamar a função de membro de [fechamento](../../mfc/reference/cdaodatabase-class.md#close) ou sair do aplicativo de forma usual, o banco de dados não será marcado como possivelmente corrompido.

> [!NOTE]
> Depois de reparar um banco de dados, também é uma boa ideia compactá-lo usando a função de membro [CompactDatabase](#compactdatabase) para desfragmentar o arquivo e recuperar o espaço em disco.

Para obter mais informações sobre como reparar bancos de dados, consulte o tópico "Método RepairDatabase" na ajuda do DAO.

## <a name="cdaoworkspacerollback"></a><a name="rollback"></a> CDaoWorkspace:: Rollback

Chame essa função de membro para encerrar a transação atual e restaurar todos os bancos de dados no espaço de trabalho para sua condição antes que a transação seja iniciada.

```cpp
void Rollback();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Em um objeto de espaço de trabalho, as transações são sempre globais para o espaço de trabalho e não são limitadas a apenas um banco de dados ou conjunto de registros. Se você executar operações em mais de um banco de dados ou conjunto de registros dentro de uma transação de espaço de trabalho, o `Rollback` restaurará todas as operações em todos os conjuntos de registros e dos mesmos.

Se você fechar um objeto de espaço de trabalho sem salvar ou reverter nenhuma transação pendente, as transações serão automaticamente revertidas. Se você chamar o [CommitTrans](#committrans) ou `Rollback` sem primeiro chamar [BeginTrans](#begintrans), ocorrerá um erro.

> [!NOTE]
> Quando você inicia uma transação, o mecanismo de banco de dados registra suas operações em um arquivo mantido no diretório especificado pela variável de ambiente TEMP na estação de trabalho. Se o arquivo de log de transações esgotar o armazenamento disponível em sua unidade temporária, o mecanismo de banco de dados fará com que o MFC lance um `CDaoException` (erro do DAO 2004). Neste ponto, se você chamar `CommitTrans` , um número indeterminado de operações será confirmado, mas as demais operações não concluídas serão perdidas e a operação precisará ser reiniciada. Chamar `Rollback` libera o log de transações e reverter todas as operações na transação.

## <a name="cdaoworkspacesetdefaultpassword"></a><a name="setdefaultpassword"></a> CDaoWorkspace::SetDefaultPassword

Chame essa função de membro para definir a senha padrão que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.

```
static void PASCAL SetDefaultPassword(LPCTSTR lpszPassword);
```

### <a name="parameters"></a>parâmetros

*lpszPassword*<br/>
A senha padrão. Uma senha pode ter até 14 caracteres e pode conter qualquer caractere, exceto o ASCII 0 (nulo). As senhas diferenciam maiúsculas de minúsculas.

### <a name="remarks"></a>Comentários

A senha padrão que você define aplica-se a novos espaços de trabalho criados após a chamada. Ao criar espaços de trabalho subsequentes, você não precisa especificar uma senha na chamada de [criação](#create) .

Para usar essa função de membro:

1. Construa um `CDaoWorkspace` objeto, mas não chame `Create` .

1. Chame `SetDefaultPassword` e, se desejar, [SetDefaultUser](#setdefaultuser).

1. Chame `Create` este objeto de espaço de trabalho ou os subsequentes, sem especificar uma senha.

Por padrão, a propriedade DefaultUser é definida como "admin" e a propriedade DefaultPassword é definida como uma cadeia de caracteres vazia ("").

Para obter mais informações sobre segurança, consulte o tópico "Propriedade Permissions" na ajuda do DAO. Para obter informações relacionadas, consulte os tópicos "Propriedade DefaultPassword" e "DefaultUser Property" na ajuda do DAO.

## <a name="cdaoworkspacesetdefaultuser"></a><a name="setdefaultuser"></a> CDaoWorkspace::SetDefaultUser

Chame essa função de membro para definir o nome de usuário padrão que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.

```
static void PASCAL SetDefaultUser(LPCTSTR lpszDefaultUser);
```

### <a name="parameters"></a>parâmetros

*lpszDefaultUser*<br/>
O nome de usuário padrão. Um nome de usuário pode ter de 1-20 A caracteres de comprimento e incluir caracteres alfabéticos, caracteres acentuados, números, espaços e símbolos, exceto para: "(aspas),/(barra invertida), \ (barra invertida), \[ \] (colchetes),: (dois-pontos), &#124; (sinal \< (less-than sign), > de maior do que), + (sinal de adição), = (símbolo de igualdade),; (ponto e vírgula),, (vírgula), (ponto de interrogação), \* (asterisco), espaços à esquerda e caracteres de controle (ASCII 00 a ASCII 31). Para obter informações relacionadas, consulte o tópico "propriedade de nome de usuário" na ajuda do DAO.

### <a name="remarks"></a>Comentários

O nome de usuário padrão que você define aplica-se a novos espaços de trabalho criados após a chamada. Ao criar espaços de trabalho subsequentes, você não precisa especificar um nome de usuário na chamada de [criação](#create) .

Para usar essa função de membro:

1. Construa um `CDaoWorkspace` objeto, mas não chame `Create` .

1. Chame `SetDefaultUser` e, se desejar, [SetDefaultPassword](#setdefaultpassword).

1. Chame `Create` este objeto de espaço de trabalho ou os subsequentes, sem especificar um nome de usuário.

Por padrão, a propriedade DefaultUser é definida como "admin" e a propriedade DefaultPassword é definida como uma cadeia de caracteres vazia ("").

Para obter informações relacionadas, consulte os tópicos "Propriedade DefaultUser" e "DefaultPassword Property" na ajuda do DAO.

## <a name="cdaoworkspacesetinipath"></a><a name="setinipath"></a> CDaoWorkspace::SetIniPath

Chame essa função de membro para especificar o local das configurações do registro do Windows para o mecanismo de banco de dados do Microsoft Jet.

```
static void PASCAL SetIniPath(LPCTSTR lpszRegistrySubKey);
```

### <a name="parameters"></a>parâmetros

*lpszRegistrySubkey*<br/>
Uma cadeia de caracteres que contém o nome de uma subchave do registro do Windows para o local das configurações ou dos parâmetros do mecanismo de banco de dados do Microsoft Jet necessários para bancos dos dados ISAM instaláveis.

### <a name="remarks"></a>Comentários

Chame `SetIniPath` somente se precisar especificar configurações especiais. Para obter mais informações, consulte o tópico "Propriedade IniPath" na ajuda do DAO.

> [!NOTE]
> Chame `SetIniPath` durante a instalação do aplicativo, não quando o aplicativo é executado. `SetIniPath` deve ser chamado antes de abrir quaisquer espaços de trabalho, bancos de dados ou conjuntos de registros; caso contrário, o MFC lançará uma exceção.

Você pode usar esse mecanismo para configurar o mecanismo de banco de dados com as configurações de registro fornecidas pelo usuário. O escopo deste atributo é limitado ao seu aplicativo e não pode ser alterado sem reiniciar o aplicativo.

## <a name="cdaoworkspacesetisolateodbctrans"></a><a name="setisolateodbctrans"></a> CDaoWorkspace::SetIsolateODBCTrans

Chame essa função de membro para definir o valor da propriedade IsolateODBCTrans do DAO para o espaço de trabalho.

```cpp
void SetIsolateODBCTrans(BOOL bIsolateODBCTrans);
```

### <a name="parameters"></a>parâmetros

*bIsolateODBCTrans*<br/>
Passe TRUE se desejar começar a isolar as transações ODBC. Passe FALSE se desejar parar de isolar as transações ODBC.

### <a name="remarks"></a>Comentários

Em algumas situações, talvez seja necessário ter várias transações simultâneas pendentes no mesmo banco de dados ODBC. Para fazer isso, você precisa abrir um espaço de trabalho separado para cada transação. Embora cada espaço de trabalho possa ter sua própria conexão ODBC com o banco de dados, isso reduz o desempenho do sistema. Como o isolamento da transação normalmente não é necessário, as conexões ODBC de vários objetos de espaço de trabalho abertos pelo mesmo usuário são compartilhadas por padrão.

Alguns servidores ODBC, como Microsoft SQL Server, não permitem transações simultâneas em uma única conexão. Se você precisar ter mais de uma transação de cada vez pendentes em relação a esse banco de dados, defina a propriedade IsolateODBCTrans como TRUE em cada espaço de trabalho assim que abri-la. Isso força uma conexão ODBC separada para cada espaço de trabalho.

## <a name="cdaoworkspacesetlogintimeout"></a><a name="setlogintimeout"></a> CDaoWorkspace::SetLoginTimeout

Chame essa função de membro para definir o valor da Propriedade do DAO LoginTimeout para o espaço de trabalho.

```
static void PASCAL SetLoginTimeout(short nSeconds);
```

### <a name="parameters"></a>parâmetros

*nSeconds*<br/>
O número de segundos antes de ocorrer um erro quando você tenta fazer logon em um banco de dados ODBC.

### <a name="remarks"></a>Comentários

Esse valor representa o número de segundos antes de ocorrer um erro quando você tenta fazer logon em um banco de dados ODBC. A configuração padrão de LoginTimeout é de 20 segundos. Quando LoginTimeout é definido como 0, nenhum tempo limite ocorre e a comunicação com a fonte de dados pode parar de responder.

Quando você está tentando fazer logon em um banco de dados ODBC, como Microsoft SQL Server, a conexão pode falhar como resultado de erros de rede ou porque o servidor não está em execução. Em vez de esperar pelo padrão de 20 segundos para se conectar, você pode especificar quanto tempo o mecanismo de banco de dados aguarda antes de gerar um erro. O logon no servidor ocorre implicitamente como parte de vários eventos diferentes, como a execução de uma consulta em um banco de dados de servidor externo. O valor de tempo limite é determinado pela configuração atual da Propriedade LoginTimeout.

Para obter informações relacionadas, consulte o tópico "Propriedade LoginTimeout" na ajuda do DAO.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
