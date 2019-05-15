---
title: 'TN054: Chamando DAO diretamente usando Classes DAO MFC'
ms.date: 06/28/2018
helpviewer_keywords:
- MFC, DAO and
- passwords [MFC], calling DAO
- security [MFC], DAO
- DAO (Data Access Objects), calling directly
- DAO (Data Access Objects), security
- security [MFC]
- TN054
- DAO (Data Access Objects), and MFC
ms.assetid: f7de7d85-8d6c-4426-aa05-2e617c0da957
ms.openlocfilehash: b6aae8929e2840791e8d629378a0ec2261a2cda9
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65610981"
---
# <a name="tn054-calling-dao-directly-while-using-mfc-dao-classes"></a>TN054: Chamando DAO diretamente usando Classes DAO MFC

> [!NOTE]
> Os assistentes e o ambiente do Visual C++ não têm suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO em manutenção de aplicativos existentes.

Ao usar as classes de banco de dados MFC DAO, pode haver situações em que é necessário usar DAO diretamente. Geralmente, isso não será o caso, mas o MFC tenha fornecido alguns mecanismos de auxiliar para facilitar a fazer chamadas DAO diretas simples ao combinar o uso de classes do MFC com chamadas diretas do DAO. DAO direta de fazer chamadas para os métodos de um objeto gerenciado de MFC DAO devem exigir apenas algumas linhas de código. Se você precisa criar e usar objetos DAO *não* gerenciado pelo MFC, você terá que fazer um pouco mais de trabalho, na verdade, chamando `Release` no objeto. Essa observação técnica explica quando você talvez queira chamar DAO diretamente, o que os auxiliares MFC podem fazer para ajudá-lo e como usar as interfaces OLE do DAO. Por fim, essa observação fornece algumas funções de exemplo que mostra como chamar DAO diretamente para recursos de segurança do DAO.

## <a name="when-to-make-direct-dao-calls"></a>Quando fazer chamadas diretas DAO

As situações mais comuns para fazer chamadas DAO diretas ocorrerem quando coleções precisam ser atualizados ou quando você estiver implementando recursos não encapsulados pelo MFC. O recurso mais significativo que não são exposto pelo MFC é segurança. Se você quiser implementar recursos de segurança, você precisará usar os objetos de usuário (s) de DAO e grupo (s) diretamente. Além da segurança, há apenas alguns outros recursos DAO MFC não tem suportados. Isso inclui recursos de replicação de banco de dados e de clonagem de conjunto de registros, bem como algumas adições mais recentes para DAO.

## <a name="a-brief-overview-of-dao-and-mfcs-implementation"></a>Uma breve visão geral da implementação do DAO e do MFC

Encapsulamento do MFC do DAO torna o uso de DAO mais fácil ao manipular muitos dos detalhes para que você não precise se preocupar sobre as pequenas coisas. Isso inclui a inicialização do OLE, criação e gerenciamento dos objetos DAO (especialmente os objetos de coleção), erro de verificação e fornecendo uma interface com rigidez de tipos, mais simples (sem **VARIANT** ou `BSTR` argumentos). Você pode fazer chamadas diretas do DAO e ainda aproveitar esses recursos. Tudo o que seu código deve fazer é chamar `Release` para todos os objetos criados pelo DAO direto chamadas e *não* modificar qualquer um dos ponteiros de interface MFC pode depender de internamente. Por exemplo, não modifique os *m_pDAORecordset* membro de uma abertura `CDaoRecordset` do objeto a menos que você compreenda *todos os* as ramificações internas. Você pode, no entanto, usar o *m_pDAORecordset* interface para chamar DAO diretamente para obter a coleção de campos. Nesse caso, o *m_pDAORecordset* membro não deve ser modificado. Você simplesmente precisa chamar `Release` no objeto de coleção de campos quando tiver terminado com o objeto.

## <a name="description-of-helpers-to-make-dao-calls-easier"></a>Descrição de auxiliares para tornar o DAO chama mais fácil

Os auxiliares fornecidos para tornar mais fácil de chamada de DAO são os mesmos auxiliares que são usados internamente em classes MFC DAO banco de dados. Esses auxiliares são usados para verificar os códigos de retorno ao fazer uma chamada direta do DAO, registro em log a saída de depuração, verificação de erros esperados e lançando exceções apropriadas, se necessário. Há duas funções auxiliares subjacente e quatro macros que são mapeados para um desses dois auxiliares. A explicação melhor seria simplesmente ler o código. Ver **DAO_CHECK**, **DAO_CHECK_ERROR**, **DAO_CHECK_MEM**, e **DAO_TRACE** em AFXDAO. H para ver as macros e ver **AfxDaoCheck** e **AfxDaoTrace** em DAOCORE. CPP.

## <a name="using-the-dao-ole-interfaces"></a>Usando as Interfaces OLE DAO

As interfaces OLE para cada objeto na hierarquia do objeto DAO são definidas no arquivo de cabeçalho DBDAOINT. H, que é encontrado no diretório \Program Files\Microsoft Visual Studio .NET 2003\VC7\include. Essas interfaces fornecem métodos que permitem que você manipule toda a hierarquia DAO.

