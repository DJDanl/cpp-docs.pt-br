---
title: Classe COleObjectFactory | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleObjectFactory
dev_langs:
- C++
helpviewer_keywords:
- OLE, class factory
- OLE class factory
- COleObjectFactory class
- objects [C++], creating OLE
- OLE objects
- object creation, OLE objects
- class factories, COleObjectFactory class
- OLE objects, creating
ms.assetid: ab179c1e-4af2-44aa-a576-37c48149b427
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 643d17ccdefb60b561e7e5488753a6dbf778c69f
ms.lasthandoff: 02/25/2017

---
# <a name="coleobjectfactory-class"></a>Classe COleObjectFactory
Implementa o OLE classe factory, que cria os objetos OLE, como servidores, objetos de automação e documentos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleObjectFactory : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::COleObjectFactory](#coleobjectfactory)|Constrói um objeto `COleObjectFactory`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::GetClassID](#getclassid)|Retorna a OLE ID dos objetos que cria esta fábrica de classe.|  
|[COleObjectFactory::IsLicenseValid](#islicensevalid)|Determina se a licença do controle é válida.|  
|[COleObjectFactory::IsRegistered](#isregistered)|Indica se a fábrica do objeto é registrada com as DLLs do sistema OLE.|  
|[COleObjectFactory](#register)|Registra as DLLs do sistema OLE essa fábrica do objeto.|  
|[COleObjectFactory::RegisterAll](#registerall)|Registra todas as fábricas de objeto do aplicativo com DLLs do sistema OLE.|  
|[COleObjectFactory:: Revoke](#revoke)|Revoga o registro da fábrica de objetos com DLLs do sistema OLE.|  
|[COleObjectFactory::RevokeAll](#revokeall)|Revoga registros às fábricas de objeto do aplicativo com as DLLs do sistema OLE.|  
|[COleObjectFactory:: UnregisterAll](#unregisterall)|Cancela o registro de todas as fábricas de objeto do aplicativo.|  
|[COleObjectFactory::UpdateRegistry](#updateregistry)|Registra essa fábrica de objeto com o registro do sistema OLE.|  
|[COleObjectFactory::UpdateRegistryAll](#updateregistryall)|Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::GetLicenseKey](#getlicensekey)|Solicita uma chave exclusiva da DLL do controle.|  
|[COleObjectFactory::OnCreateObject](#oncreateobject)|Chamado pela estrutura para criar um novo objeto do tipo dessa fábrica.|  
|[COleObjectFactory::VerifyLicenseKey](#verifylicensekey)|Verifica se a chave inserida no controle corresponde a chave inserida no contêiner.|  
|[COleObjectFactory::VerifyUserLicense](#verifyuserlicense)|Verifica se o controle é licenciado para uso em tempo de design.|  
  
## <a name="remarks"></a>Comentários  
 O `COleObjectFactory` classe tem funções de membro para executar as seguintes funções:  
  
-   Gerenciando o registro de objetos.  
  
-   Atualizando o registro do sistema OLE, bem como o registro de tempo de execução que informa OLE que os objetos estão em execução e pronto para receber mensagens.  
  
-   Impor o licenciamento, limitando o uso do controle para os desenvolvedores licenciados em tempo de design e aplicativos licenciados em tempo de execução.  
  
-   Registrar fábricas de objeto de controle com o registro do sistema OLE.  
  
 Para obter mais informações sobre a criação de objeto, consulte os artigos [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md) e [objetos de dados e fontes de dados: criação e destruição](../../mfc/data-objects-and-data-sources-creation-and-destruction.md). Para obter mais informações sobre o registro, consulte o artigo [registro](../../mfc/registration.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleObjectFactory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="a-namecoleobjectfactorya--coleobjectfactorycoleobjectfactory"></a><a name="coleobjectfactory"></a>COleObjectFactory::COleObjectFactory  
 Constrói uma `COleObjectFactory` objeto, inicializa-o como uma fábrica do objeto registrado e o adiciona à lista de fábricas.  
  
```  
COleObjectFactory(
    REFCLSID clsid,  
    CRuntimeClass* pRuntimeClass,  
    BOOL bMultiInstance,  
    LPCTSTR lpszProgID);

 
COleObjectFactory(
    REFCLSID clsid,  
    CRuntimeClass* pRuntimeClass,  
    BOOL bMultiInstance,  
    int nFlags,  
    LPCTSTR lpszProgID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 Referência à ID de classe OLE essa fábrica de objeto representa.  
  
 `pRuntimeClass`  
 Ponteiro para a classe de tempo de execução dos objetos C++ que pode criar essa fábrica.  
  
 `bMultiInstance`  
 Indica se uma única instância do aplicativo pode suportar várias instâncias. Se **TRUE**, várias instâncias do aplicativo são iniciadas para cada solicitação criar um objeto.  
  
 `nFlags`  
 Contém um ou mais dos sinalizadores a seguir:  
  
- **afxRegDefault** define o modelo de threading para ThreadingModel = Apartment.  
  
- **afxRegInsertable** permite que o controle apareça o **Inserir objeto** caixa de diálogo para objetos OLE.  
  
- `afxRegApartmentThreading`Define o modelo de threading no registro para ThreadingModel = Apartment.  
  
- **afxRegFreeThreading** define o modelo de threading no registro para ThreadingModel = gratuito.  
  
     Você pode combinar os dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` para definir ThreadingModel = ambos. Consulte [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre o registro de modelo de threading.  
  
 `lpszProgID`  
 Ponteiro para uma cadeia de caracteres que contém um identificador de programa textual, como "Microsoft Excel".  
  
### <a name="remarks"></a>Comentários  
 Para usar o objeto, no entanto, você deve registrá-lo.  
  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetclassida--coleobjectfactorygetclassid"></a><a name="getclassid"></a>COleObjectFactory::GetClassID  
 Retorna uma referência à ID de classe OLE representa essa fábrica.  
  
```  
REFCLSID GetClassID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Referência à ID de classe OLE esta fábrica representa.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetlicensekeya--coleobjectfactorygetlicensekey"></a><a name="getlicensekey"></a>COleObjectFactory::GetLicenseKey  
 Solicita uma chave de licença exclusiva da DLL do controle e o armazena no `BSTR` apontada por `pbstrKey`.  
  
```  
virtual BOOL GetLicenseKey(
    DWORD dwReserved,  
    BSTR* pbstrKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwReserved`  
 Reservado para uso futuro.  
  
 `pbstrKey`  
 Ponteiro para uma `BSTR` que armazenará a chave de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres de chave de licença não é **nulo**; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função retorna 0 e armazena nada a `BSTR`. Se você usar MFC ActiveX ControlWizard para criar o projeto, ControlWizard fornece uma substituição que recupera a chave de licença do controle.  
  
##  <a name="a-nameislicensevalida--coleobjectfactoryislicensevalid"></a><a name="islicensevalid"></a>COleObjectFactory::IsLicenseValid  
 Determina se a licença do controle é válida.  
  
```  
BOOL IsLicenseValid();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se successul; Caso contrário, false.  
  
##  <a name="a-nameisregistereda--coleobjectfactoryisregistered"></a><a name="isregistered"></a>COleObjectFactory::IsRegistered  
 Retorna um valor diferente de zero se a fábrica for registrada com DLLs do sistema OLE.  
  
```  
virtual BOOL IsRegistered() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica for registrada; Caso contrário, 0.  
  
##  <a name="a-nameoncreateobjecta--coleobjectfactoryoncreateobject"></a><a name="oncreateobject"></a>COleObjectFactory::OnCreateObject  
 Chamado pela estrutura para criar um novo objeto.  
  
```  
virtual CCmdTarget* OnCreateObject();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto criado. Ele pode lançar uma exceção de memória se falhar.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para criar o objeto de algo diferente de [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) passado para o construtor.  
  
##  <a name="a-nameregistera--coleobjectfactoryregister"></a><a name="register"></a>COleObjectFactory  
 Registra as DLLs do sistema OLE essa fábrica do objeto.  
  
```  
virtual BOOL Register();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica for registrada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="a-nameregisteralla--coleobjectfactoryregisterall"></a><a name="registerall"></a>COleObjectFactory::RegisterAll  
 Registra todas as fábricas de objeto do aplicativo com as DLLs do sistema OLE.  
  
```  
static BOOL PASCAL RegisterAll();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as fábricas estiverem registradas com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="a-namerevokea--coleobjectfactoryrevoke"></a><a name="revoke"></a>COleObjectFactory:: Revoke  
 Revoga o registro da fábrica de objetos com DLLs do sistema OLE.  
  
```  
void Revoke();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função automaticamente antes que o aplicativo é encerrado. Se necessário, chamá-lo de uma substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).  
  
##  <a name="a-namerevokealla--coleobjectfactoryrevokeall"></a><a name="revokeall"></a>COleObjectFactory::RevokeAll  
 Revoga todos os registros de fábricas de objeto do aplicativo com as DLLs do sistema OLE.  
  
```  
static void PASCAL RevokeAll();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função automaticamente antes que o aplicativo é encerrado. Se necessário, chamá-lo de uma substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).  
  
##  <a name="a-nameunregisteralla--coleobjectfactoryunregisterall"></a><a name="unregisterall"></a>COleObjectFactory:: UnregisterAll  
 Cancela o registro de todas as fábricas de objeto do aplicativo.  
  
```  
static BOOL PASCAL UnregisterAll();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se for bem-sucedida; Caso contrário, FALSE.  
  
##  <a name="a-nameupdateregistrya--coleobjectfactoryupdateregistry"></a><a name="updateregistry"></a>COleObjectFactory::UpdateRegistry  
 Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.  
  
```  
void UpdateRegistry(LPCTSTR lpszProgID = NULL);  
virtual BOOL UpdateRegistry(BOOL bRegister);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProgID`  
 Ponteiro para uma cadeia de caracteres que contém o identificador de programa legíveis, como "Excel.Document.5".  
  
 `bRegister`  
 Determina se a fábrica do objeto da classe de controle deve ser registrado.  
  
### <a name="remarks"></a>Comentários  
 Execute as discussões breves das duas formas para esta função:  
  
- **UpdateRegistry (** `lpszProgID` **)** registra essa fábrica de objeto com o registro do sistema OLE. Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
- **UpdateRegistry (** `bRegister` **)** esse formulário da função é substituível. Se `bRegister` é **TRUE**, essa função registra a classe de controle com o registro do sistema. Caso contrário, ele cancela o registro da classe.  
  
     Se você usar MFC ActiveX ControlWizard para criar o projeto, ControlWizard fornece uma substituição para essa função virtual pura.  
  
##  <a name="a-nameupdateregistryalla--coleobjectfactoryupdateregistryall"></a><a name="updateregistryall"></a>COleObjectFactory::UpdateRegistryAll  
 Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.  
  
```  
static BOOL PASCAL UpdateRegistryAll(BOOL bRegister = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegister`  
 Determina se a fábrica do objeto da classe de controle deve ser registrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as fábricas são atualizadas com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="a-nameverifylicensekeya--coleobjectfactoryverifylicensekey"></a><a name="verifylicensekey"></a>COleObjectFactory::VerifyLicenseKey  
 Verifica se o contêiner é licenciado para usar o controle OLE.  
  
```  
virtual BOOL VerifyLicenseKey(BSTR bstrKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrKey`  
 Um `BSTR` armazenar a versão do contêiner da cadeia de caracteres de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a licença de tempo de execução é válida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de versão padrão [GetLicenseKey](#getlicensekey) para obter uma cópia do controle da cadeia de caracteres de licença e o compara com a cadeia de caracteres em `bstrKey`. Se duas cadeias de caracteres correspondem, a função retorna um valor diferente de zero. Caso contrário, retornará 0.  
  
 Você pode substituir essa função para fornecer verificação personalizada da licença.  
  
 A função [VerifyUserLicense](#verifyuserlicense) verifica a licença de tempo de design.  
  
##  <a name="a-nameverifyuserlicensea--coleobjectfactoryverifyuserlicense"></a><a name="verifyuserlicense"></a>COleObjectFactory::VerifyUserLicense  
 Verifica a licença de tempo de design para o controle OLE.  
  
```  
virtual BOOL VerifyUserLicense();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a licença de tempo de design é válida. Caso contrário, 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)

