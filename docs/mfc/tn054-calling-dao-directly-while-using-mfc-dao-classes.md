---
title: 'TN054: Chamando DAO diretamente usando Classes DAO MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.dao
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f060364a8c08a32acae49a0386911486251b0e31
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122445"
---
# <a name="tn054-calling-dao-directly-while-using-mfc-dao-classes"></a>TN054: chamando DAO diretamente usando classes DAO MFC

> [!NOTE]
> Os assistentes e o ambiente do Visual C++ não dão suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO na manutenção de aplicativos existentes.

Ao usar as classes de banco de dados MFC DAO, pode haver situações em que é necessário usar DAO diretamente. Geralmente, isso não será o caso, mas MFC forneceu alguns mecanismos de auxiliar para facilitar a fazer chamadas DAO diretas simples ao combinar o uso das classes MFC com chamadas diretas do DAO. DAO direta de fazer chamadas para os métodos de um objeto gerenciado MFC DAO devem exigir apenas algumas linhas de código. Se você precisa criar e usar objetos DAO *não* gerenciado pelo MFC, você terá que fazer um pouco mais trabalho realmente chamando `Release` no objeto. Esta nota técnica explica quando você quiser chamar DAO diretamente, o que os auxiliares MFC podem fazer para ajudá-lo e como usar as interfaces OLE DAO. Por fim, essa observação fornece algumas funções de exemplo mostra como chamar DAO diretamente para os recursos de segurança DAO.

## <a name="when-to-make-direct-dao-calls"></a>Ao fazer chamadas diretas DAO

As situações mais comuns para fazer a direcionar chamadas DAO ocorrem quando coleções precisam ser atualizado ou quando você estiver implementando recursos não encapsulados pelo MFC. O recurso mais importante que não são exposto pelo MFC é de segurança. Se você quiser implementar recursos de segurança, você precisará usar os objetos DAO usuários e grupos diretamente. Além de segurança, há apenas alguns outros DAO recursos sem suporte pelo MFC. Isso inclui recursos de replicação de clonagem e o banco de dados do conjunto de registros, bem como algumas adições mais recentes para o DAO.

## <a name="a-brief-overview-of-dao-and-mfcs-implementation"></a>Uma breve visão geral da implementação DAO e do MFC

Encapsulamento do MFC de torna DAO usando DAO mais fácil manipular muitos dos detalhes para que você não precisa se preocupar sobre as coisas. Isso inclui a inicialização do OLE, criação e gerenciamento dos objetos DAO (especialmente os objetos da coleção), erro de verificação e fornecer uma interface com rigidez de tipos, mais simples (sem **VARIANT** ou `BSTR` argumentos). Você pode fazer chamadas diretas do DAO e ainda aproveitar esses recursos. Tudo o que seu código deve fazer é chamada `Release` para todos os objetos criados pelo DAO direto chama e *não* modifique qualquer um dos ponteiros de interface MFC pode depender internamente. Por exemplo, não modifique o *m_pDAORecordset* membro de um abertas `CDaoRecordset` do objeto a menos que você compreenda *todas as* as ramificações internas. No entanto, você pode usar o *m_pDAORecordset* interface para chamar DAO diretamente para obter a coleção de campos. Nesse caso o *m_pDAORecordset* membro não deve ser modificado. Você simplesmente precisa chamar `Release` no objeto de coleção de campos quando tiver terminado com o objeto.

## <a name="description-of-helpers-to-make-dao-calls-easier"></a>Descrição de auxiliares para tornar DAO chama mais fácil

Os auxiliares fornecidos para tornar mais fácil ao chamar DAO são os mesmo auxiliares que são usados internamente nas classes MFC DAO banco de dados. Esses auxiliares são usados para verificar os códigos de retorno ao fazer uma chamada direta do DAO, o log de saída de depuração, a verificação de erros esperados e lançando exceções adequadas, se necessário. Há duas funções auxiliares subjacente e quatro macros que mapeiam para um desses dois auxiliares. A explicação melhor seria simplesmente ler o código. Consulte **DAO_CHECK**, **DAO_CHECK_ERROR**, **DAO_CHECK_MEM**, e **DAO_TRACE** em AFXDAO. H para ver as macros e ver **AfxDaoCheck** e **AfxDaoTrace** em DAOCORE. CPP.

