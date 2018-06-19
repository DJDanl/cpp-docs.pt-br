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
ms.openlocfilehash: dd68493c9be5eb0bff63504cf49b38b9a2f216d4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33375931"
---
# <a name="coleobjectfactory-class"></a>Classe COleObjectFactory
Implementa a OLE classe factory, que cria objetos OLE, como documentos, objetos de automação e servidores.  
  
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
|[COleObjectFactory::GetClassID](#getclassid)|Retorna a OLE ID dos objetos que cria esta fábrica de classe.|  
|[COleObjectFactory::IsLicenseValid](#islicensevalid)|Determina se a licença do controle é válida.|  
|[COleObjectFactory::IsRegistered](#isregistered)|Indica se a fábrica do objeto está registrada com o sistema OLE DLLs.|  
|[COleObjectFactory](#register)|Registra esta fábrica de objeto com a DLLs do sistema OLE.|  
|[COleObjectFactory::RegisterAll](#registerall)|Registra todas as fábricas de objeto do aplicativo com DLLs do sistema OLE.|  
|[COleObjectFactory:: Revoke](#revoke)|Revoga o registro da fábrica de objetos com a DLLs do sistema OLE.|  
|[COleObjectFactory::RevokeAll](#revokeall)|Revoga os registros de fábricas de objeto do aplicativo com a DLLs do sistema OLE.|  
|[COleObjectFactory:: UnregisterAll](#unregisterall)|Cancela o registro de todas as fábricas de objeto do aplicativo.|  
|[COleObjectFactory::UpdateRegistry](#updateregistry)|Registra a fábrica de objeto com o registro do sistema OLE.|  
|[COleObjectFactory::UpdateRegistryAll](#updateregistryall)|Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleObjectFactory::GetLicenseKey](#getlicensekey)|Solicita uma chave exclusiva de DLL do controle.|  
|[COleObjectFactory::OnCreateObject](#oncreateobject)|Chamado pelo framework para criar um novo objeto do tipo essa fábrica.|  
|[COleObjectFactory::VerifyLicenseKey](#verifylicensekey)|Verifica se a chave inserida no controle corresponde a chave inserida no contêiner.|  
|[COleObjectFactory::VerifyUserLicense](#verifyuserlicense)|Verifica se o controle é licenciado para uso em tempo de design.|  
  
## <a name="remarks"></a>Comentários  
 O `COleObjectFactory` classe possui funções de membro para executar as seguintes funções:  
  
-   Gerenciando o registro de objetos.  
  
-   Atualizando o registro do sistema OLE, bem como o registro de tempo de execução que informa OLE se os objetos que estão em execução e pronto para receber mensagens.  
  
-   Imposição de licenciamento, limitando o uso do controle para desenvolvedores licenciados em tempo de design e aplicativos licenciados em tempo de execução.  
  
-   Registrar fábricas de objeto de controle com o registro do sistema OLE.  
  
 Para obter mais informações sobre a criação de objeto, consulte os artigos [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md) e [objetos de dados e fontes de dados: criação e destruição de](../../mfc/data-objects-and-data-sources-creation-and-destruction.md). Para obter mais informações sobre o registro, consulte o artigo [registro](../../mfc/registration.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleObjectFactory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="coleobjectfactory"></a>  COleObjectFactory::COleObjectFactory  
 Constrói uma `COleObjectFactory` objeto, inicializa como uma fábrica de objeto não registrado e o adiciona à lista de fábricas.  
  
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
 Referência à ID de classe OLE nesta fábrica de objeto representa.  
  
 `pRuntimeClass`  
 Ponteiro para a classe de tempo de execução dos objetos C++ que esta fábrica pode criar.  
  
 `bMultiInstance`  
 Indica se uma única instância do aplicativo pode dar suporte a várias instâncias. Se **TRUE**, várias instâncias do aplicativo são iniciadas para cada solicitação para criar um objeto.  
  
 `nFlags`  
 Contém um ou mais dos sinalizadores a seguir:  
  
- **afxRegDefault** define o modelo de threading para ThreadingModel = Apartment.  
  
- **afxRegInsertable** permite que o controle seja exibido no **Inserir objeto** caixa de diálogo para objetos OLE.  
  
- `afxRegApartmentThreading` Define o modelo de threading no registro para ThreadingModel = Apartment.  
  
- **afxRegFreeThreading** define o modelo de threading no registro para ThreadingModel = livre.  
  
     Você pode combinar dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` para definir ThreadingModel = Both. Consulte [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.  
  
 `lpszProgID`  
 Ponteiro para uma cadeia de caracteres que contém um identificador de programa textual, como "Microsoft Excel".  
  
### <a name="remarks"></a>Comentários  
 Para usar o objeto, no entanto, você deve registrá-lo.  
  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no SDK do Windows.  
  
##  <a name="getclassid"></a>  COleObjectFactory::GetClassID  
 Retorna uma referência à ID de classe OLE representa essa fábrica.  
  
```  
REFCLSID GetClassID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Representa a referência à ID de classe OLE essa fábrica.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no SDK do Windows.  
  
##  <a name="getlicensekey"></a>  COleObjectFactory::GetLicenseKey  
 Solicita uma chave de licença exclusiva de DLL do controle e o armazena no `BSTR` apontada pelo `pbstrKey`.  
  
```  
virtual BOOL GetLicenseKey(
    DWORD dwReserved,  
    BSTR* pbstrKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwReserved`  
 Reservado para uso futuro.  
  
 `pbstrKey`  
 Ponteiro para um `BSTR` que armazenará a chave de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres de chave de licença não for **nulo**; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função retorna 0 e armazena nada a `BSTR`. Se você usar MFC ActiveX ControlWizard para criar seu projeto, ControlWizard fornece uma substituição que recupera a chave de licença do controle.  
  
##  <a name="islicensevalid"></a>  COleObjectFactory::IsLicenseValid  
 Determina se a licença do controle é válida.  
  
```  
BOOL IsLicenseValid();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se successul; Caso contrário, false.  
  
##  <a name="isregistered"></a>  COleObjectFactory::IsRegistered  
 Retorna um valor diferente de zero se a fábrica for registrada com a DLLs do sistema OLE.  
  
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
 Um ponteiro para o objeto criado. Se ele falhar, ela pode lançar uma exceção de memória.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para criar o objeto de algo diferente de [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) transmitido ao construtor.  
  
##  <a name="register"></a>  COleObjectFactory  
 Registra esta fábrica de objeto com a DLLs do sistema OLE.  
  
```  
virtual BOOL Register();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fábrica for registrada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="registerall"></a>  COleObjectFactory::RegisterAll  
 Registra todas as fábricas de objeto do aplicativo com a DLLs do sistema OLE.  
  
```  
static BOOL PASCAL RegisterAll();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as fábricas são registradas com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
##  <a name="revoke"></a>  COleObjectFactory:: Revoke  
 Revoga o registro da fábrica de objetos com a DLLs do sistema OLE.  
  
```  
void Revoke();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função automaticamente antes do encerramento do aplicativo. Se necessário, chamá-lo de uma substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).  
  
##  <a name="revokeall"></a>  COleObjectFactory::RevokeAll  
 Revoga todos os registros de fábricas de objeto do aplicativo com a DLLs do sistema OLE.  
  
```  
static void PASCAL RevokeAll();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função automaticamente antes do encerramento do aplicativo. Se necessário, chamá-lo de uma substituição de [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).  
  
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
 `lpszProgID`  
 Ponteiro para uma cadeia de caracteres que contém o identificador de programa legível, como "Excel.Document.5".  
  
 `bRegister`  
 Determina se a fábrica do objeto da classe de controle é a ser registrado.  
  
### <a name="remarks"></a>Comentários  
 Execute as discussões breves das duas formas para esta função:  
  
- **UpdateRegistry (** `lpszProgID` **)** registra esta fábrica de objeto com o registro do sistema OLE. Esta função geralmente é chamada pelo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) quando o aplicativo é iniciado.  
  
- **UpdateRegistry (** `bRegister` **)** essa forma da função é substituível. Se `bRegister` é **TRUE**, essa função registra a classe de controle com o registro do sistema. Caso contrário, ele cancela o registro de classe.  
  
     Se você usar MFC ActiveX ControlWizard para criar seu projeto, ControlWizard fornece uma substituição para esta função virtual pura.  
  
##  <a name="updateregistryall"></a>  COleObjectFactory::UpdateRegistryAll  
 Registra todas as fábricas de objeto do aplicativo com o registro do sistema OLE.  
  
```  
static BOOL PASCAL UpdateRegistryAll(BOOL bRegister = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegister`  
 Determina se a fábrica do objeto da classe de controle é a ser registrado.  
  
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
 `bstrKey`  
 Um `BSTR` armazenar a versão do contêiner da cadeia de caracteres de licença.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a licença de tempo de execução é válida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de versão padrão [GetLicenseKey](#getlicensekey) para obter uma cópia do controle da cadeia de caracteres de licença e o compara com a cadeia de caracteres em `bstrKey`. Se duas cadeias de caracteres corresponderem, a função retornará um valor diferente de zero. Caso contrário, retornará 0.  
  
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
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
