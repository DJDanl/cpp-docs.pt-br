---
title: "TN054: chamando DAO diretamente usando classes DAO MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.dao"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DAO (Objetos de Acesso a Dados), e MFC"
  - "DAO (Objetos de Acesso a Dados), chamando diretamente"
  - "DAO (Objetos de Acesso a Dados), segurança"
  - "MFC [C++], DAO e"
  - "senhas [C++], chamando DAO"
  - "segurança [MFC]"
  - "segurança [MFC], DAO"
  - "TN054"
ms.assetid: f7de7d85-8d6c-4426-aa05-2e617c0da957
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN054: chamando DAO diretamente usando classes DAO MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A partir do Visual C\+\+ .NET, o ambiente e os assistentes do Visual C\+\+ não dão suporte a DAO \(embora as classes de DAO são incluídas e você ainda pode usar o\).  A Microsoft recomenda que você use [Modelos OLE DB](../Topic/OLE%20DB%20Templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos.  Você só deve usar DAO manter os aplicativos existentes.  
  
 Ao usar as classes da base de dados de MFC DAO, pode haver situações em que é necessário usar diretamente DAO.  Em geral, isso não será os casos, mas o MFC forneceu alguns mecanismos auxiliar para facilitar fazer chamadas diretos de DAO simples quando combinar o uso de MFC classifica com chamadas diretos de DAO.  Fazer chamadas diretos de DAO os métodos de um objeto gerenciado de MFC\- DAO requer apenas algumas linhas de código.  Se você precisar criar e usar objetos de DAO que *não* são gerenciados por MFC, será necessário fazer um pouco mais trabalho realmente chamando **Release** no objeto.  Observe que essa técnica explica como você pode querer chamar diretamente, DAO o que são auxiliares MFC podem fazer para ajudar, e como usar o OLE DAO interfaces.  Finalmente, esta observação fornece algumas funções de exemplo que mostram como chamar DAO diretamente para recursos de segurança de DAO.  
  
## Quando fazer chamadas diretos de DAO  
 As situações mais comuns para fazer chamadas diretos de DAO ocorrem quando as coleções precisam ser atualizadas ou quando você estiver implementando recursos não envolvidos por MFC.  O recurso o mais significativo não expõe por MFC é segurança.  Se você deseja implementar recursos de segurança, você precisará usar os usuários do grupo e DAO objetos diretamente.  Além de segurança, há apenas alguns outros recursos de DAO não suportados por MFC.  Esses incluem recursos de replicação de clonagem e da base de dados do conjunto de registros bem como as adições a DAO posteriores.  
  
## Uma visão geral da implementação de DAO e de MFC  
 O encapsulamento de MFC DAO facilita usando DAO tratando muitos detalhes para que você não precisa se preocupar sobre as coisas pequenas.  Isso inclui a inicialização do OLE, a criação e gerenciamento de objetos de DAO \(principalmente os objetos da coleção de erros\), verificando, e fornecendo uma interface com rigidez, mais simples \(nenhum **VARIANT** ou argumentos de `BSTR` \).  Você pode fazer chamadas diretos de DAO e ainda usufruir desses recursos.  Tudo o que código deve fazer é chamar **Release** para todos os objetos criados por chamadas diretos de DAO e *não* alterar os ponteiros da interface que o MFC pode depender internamente.  Por exemplo, não modifique o membro de **m\_pDAORecordset** de um objeto aberto de `CDaoRecordset` a menos que você compreenda *todas as* ramificações internas.  Você pode, no entanto, usar a interface de **m\_pDAORecordset** para chamar diretamente DAO para obter a coleção de campos.  O membro de **m\_pDAORecordset** não seria alterado nesse caso.  Você só precisa chamar **Versão** no objeto da coleção de campos quando você terminar com o objeto.  
  
## Descrição de auxiliares para facilitar chamadas de DAO  
 Os auxiliares fornecidos para fazer chamar DAO mais fácil são os mesmos auxiliares que são usados internamente nas classes da base de dados de MFC DAO.  Esses são auxiliares usados para verificar os códigos de retorno ao fazer uma chamada direta de DAO, ao registrar a saída de depuração, verificando se há erros esperados, e para lançar exceções apropriadas se necessário.  Há duas funções auxiliares subjacentes e quatro macros que mapeiam para um desses dois auxiliares.  A melhor explicação será lido apenas o código.  Consulte **DAO\_CHECK**, **DAO\_CHECK\_ERROR**, **DAO\_CHECK\_MEM**, e **DAO\_TRACE** em AFXDAO.H para ver as macros e, consulte **AfxDaoCheck** e **AfxDaoTrace** em DAOCORE.CPP.  
  
## Usando as interfaces de DAO OLE  
 As interfaces OLE para cada objeto na hierarquia de objetos de DAO são definidas no arquivo de cabeçalho DBDAOINT.H, que está localizado em \\ arquivos de programas \\ Microsoft Visual Studio .NET. \\ 2003 \\ VC7 inclui o diretório.  Essas interfaces fornecem os métodos que permitem manipular a hierarquia inteira de DAO.  
  
 Para muitos dos métodos nas interfaces de DAO, você precisará manipular um objeto de `BSTR` \(uma cadeia de caracteres comprimento do prefixo usada na automação OLE\).  O objeto de `BSTR` normalmente é encapsulado no tipo de dados de **VARIANT** .  A classe `COleVariant` próprio MFC herda do tipo de dados de **VARIANT** .  Se você criar seu projeto para ANSI ou Unicode, as interfaces de DAO retornarão ANSI ou Unicode `BSTR`S.  Dois macros, **V\_BSTR** e **V\_BSTRT**, são úteis para garantir que a interface de DAO obtém `BSTR` do tipo esperado.  
  
 **V\_BSTR** extrairá o membro de **bstrVal** de `COleVariant`.  Esta macro é normalmente usado quando você precisa passar o conteúdo de `COleVariant` a um método de uma interface de DAO.  O seguinte fragmento de código mostra as declarações e o uso real para dois métodos da interface de DAOUser DAO que se beneficiam de macro de **V\_BSTR** :  
  
```  
COleVariant varOldName;  
COleVariant varNewName( _T("NewUser"), VT_BSTRT );  
  
// Code to assign pUser to a valid value omitted  
DAOUser *pUser = NULL;  
  
// These method declarations were taken from DBDAOINT.H  
// STDMETHOD(get_Name) (THIS_ BSTR FAR* pbstr) PURE;  
// STDMETHOD(put_Name) (THIS_ BSTR bstr) PURE;  
  
DAO_CHECK( pUser->get_Name( &V_BSTR ( &varOldName ) ));  
DAO_CHECK( pUser->put_Name( V_BSTR ( &varNewName ) ));  
```  
  
 Observe que o argumento de `VT_BSTRT` especificado no construtor de `COleVariant` acima garante que haja ANSI `BSTR` em `COleVariant` se você criar uma versão ANSI de seu aplicativo e um `BSTR` Unicode para Unicode uma versão de seu aplicativo.  Isso é o que DAO espera.  
  
 O outro, macro **V\_BSTRT**, extrairá ANSI ou Unicode **bstrVal** o membro de `COleVariant` dependendo do tipo de construção \(ANSI ou Unicode\).  O código a seguir demonstra como extrair o valor de `BSTR` de `COleVariant` em `CString`:  
  
```  
COleVariant varName( _T( "MyName" ), VT_BSTRT );  
CString str = V_BSTRT( &varName );  
```  
  
 A macro de **V\_BSTRT** , junto com outras técnicas abrir outros tipos que são armazenados em `COleVariant`, é demonstrado no exemplo de DAOVIEW.  Especificamente, essa conversão é executada no método de **CCrack::strVARIANT** .  Esse método, sempre que possível, converte o valor de `COleVariant` em uma instância de `CString`.  
  
## Exemplo simples de uma chamada direta a DAO  
 As situações podem ocorrer quando é necessário atualizar os objetos subjacentes da coleção de DAO.  Normalmente, isso não deve ser necessário, mas é um procedimento simples se for necessário.  Um exemplo de quando uma coleção precisa ser atualizado é ao operar em um ambiente multiusuário com vários usuários que criam novos tabledefs.  Nesse caso a sua coleção de tabledefs pode se tornar obsoleto.  Para atualizar a coleção, você precisa apenas de chamar o método de **Atualizar** de objeto específico da coleção e de procura erros:  
  
```  
DAO_CHECK( pMyDaoDatabase->  
    m_pDAOTableDefs->Refresh( ) );  
```  
  
 Observe que atualmente todas as interfaces de objeto da coleção de DAO são detalhes de implementação não documentados das classes da base de dados de MFC DAO.  
  
## Usando DAO diretamente para recursos de segurança de DAO  
 As classes da base de dados de MFC DAO não envolvem recursos de segurança de DAO.  Você deve chamar métodos de interfaces de DAO para usar os recursos de segurança de qualquer DAO.  A função a seguir define o base de dados do sistema e altera a senha do usuário.  Este função chamar outras três funções, que são definidas posteriormente.  
  
```  
void ChangeUserPassword( )  
{  
   // Specify path to the Microsoft Access  
   // system database  
   CString strSystemDB =   
     _T( "c:\\Program Files\\MSOffice\\access\\System.mdw" );  
  
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
   // have no affect.  
  
   SetSystemDB( strSystemDB );  
  
   // User name and password manually added  
   // by using Microsoft Access  
   CString strUserName = _T( "NewUser" );  
   CString strOldPassword = _T( "Password" );  
   CString strNewPassword = _T( "NewPassword" );  
  
   // Set default user so that MFC will be able  
   // to log in by default using the user name and   
   // password from the system database  
   SetDefaultUser( strUserName, strOldPassword );  
  
   // Change the password. You should be able to  
   // call this function from anywhere in your   
   // MFC application  
   ChangePassword( strUserName, strOldPassword,   
                   strNewPassword );  
  
   .  
   .  
   .  
  
}  
```  
  
 Os quatro exemplos seguintes demonstram como:  
  
-   Definir o base de dados do sistema DAO \(arquivo de .MDW\).  
  
-   Definir o usuário e a senha padrão.  
  
-   Alterar a senha de um usuário.  
  
-   Alterar a senha de um arquivo de .MDB.  
  
### Definindo a base de dados do sistema  
 A seguir uma função de exemplo para definir o base de dados do sistema que será usado por um aplicativo.  Essa função deve ser chamada antes que todos os outros chamadas de DAO sejam feitas.  
  
```  
// Set the system database that the   
// DAO database engine will use  
  
void SetSystemDB( CString & strSystemMDB )  
{  
   COleVariant varSystemDB( strSystemMDB, VT_BSTRT );  
  
   // Initialize DAO for MFC  
   AfxDaoInit( );  
   DAODBEngine* pDBEngine = AfxDaoGetEngine( );  
  
   ASSERT( pDBEngine != NULL );  
  
   // Call put_SystemDB method to set the   
   // system database for DAO engine  
   DAO_CHECK( pDBEngine->put_SystemDB( varSystemDB.bstrVal ) );  
}  
```  
  
### Definindo o usuário e a senha padrão  
 Para definir o usuário e a senha padrão para uma base de dados do sistema, use a seguinte função:  
  
```  
void SetDefaultUser(CString & strUserName, CString & strPassword)  
{  
  COleVariant varUserName( strUserName, VT_BSTRT );  
  COleVariant varPassword( strPassword, VT_BSTRT );  
  
  DAODBEngine* pDBEngine = AfxDaoGetEngine( );  
  ASSERT( pDBEngine != NULL );  
  
  // Set default user:  
  DAO_CHECK( pDBEngine->put_DefaultUser( varUserName.bstrVal ) );  
  
  // Set default password:  
  DAO_CHECK( pDBEngine->put_DefaultPassword( varPassword.bstrVal ) );  
}  
```  
  
### Alterando uma senha de usuário  
 Para alterar uma senha de usuário, use a seguinte função:  
  
```  
void ChangePassword( CString &strUserName,   
                     CString &strOldPassword,   
                     CString &strNewPassword )  
{  
   // Create (open) a workspace  
   CDaoWorkspace wsp;  
   CString strWspName = _T( "Temp Workspace" );  
  
   wsp.Create( strWspName, strUserName,  
               strOldPassword );  
   wsp.Append( );  
  
   // Determine how many objects there are  
   // in the Users collection  
   short nUserCount;  
   short nCurrentUser;  
   DAOUser *pUser  = NULL;  
   DAOUsers *pUsers = NULL;  
  
   // Side-effect is implicit OLE AddRef( )   
   // on DAOUser object:  
   DAO_CHECK( wsp.m_pDAOWorkspace->get_Users( &pUsers ) );  
  
   // Side-effect is implicit OLE AddRef( )   
   // on DAOUsers object  
    DAO_CHECK( pUsers->get_Count( &nUserCount ) );  
  
   // Traverse through the list of users   
   // and change password for the userid  
   // used to create/open the workspace  
   for( nCurrentUser = 0; nCurrentUser < nUserCount;  
        nCurrentUser++ )  
   {  
       COleVariant varIndex( nCurrentUser, VT_I2 );  
       COleVariant varName;  
  
       // Retrieve information for user nCurrentUser  
       DAO_CHECK( pUsers->get_Item( varIndex, &pUser ) );  
  
       // Retrieve name for user nCurrentUser  
       DAO_CHECK( pUser->get_Name( &V_BSTR( &varName ) ) );  
  
       CString strTemp = V_BSTRT( &varName );  
  
       // If there is a match, change the password  
       if( strTemp == strUserName )  
       {  
           COleVariant varOldPwd( strOldPassword,   
                                  VT_BSTRT );  
           COleVariant varNewPwd( strNewPassword,   
                                  VT_BSTRT );  
  
           DAO_CHECK( pUser->NewPassword( V_BSTR( &varOldPwd ),  
                      V_BSTR( &varNewPwd ) ) );  
  
           TRACE( "\t Password is changed\n" );  
       }  
   }  
  
   // Clean up: decrement the usage count  
   // on the OLE objects  
   pUser->Release( );  
   pUsers->Release( );  
  
   wsp.Close( );  
}  
```  
  
### Alterando a senha de um Arquivo .MDB  
 Para alterar a senha de um arquivo de .MDB, use a seguinte função:  
  
```  
void SetDBPassword( LPCTSTR pDB, LPCTSTR pszOldPassword, LPCTSTR pszNewPassword )  
{  
   CDaoDatabase db;  
   CString strConnect( _T( ";pwd=" ) );  
  
   // the database must be opened as exclusive  
   // to set a password  
   db.Open( pDB, TRUE, FALSE,   
            strConnect + pszOldPassword );  
  
   COleVariant NewPassword( pszNewPassword, VT_BSTRT ),  
               OldPassword( pszOldPassword, VT_BSTRT );  
  
   DAO_CHECK( db.m_pDAODatabase->NewPassword( V_BSTR( &OldPassword ),  
              V_BSTR( &NewPassword ) ) );  
  
   db.Close();  
}  
```  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)