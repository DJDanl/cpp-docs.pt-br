---
title: 'TN054: Chamando o DAO diretamente ao usar classes do MFC DAO'
ms.date: 09/17/2019
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
ms.openlocfilehash: cef9852f762a64579e11fe4b0d8606bfc9d36709
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71095972"
---
# <a name="tn054-calling-dao-directly-while-using-mfc-dao-classes"></a>TN054: Chamando o DAO diretamente ao usar classes do MFC DAO

> [!NOTE]
> O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. 3,6 é a versão final e é considerada obsoleta. O ambiente C++ visual e os assistentes não dão suporte a DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use [modelos de OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar o DAO na manutenção de aplicativos existentes.

Ao usar as classes de banco de dados do MFC DAO, pode haver situações em que é necessário usar o DAO diretamente. Normalmente, esse não será o caso, mas o MFC forneceu alguns mecanismos auxiliares para facilitar a criação de chamadas DAO diretas ao combinar o uso das classes do MFC com chamadas diretas do DAO. Fazer chamadas DAO diretas para os métodos de um objeto DAO gerenciado pelo MFC deve exigir apenas algumas linhas de código. Se você precisar criar e usar objetos DAO que *não* são gerenciados pelo MFC, será necessário fazer um pouco mais de trabalho chamando `Release` no objeto. Esta nota técnica explica quando você pode querer chamar o DAO diretamente, o que os auxiliares do MFC podem fazer para ajudá-lo e como usar as interfaces OLE do DAO. Por fim, esta observação fornece algumas funções de exemplo que mostram como chamar o DAO diretamente para recursos de segurança do DAO.

## <a name="when-to-make-direct-dao-calls"></a>Quando fazer chamadas diretas do DAO

As situações mais comuns para fazer chamadas do DAO diretas ocorrem quando as coleções precisam ser atualizadas ou quando você está implementando recursos não encapsulados pelo MFC. O recurso mais significativo não exposto pelo MFC é a segurança. Se você quiser implementar recursos de segurança, você precisará usar os objetos DAO e grupos diretamente (s). Além da segurança, há apenas alguns outros recursos do DAO que não têm suporte do MFC. Isso inclui clonagem de conjunto de registros e recursos de replicação de banco de dados, bem como algumas adições mais recentes ao DAO.

## <a name="a-brief-overview-of-dao-and-mfcs-implementation"></a>Uma breve visão geral da implementação do DAO e do MFC

A disposição do DAO do MFC facilita o uso do DAO ao lidar com muitos dos detalhes para que você não precise se preocupar com as pequenas coisas. Isso inclui a inicialização de OLE, a criação e o gerenciamento dos objetos DAO (especialmente os objetos de coleção), a verificação de erros e o fornecimento de uma interface fortemente tipada , mais `BSTR` simples (sem variante ou argumentos). Você pode fazer chamadas DAO diretas e ainda aproveitar esses recursos. Todo o seu código deve fazer é `Release` chamar todos os objetos criados por chamadas diretas do DAO e *não* modificar nenhum dos ponteiros de interface que o MFC possa contar internamente. Por exemplo, não modifique o membro *m_pDAORecordset* de um objeto aberto `CDaoRecordset` , a menos que você compreenda *todas* as ramificações internas. No entanto, você pode usar a interface *m_pDAORecordset* para chamar o DAO diretamente para obter a coleção Fields. Nesse caso, o membro *m_pDAORecordset* não seria modificado. Basta chamar `Release` o objeto de coleção Fields quando terminar com o objeto.

## <a name="description-of-helpers-to-make-dao-calls-easier"></a>Descrição dos auxiliares para facilitar as chamadas do DAO

Os auxiliares fornecidos para tornar a chamada do DAO mais fácil são os mesmos auxiliares que são usados internamente nas classes de banco de dados do MFC DAO. Esses auxiliares são usados para verificar os códigos de retorno ao fazer uma chamada de DAO direta, registrar em log a saída de depuração, verificar se há erros esperados e lançar as exceções apropriadas, se necessário. Há duas funções auxiliares subjacentes e quatro macros que são mapeadas para um desses dois auxiliares. A melhor explicação seria simplesmente ler o código. Consulte **DAO_CHECK**, **DAO_CHECK_ERROR**, **DAO_CHECK_MEM**e **DAO_TRACE** em AFXDAO. H para ver as macros e ver **AfxDaoCheck** e **AfxDaoTrace** em DAOCORE. CPP.

## <a name="using-the-dao-ole-interfaces"></a>Usando as interfaces OLE do DAO

As interfaces OLE para cada objeto na hierarquia de objetos DAO são definidas no arquivo de cabeçalho DBDAOINT. H, que é encontrado no diretório \Program Files\Microsoft Visual Studio .NET 2003 \ VC7\include. Essas interfaces fornecem métodos que permitem manipular toda a hierarquia do DAO.

Para muitos dos métodos nas interfaces DAO, você precisará manipular um `BSTR` objeto (uma cadeia de caracteres com prefixo de comprimento usada na automação OLE). O `BSTR` objeto normalmente é encapsulado dentro do tipo de dados **Variant** . A própria classe `COleVariant` MFC herda do tipo de dados **Variant** . Dependendo se você compilar seu projeto para ANSI ou Unicode, as interfaces DAO retornarão ANSI ou Unicode `BSTR`s. Duas macros, V_BSTR e V_BSTRT, são úteis para garantir que a interface DAO obtenha `BSTR` o do tipo esperado.

V_BSTR irá extrair o membro *bstrVal* de um `COleVariant`. Essa macro normalmente é usada quando você precisa passar o conteúdo de um `COleVariant` para um método de uma interface DAO. O fragmento de código a seguir mostra as declarações e o uso real para dois métodos da interface DAOUser do DAO que aproveitam a macro V_BSTR:

```cpp
COleVariant varOldName;
COleVariant varNewName(_T("NewUser"), VT_BSTRT);

// Code to assign pUser to a valid value omitted DAO 3.6 is the final version and it is considered obsolete.User *pUser = NULL;

// These method declarations were taken from DBDAOINT.H
// STDMETHOD(get_Name) (THIS_ BSTR FAR* pbstr) PURE;
// STDMETHOD(put_Name) (THIS_ BSTR bstr) PURE;
DAO 3.6 is the final version and it is considered obsolete._CHECK(pUser->get_Name(&V_BSTR (&varOldName))); DAO 3.6 is the final version and it is considered obsolete._CHECK(pUser->put_Name(V_BSTR (&varNewName)));
```

Observe que o `VT_BSTRT` argumento especificado `COleVariant` no Construtor acima garante que haverá um ANSI `BSTR` no `COleVariant` se você criar uma versão ANSI do seu aplicativo e um Unicode `BSTR` para uma versão Unicode do seu aplicativo. Isso é o que o DAO espera.

A outra macro, V_BSTRT, extrairá um membro *bstrVal* ANSI ou Unicode de `COleVariant` dependendo do tipo de compilação (ANSI ou Unicode). O código a seguir demonstra como extrair o `BSTR` valor de um `COleVariant` para um `CString`:

```cpp
COleVariant varName(_T("MyName"), VT_BSTRT);
CString str = V_BSTRT(&varName);
```

A macro V_BSTRT, juntamente com outras técnicas para abrir outros tipos armazenados no `COleVariant`, é demonstrada no exemplo DAOVIEW. Especificamente, essa tradução é executada no `CCrack::strVARIANT` método. Esse método, quando possível, traduz o valor de um `COleVariant` em uma instância do. `CString`

## <a name="simple-example-of-a-direct-call-to-dao"></a>Exemplo simples de uma chamada direta para o DAO

Podem surgir situações em que é necessário atualizar os objetos subjacentes da coleção DAO. Normalmente, isso não deve ser necessário, mas é um procedimento simples, se necessário. Um exemplo de quando uma coleção pode precisar ser atualizada é ao operar em um ambiente multiusuário com vários usuários criando novos TableDefs. Nesse caso, sua coleção de tabledefs pode se tornar obsoleta. Para atualizar a coleção, você simplesmente precisa chamar o `Refresh` método do objeto de coleção específico e verificar se há erros:

```cpp DAO 3.6 is the final version and it is considered obsolete._CHECK(pMyDaoDatabase->m_pDAOTableDefs->Refresh());
```

Observe que atualmente todas as interfaces de objeto da coleção DAO são detalhes de implementação não documentados das classes de banco de dados do MFC DAO.

## <a name="using-dao-directly-for-dao-security-features"></a>Usando o DAO diretamente para recursos de segurança do DAO

As classes de banco de dados do MFC DAO não encapsulam os recursos de segurança do DAO. Você deve chamar métodos de interfaces DAO para usar alguns recursos de segurança do DAO. A função a seguir define o banco de dados do sistema e altera a senha do usuário. Essa função chama três outras funções, que são definidas posteriormente.

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

- Defina o banco de dados do sistema DAO (. Arquivo MDW).

- Defina o usuário e a senha padrão.

- Alterar a senha de um usuário.

- Altere a senha de um. Arquivo MDB.

### <a name="setting-the-system-database"></a>Configurando o banco de dados do sistema

Abaixo está uma função de exemplo para definir o banco de dados do sistema que será usado por um aplicativo. Essa função deve ser chamada antes que qualquer outra chamada de DAO seja feita.

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

### <a name="setting-the-default-user-and-password"></a>Definindo o usuário e a senha padrão

Para definir o usuário padrão e a senha para um banco de dados do sistema, use a seguinte função:

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

### <a name="changing-a-users-password"></a>Alterando a senha de um usuário

Para alterar a senha de um usuário, use a seguinte função:

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

Para alterar a senha de um. Arquivo MDB, use a seguinte função:

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
