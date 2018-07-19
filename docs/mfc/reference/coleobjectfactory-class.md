---
title: Classe COleObjectFactory | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleObjectFactory
- AFXDISP/COleObjectFactory
- AFXDISP/COleObjectFactory::COleObjectFactory
- AFXDISP/COleObjectFactory::GetClassID
- AFXDISP/COleObjectFactory::IsLicenseValid
- AFXDISP/COleObjectFactory::IsRegistered
- AFXDISP/COleObjectFactory::Register
- AFXDISP/COleObjectFactory::RegisterAll
- AFXDISP/COleObjectFactory::Revoke
- AFXDISP/COleObjectFactory::RevokeAll
- AFXDISP/COleObjectFactory::UnregisterAll
- AFXDISP/COleObjectFactory::UpdateRegistry
- AFXDISP/COleObjectFactory::UpdateRegistryAll
- AFXDISP/COleObjectFactory::GetLicenseKey
- AFXDISP/COleObjectFactory::OnCreateObject
- AFXDISP/COleObjectFactory::VerifyLicenseKey
- AFXDISP/COleObjectFactory::VerifyUserLicense
dev_langs:
- C++
helpviewer_keywords:
- COleObjectFactory [MFC], COleObjectFactory
- COleObjectFactory [MFC], GetClassID
- COleObjectFactory [MFC], IsLicenseValid
- COleObjectFactory [MFC], IsRegistered
- COleObjectFactory [MFC], Register
- COleObjectFactory [MFC], RegisterAll
- COleObjectFactory [MFC], Revoke
- COleObjectFactory [MFC], RevokeAll
- COleObjectFactory [MFC], UnregisterAll
- COleObjectFactory [MFC], UpdateRegistry
- COleObjectFactory [MFC], UpdateRegistryAll
- COleObjectFactory [MFC], GetLicenseKey
- COleObjectFactory [MFC], OnCreateObject
- COleObjectFactory [MFC], VerifyLicenseKey
- COleObjectFactory [MFC], VerifyUserLicense
ms.assetid: ab179c1e-4af2-44aa-a576-37c48149b427
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4d2ac698466709931259f1df28d6c75aa38b30f2
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37850700"
---
# <a name="coleobjectfactory-class"></a>Classe COleObjectFactory
Implementa a OLE classe factory, que cria objetos OLE, como servidores, objetos de automação e documentos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleObjectFactory : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::COleObjectFactory](#coleobjectfactory)|Constrói um objeto `COleObjectFactory`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::GetClassID](#getclassid)|Retorna a OLE a ID dos objetos que cria esta fábrica de classe.|  
|[COleObjectFactory::IsLicenseValid](#islicensevalid)|Determina se a licença do controle é válida.|  
|[COleObjectFactory::IsRegistered](#isregistered)|Indica se a fábrica do objeto está registrada com as DLLs do sistema OLE.|  
|[COleObjectFactory](#register)|Registra a fábrica de objeto com as DLLs do sistema OLE.|  
|[COleObjectFactory::RegisterAll](#registerall)|Registra todas as fábricas de objeto do aplicativo com DLLs do sistema OLE.|  
|[COleObjectFactory:: Revoke](#revoke)|Revoga o registro desta fábrica objeto com as DLLs do sistema OLE.|  
|[COleObjectFactory::RevokeAll](#revokeall)|Revoga os registros dos fábricas de objeto do aplicativo com as DLLs do sistema OLE.|  
|[COleObjectFactory:: UnregisterAll](#unregisterall)|Cancela o registro de todas as fábricas de objeto do aplicativo.|  
|[COleObjectFactory::UpdateRegistry](#updateregistry)|Registra essa fábrica de objeto com o registro do sistema OLE.|  
|[COleObjectFactory::UpdateRegistryAll](#updateregistryall)|Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::GetLicenseKey](#getlicensekey)|Solicita uma chave exclusiva de DLL do controle.|  
|[COleObjectFactory::OnCreateObject](#oncreateobject)|Chamado pelo framework para criar um novo objeto do tipo dessa fábrica.|  
|[COleObjectFactory::VerifyLicenseKey](#verifylicensekey)|Verifica se a chave inserida no controle corresponde à chave inserida no contêiner.|  
|[COleObjectFactory::VerifyUserLicense](#verifyuserlicense)|Verifica se o controle é licenciado para uso de tempo de design.|  
  
## <a name="remarks"></a>Comentários  
 O `COleObjectFactory` classe tem funções de membro para executar as seguintes funções:  
  
-   Gerenciando o registro de objetos.  
  
-   Atualizando o registro do sistema OLE, bem como o registro do tempo de execução que informa ao OLE que os objetos estão em execução e pronto para receber mensagens.  
  
-   Impor o licenciamento, limitando o uso do controle aos desenvolvedores licenciados em tempo de design e aos aplicativos licenciados em tempo de execução.  
  
-   Registrar fábricas de objeto de controle com o registro do sistema OLE.  
  
 Para obter mais informações sobre a criação de objeto, consulte os artigos [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md) e [objetos de dados e fontes de dados: criação e destruição](../../mfc/data-objects-and-data-sources-creation-and-destruction.md). Para obter mais informações sobre o registro, consulte o artigo [registro](../../mfc/registration.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleObjectFactory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="coleobjectfactory"></a>  COleObjectFactory::COleObjectFactory  
 Constrói um `COleObjectFactory` objeto, inicializa-o como uma fábrica de objeto registrado e o adiciona à lista de fábricas.  
  
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
 *clsid*  
 Referência à ID de classe OLE esta fábrica de objeto representa.  
  
 *pRuntimeClass*  
 Ponteiro para a classe de tempo de execução dos objetos C++ que esta fábrica pode criar.  
  
 *bMultiInstance*  
 Indica se uma única instância do aplicativo pode dar suporte a várias instâncias. Se for TRUE, várias instâncias do aplicativo são iniciadas para cada solicitação criar um objeto.  
  
 *nFlags*  
 Contém um ou mais dos seguintes sinalizadores:  
  
- `afxRegDefault` Define o modelo de threading para ThreadingModel = Apartment.  
  
- `afxRegInsertable` Permite que o controle apareça na **Inserir objeto** caixa de diálogo para objetos OLE.  
  
- `afxRegApartmentThreading` Define o modelo de threading no registro para ThreadingModel = Apartment.  
  
- `afxRegFreeThreading` Define o modelo de threading no registro para ThreadingModel = gratuito.  
  
     Você pode combinar os dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` definir ThreadingModel = Both. Ver [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.  
  
 *lpszProgID*  
 Ponteiro para uma cadeia de caracteres que contém um identificador de programa textual, como "Microsoft Excel".  
  
### <a name="remarks"></a>Comentários  
 Para usar o objeto, no entanto, você deve registrá-lo.  
  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no SDK do Windows.  
  
##  <a name="getclassid"></a>  COleObjectFactory::GetClassID  
 Retorna uma referência para a ID de classe OLE representa essa fábrica.  
  
```  
REFCLSID GetClassID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Representa a referência à ID de classe OLE essa fábrica.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no SDK do Windows.  
  
##  <a name="getlicensekey"></a>  COleObjectFactory::GetLicenseKey  
 Solicita uma chave de licença exclusiva do DLL do controle e o armazena em BSTR apontado por *pbstrKey*.  
  
```  
virtual BOOL GetLicenseKey(
    DWORD dwReserved,  
    BSTR* pbstrKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwReserved*  
 Reservado para uso futuro.  
  
 *pbstrKey*  
 Ponteiro para um BSTR que armazenará a chave de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres de chave de licença não for nula. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função retorna 0 e não armazena nada em BSTR. Se você usar ControlWizard de ActiveX do MFC para criar seu projeto, ControlWizard fornece uma substituição que recupera a chave de licença do controle.  
  
##  <a name="islicensevalid"></a>  COleObjectFactory::IsLicenseValid  
 Determina se a licença do controle é válida.  
  
```  
BOOL IsLicenseValid();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se successul; Caso contrário, false.  
  
##  <a name="isregistered"></a>  COleObjectFactory::IsRegistered  
 Retorna um valor diferente de zero se a fábrica for registrada com as DLLs do sistema OLE.  
  
```  
virtual BOOL IsRegistered() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica for registrada; Caso contrário, 0.  
  
##  <a name="oncreateobject"></a>  COleObjectFactory::OnCreateObject  
 Chamado pelo framework para criar um novo objeto.  
  
```  
virtual CCmdTarget* OnCreateObject();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto criado. Se ele falhar, ele pode lançar uma exceção de memória.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para criar o objeto de algo diferente de [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) passado para o construtor.  
  
##  <a name="register"></a>  COleObjectFactory  
 Registra a fábrica de objeto com as DLLs do sistema OLE.  
  
```  
virtual BOOL Register();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica for registrada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="registerall"></a>  COleObjectFactory::RegisterAll  
 Registra todas as fábricas de objeto do aplicativo com as DLLs do sistema OLE.  
  
```  
static BOOL PASCAL RegisterAll();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o fábricas são registradas com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="revoke"></a>  COleObjectFactory:: Revoke  
 Revoga o registro desta fábrica objeto com as DLLs do sistema OLE.  
  
```  
void Revoke();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função automaticamente antes que o aplicativo seja encerrado. Se necessário, chamá-lo da substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).  
  
##  <a name="revokeall"></a>  COleObjectFactory::RevokeAll  
 Revoga todos os registros dos fábricas de objeto do aplicativo com as DLLs do sistema OLE.  
  
```  
static void PASCAL RevokeAll();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função automaticamente antes que o aplicativo seja encerrado. Se necessário, chamá-lo da substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).  
  
##  <a name="unregisterall"></a>  COleObjectFactory:: UnregisterAll  
 Cancela o registro de todas as fábricas de objeto do aplicativo.  
  
```  
static BOOL PASCAL UnregisterAll();
```  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se bem-sucedido; Caso contrário, FALSE.  
  
##  <a name="updateregistry"></a>  COleObjectFactory::UpdateRegistry  
 Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.  
  
```  
void UpdateRegistry(LPCTSTR lpszProgID = NULL);  
virtual BOOL UpdateRegistry(BOOL bRegister);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszProgID*  
 Ponteiro para uma cadeia de caracteres que contém o identificador de programa legível por humanos, como "Excel.Document.5".  
  
 *bRegistre-se participar*  
 Determina se a fábrica do objeto da classe de controle deve ser registrado.  
  
### <a name="remarks"></a>Comentários  
 Execute as discussões breves das duas formas para esta função:  
  
- **UpdateRegistry (** `lpszProgID` **)** registra essa fábrica de objeto com o registro do sistema OLE. Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
- **UpdateRegistry (** `bRegister` **)** essa forma da função é substituível. Se *bRegistre-se participar* for TRUE, este registradores de função que o controle de classe com o registro do sistema. Caso contrário, ele cancela o registro da classe.  
  
     Se você usar ControlWizard de ActiveX do MFC para criar seu projeto, ControlWizard fornece uma substituição para essa função virtual pura.  
  
##  <a name="updateregistryall"></a>  COleObjectFactory::UpdateRegistryAll  
 Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.  
  
```  
static BOOL PASCAL UpdateRegistryAll(BOOL bRegister = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bRegistre-se participar*  
 Determina se a fábrica do objeto da classe de controle deve ser registrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as fábricas são atualizadas com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="verifylicensekey"></a>  COleObjectFactory::VerifyLicenseKey  
 Verifica se o contêiner é licenciado para usar o controle OLE.  
  
```  
virtual BOOL VerifyLicenseKey(BSTR bstrKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bstrKey*  
 Um BSTR armazenar a versão do contêiner da cadeia de caracteres de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a licença de tempo de execução é válida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de versão padrão [GetLicenseKey](#getlicensekey) para obter uma cópia do controle da cadeia de caracteres de licença e o compara com a cadeia de caracteres na *bstrKey*. Se duas cadeias de caracteres corresponderem, a função retorna um valor diferente de zero; Caso contrário, retornará 0.  
  
 Você pode substituir essa função para fornecer verificação personalizada da licença.  
  
 A função [VerifyUserLicense](#verifyuserlicense) verifica a licença de tempo de design.  
  
##  <a name="verifyuserlicense"></a>  COleObjectFactory::VerifyUserLicense  
 Verifica a licença de tempo de design para o controle OLE.  
  
```  
virtual BOOL VerifyUserLicense();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a licença de tempo de design é válida. Caso contrário, 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