Para muitos dos métodos em interfaces do DAO, você precisará manipular uma `BSTR` objeto (um prefixo de comprimento de cadeia de caracteres usado na automação OLE). O `BSTR` objeto normalmente é encapsulado dentro de **VARIANT** tipo de dados. A classe do MFC `COleVariant` em si herda as **VARIANT** tipo de dados. Dependendo se você compila seu projeto para ANSI ou Unicode, as interfaces do DAO retornará ANSI ou Unicode `BSTR`s. Duas macros, V_BSTR e V_BSTRT, são úteis para garantir que a interface do DAO obtém o `BSTR` do tipo esperado.

V_BSTR extrairá os *bstrVal* membro de um `COleVariant`. Essa macro é normalmente usada quando você precisa passar o conteúdo de um `COleVariant` para um método de uma interface de DAO. O fragmento de código a seguir mostra as declarações e o uso real para dois métodos da interface do DAO DAOUser que tiram proveito da macro V_BSTR:

```cpp
COleVariant varOldName;
COleVariant varNewName(_T("NewUser"), VT_BSTRT);

// Code to assign pUser to a valid value omitted
DAOUser *pUser = NULL;

// These method declarations were taken from DBDAOINT.H
// STDMETHOD(get_Name) (THIS_ BSTR FAR* pbstr) PURE;
// STDMETHOD(put_Name) (THIS_ BSTR bstr) PURE;

DAO_CHECK(pUser->get_Name(&V_BSTR (&varOldName)));
DAO_CHECK(pUser->put_Name(V_BSTR (&varNewName)));
```

Observe que o `VT_BSTRT` argumento especificado na `COleVariant` construtor acima garante que haverá um ANSI `BSTR` no `COleVariant` se você criar uma versão ANSI do seu aplicativo e a Unicode `BSTR` para obter uma versão Unicode seu aplicativo. Esse é o que espera DAO.

A macro outra, V_BSTRT, extrairá um ANSI ou Unicode *bstrVal* membro `COleVariant` dependendo do tipo de compilação (ANSI ou Unicode). O código a seguir demonstra como extrair o `BSTR` valor de uma `COleVariant` em um `CString`:

```cpp
COleVariant varName(_T("MyName"), VT_BSTRT);
CString str = V_BSTRT(&varName);
```

A macro V_BSTRT, juntamente com outras técnicas para abrir outros tipos que são armazenados em `COleVariant`, é demonstrado no exemplo DAOVIEW. Especificamente, essa conversão é executada no `CCrack::strVARIANT` método. Esse método, sempre que possível, converte o valor de uma `COleVariant` em uma instância de `CString`.

## <a name="simple-example-of-a-direct-call-to-dao"></a>Exemplo simples de uma chamada direta para DAO

Pode haver situações quando for necessário atualizar os objetos de coleção subjacentes do DAO. Normalmente, isso não deve ser necessário, mas esse é um procedimento simple, se for necessário. Um exemplo de quando uma coleção precisar ser atualizada é ao operar em um ambiente multiusuário com vários usuários criando tabledefs novo. Nesse caso, sua coleção tabledefs pode se tornar obsoleta. Para atualizar a coleção, você simplesmente precisa chamar o `Refresh` método do objeto de coleção específica e verificação de erros:

```cpp
DAO_CHECK(pMyDaoDatabase->m_pDAOTableDefs->Refresh());
```

Observe que, no momento, todas as interfaces de objeto de coleção de DAO são detalhes de implementação não documentadas das classes de banco de dados MFC DAO.

## <a name="using-dao-directly-for-dao-security-features"></a>Usando o DAO diretamente para recursos de segurança do DAO

As classes de banco de dados MFC DAO não quebram o recursos de segurança do DAO. Você deve chamar os métodos das interfaces do DAO para usar alguns recursos de segurança do DAO. A função a seguir define o banco de dados do sistema e, em seguida, altera a senha do usuário. Essa função chama três outras funções, que são definidas posteriormente.

```cpp
void ChangeUserPassword()
{
    // Specify path to the Microsoft Access *// system database
    CString strSystemDB =
        _T("c:\\Program Files\\MSOffice\\access\\System.mdw");

    // Set system database before MFC initilizes DAO
    // NOTE: An MFC module uses only one instance
    // of a DAO database engine object. If you have
    // called a DAO object in your application prior
    // to calling the function below, you must call
    // AfxDaoTerm to destroy the existing database
    // engine object. Otherwise, the database engine
    // object already in use will be reused, and setting
    // a system datbase will have no effect.
    //
    // If you have used a DAO object prior to calling
    // this function it is important that DAO be
    // terminated with AfxDaoTerm since an MFC
    // module only gets one copy of the database engine
    // and that engine will be reused if it hasn't been
    // terminated. In other words, if you do not call
    // AfxDaoTerm and there is currently a database
    // initialized, setting the system database will
    // have no effect.
    SetSystemDB(strSystemDB);

    // User name and password manually added
    // by using Microsoft Access
    CString strUserName = _T("NewUser");
    CString strOldPassword = _T("Password");
    CString strNewPassword = _T("NewPassword");

    // Set default user so that MFC will be able
    // to log in by default using the user name and
    // password from the system database
    SetDefaultUser(strUserName, strOldPassword);

    // Change the password. You should be able to
    // call this function from anywhere in your
    // MFC application
    ChangePassword(strUserName, strOldPassword, strNewPassword);

    // ...
}
```