## <a name="using-the-dao-ole-interfaces"></a>Usando as Interfaces OLE DAO

As interfaces OLE para cada objeto na hierarquia de objetos DAO são definidas no arquivo de cabeçalho DBDAOINT. H, que está localizado no diretório \Program Files\Microsoft 2003\VC7\include do Visual Studio .NET. Essas interfaces fornecem métodos que permitem que você manipule toda a hierarquia DAO.

Para muitos dos métodos em interfaces DAO, você precisará manipular uma `BSTR` objeto (um prefixo de comprimento da cadeia de caracteres usada na automação OLE). O `BSTR` objeto normalmente é encapsulado dentro de **VARIANT** tipo de dados. A classe do MFC `COleVariant` em si herda o **VARIANT** tipo de dados. Dependendo se você compilar o projeto para ANSI ou Unicode, as interfaces DAO retornará ANSI ou Unicode `BSTR`s. Duas macros, V_BSTR e V_BSTRT, são úteis para garantir que a interface DAO obtém o `BSTR` do tipo esperado.

V_BSTR extrairá o *bstrVal* membro de um `COleVariant`. Esta macro normalmente é usada quando você precisa passar o conteúdo de um `COleVariant` para um método de uma interface DAO. O fragmento de código a seguir mostra as declarações e o uso real para dois métodos da interface DAOUser DAO que aproveitam a macro V_BSTR:

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

Observe que o `VT_BSTRT` argumento especificado no `COleVariant` construtor acima garante que haja um ANSI `BSTR` no `COleVariant` se você criar uma versão de ANSI de seu aplicativo e um Unicode `BSTR` para obter uma versão Unicode seu aplicativo. Este é o que espera DAO.

A macro outros, V_BSTRT, extrairá ANSI ou Unicode *bstrVal* membro `COleVariant` dependendo do tipo de compilação (ANSI ou Unicode). O código a seguir demonstra como extrair o `BSTR` valor de um `COleVariant` em um `CString`:

```cpp
COleVariant varName(_T("MyName"), VT_BSTRT);
CString str = V_BSTRT(&varName);
```

A macro V_BSTRT, juntamente com outras técnicas para abrir outros tipos que são armazenados em `COleVariant`, é demonstrado no exemplo DAOVIEW. Especificamente, essa conversão é executada no `CCrack::strVARIANT` método. Esse método, sempre que possível, converte o valor de um `COleVariant` em uma instância de `CString`.

## <a name="simple-example-of-a-direct-call-to-dao"></a>Exemplo simples de uma chamada direta para DAO

Pode haver situações quando é necessário atualizar os objetos da coleção DAO subjacentes. Normalmente, isso não deve ser necessário, mas é um procedimento simples se for necessário. Um exemplo de quando uma coleção talvez precise ser atualizada é ao operar em um ambiente multiusuário com vários usuários criando tabledefs novo. Nesse caso, sua coleção tabledefs poderão ficar obsoleta. Para atualizar a coleção, você só precisa chamar o `Refresh` método do objeto de coleção específica e verificação de erros:

```cpp
DAO_CHECK(pMyDaoDatabase->m_pDAOTableDefs->Refresh());
```

Observe que no momento todas as interfaces de objeto de coleção DAO são detalhes de implementação não documentadas das classes de banco de dados MFC DAO.

## <a name="using-dao-directly-for-dao-security-features"></a>Usando DAO diretamente para os recursos de segurança DAO

As classes de banco de dados MFC DAO não encapsule os recursos de segurança DAO. Você deve chamar os métodos das interfaces DAO usar alguns recursos de segurança DAO. A função a seguir define o banco de dados do sistema e, em seguida, altera a senha do usuário. Esta função chama três outras funções, que são definidas posteriormente.

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

Abaixo está uma função para definir o banco de dados do sistema que será usado por um aplicativo de exemplo. Essa função deve ser chamada antes de quaisquer outros DAO as chamadas são feitas.

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

### <a name="changing-a-users-password"></a>Alterando a senha do usuário

Para alterar a senha do usuário, use a seguinte função:

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

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