Os próximos quatro exemplos demonstram como:

- Definir o banco de dados do sistema DAO (. Arquivo MDW).

- Defina o usuário padrão e a senha.

- Altere a senha de um usuário.

- Alterar a senha de um. Arquivo MDB.

### <a name="setting-the-system-database"></a>Definindo o banco de dados do sistema

Abaixo está uma função de exemplo para definir o banco de dados do sistema que será usado por um aplicativo. Essa função deve ser chamada antes que quaisquer outras chamadas DAO sejam feitas.

```cpp
// Set the system database that the
// DAO database engine will use

void SetSystemDB(CString& strSystemMDB)
{
    COleVariant varSystemDB(strSystemMDB, VT_BSTRT);

    // Initialize DAO for MFC
    AfxDaoInit();
    DAODBEngine* pDBEngine = AfxDaoGetEngine();

    ASSERT(pDBEngine != NULL);

    // Call put_SystemDB method to set the *// system database for DAO engine
    DAO_CHECK(pDBEngine->put_SystemDB(varSystemDB.bstrVal));
}
```

### <a name="setting-the-default-user-and-password"></a>Definindo o padrão de usuário e senha

Para definir o usuário padrão e a senha para um banco de dados do sistema, use a função a seguir:

```cpp
void SetDefaultUser(CString& strUserName,
    CString& strPassword)
{
    COleVariant varUserName(strUserName, VT_BSTRT);
    COleVariant varPassword(strPassword, VT_BSTRT);

    DAODBEngine* pDBEngine = AfxDaoGetEngine();
    ASSERT(pDBEngine != NULL);

    // Set default user:
    DAO_CHECK(pDBEngine->put_DefaultUser(varUserName.bstrVal));

    // Set default password:
    DAO_CHECK(pDBEngine->put_DefaultPassword(varPassword.bstrVal));
}
```

### <a name="changing-a-users-password"></a>Alterando a senha do usuário

Para alterar a senha do usuário, use a função a seguir:

```cpp
void ChangePassword(CString &strUserName,
    CString &strOldPassword,
    CString &strNewPassword)
{
    // Create (open) a workspace
    CDaoWorkspace wsp;
    CString strWspName = _T("Temp Workspace");

    wsp.Create(strWspName, strUserName, strOldPassword);
    wsp.Append();

    // Determine how many objects there are *// in the Users collection
    short nUserCount;
    short nCurrentUser;
    DAOUser *pUser = NULL;
    DAOUsers *pUsers = NULL;

    // Side-effect is implicit OLE AddRef()
    // on DAOUser object:
    DAO_CHECK(wsp.m_pDAOWorkspace->get_Users(&pUsers));

    // Side-effect is implicit OLE AddRef()
    // on DAOUsers object
    DAO_CHECK(pUsers->getcount(&nUserCount));

    // Traverse through the list of users
    // and change password for the userid
    // used to create/open the workspace
    for(nCurrentUser = 0; nCurrentUser <nUserCount; nCurrentUser++)
    {
        COleVariant varIndex(nCurrentUser, VT_I2);
        COleVariant varName;

        // Retrieve information for user nCurrentUser
        DAO_CHECK(pUsers->get_Item(varIndex, &pUser));

        // Retrieve name for user nCurrentUser
        DAO_CHECK(pUser->get_Name(&V_BSTR(&varName)));

        CString strTemp = V_BSTRT(&varName);

        // If there is a match, change the password
        if (strTemp == strUserName)
        {
            COleVariant varOldPwd(strOldPassword, VT_BSTRT);
            COleVariant varNewPwd(strNewPassword, VT_BSTRT);

            DAO_CHECK(pUser->NewPassword(V_BSTR(&varOldPwd),
                V_BSTR(&varNewPwd)));

            TRACE("\t Password is changed\n");
        }
    }
    // Clean up: decrement the usage count
    // on the OLE objects
    pUser->Release();
    pUsers->Release();
    wsp.Close();
}
```

### <a name="changing-the-password-of-an-mdb-file"></a>Alterando a senha de um. Arquivo MDB

Para alterar a senha de um. MDB de arquivos, use a seguinte função:

```cpp
void SetDBPassword(LPCTSTR pDB,
    LPCTSTR pszOldPassword,
    LPCTSTR pszNewPassword)
{
    CDaoDatabase db;
    CString strConnect(_T(";pwd="));

    // the database must be opened as exclusive
    // to set a password
    db.Open(pDB, TRUE, FALSE, strConnect + pszOldPassword);

    COleVariant NewPassword(pszNewPassword, VT_BSTRT),
                OldPassword(pszOldPassword, VT_BSTRT);

    DAO_CHECK(db.m_pDAODatabase->NewPassword(V_BSTR(&OldPassword),
        V_BSTR(&NewPassword)));

    db.Close();
}
```

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
