---
title: Registrando controles OLE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.ole
dev_langs:
- C++
helpviewer_keywords:
- registering OLE controls
- OLE controls [MFC], registering
ms.assetid: 73c45b7f-7dbc-43f5-bd17-dd77c6acec72
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b11e943b8aa6427517ecb5b32ddf6f56442f5d0a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="registering-ole-controls"></a>Registrando controles OLE
Controles OLE, como outros objetos de servidor OLE, podem ser acessados por outros aplicativos com reconhecimento de OLE. Isso é obtido registrando a biblioteca de tipos e a classe do controle.  
  
 As funções a seguir permitem adicionar e remover a classe do controle, páginas de propriedade e biblioteca de tipos do banco de dados de registro do Windows:  
  
### <a name="registering-ole-controls"></a>Registrando controles OLE  
  
|||  
|-|-|  
|[AfxOleRegisterControlClass](#afxoleregistercontrolclass)|Adiciona a classe do controle para o banco de dados de registro.|  
|[AfxOleRegisterPropertyPageClass](#afxoleregisterpropertypageclass)|Adiciona uma página de propriedades de controle para o banco de dados de registro.|  
|[AfxOleRegisterTypeLib](#afxoleregistertypelib)|Adiciona a biblioteca de tipos do controle para o banco de dados de registro.|  
|[AfxOleUnregisterClass](#afxoleunregisterclass)|Remove uma classe de controle ou uma classe de página de propriedade do banco de dados de registro.|  
|[AfxOleUnregisterTypeLib](#afxoleunregistertypelib)|Remove a biblioteca de tipos do controle do banco de dados de registro.|  
  
 `AfxOleRegisterTypeLib`geralmente é chamado na implementação de uma DLL controle de `DllRegisterServer`. Da mesma forma, `AfxOleUnregisterTypeLib` é chamado pelo `DllUnregisterServer`. `AfxOleRegisterControlClass`, `AfxOleRegisterPropertyPageClass`, e `AfxOleUnregisterClass` normalmente são chamados pelo `UpdateRegistry` função membro de página de fábrica ou a propriedade de classe do controle.  
  
##  <a name="afxoleregistercontrolclass"></a>AfxOleRegisterControlClass  
 Registra a classe de controle com o banco de dados de registro do Windows.  
  
```   
BOOL AFXAPI AfxOleRegisterControlClass(
    HINSTANCE hInstance,  
    REFCLSID clsid,  
    LPCTSTR pszProgID,  
    UINT idTypeName,  
    UINT idBitmap,  
    int nRegFlags,  
    DWORD dwMiscStatus,  
    REFGUID tlid,  
    WORD wVerMajor,  
    WORD wVerMinor); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 O identificador de instância do módulo associado à classe de controle.  
  
 `clsid`  
 A ID exclusiva de classe do controle.  
  
 `pszProgID`  
 A ID exclusiva do controle.  
  
 `idTypeName`  
 A ID de recurso da cadeia de caracteres que contém um nome de tipo legíveis pelo usuário para o controle.  
  
 *idBitmap*  
 A ID de recurso do bitmap usado para representar o controle OLE em uma barra de ferramentas ou uma paleta.  
  
 `nRegFlags`  
 Contém um ou mais dos sinalizadores a seguir:  
  
- `afxRegInsertable`Permite que o controle seja exibido na caixa de diálogo Inserir objeto para objetos OLE.  
  
- `afxRegApartmentThreading`Define o modelo de threading no registro para ThreadingModel = Apartment.  
  
- `afxRegFreeThreading`Define o modelo de threading no registro para ThreadingModel = livre.  
  
     Você pode combinar dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` para definir ThreadingModel = Both. Consulte [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.  
  
> [!NOTE]
>  Em versões do MFC antes MFC 4.2, o `int` `nRegFlags` parâmetro era um **BOOL** parâmetro *bInsertable*, que permitido ou proibido o controle a ser inserido na caixa de diálogo Inserir objeto caixa.  
  
 *dwMiscStatus*  
 Contém um ou mais dos seguintes sinalizadores de status (para obter uma descrição dos sinalizadores, consulte **OLEMISC** enumeração no SDK do Windows):  
  
-   OLEMISC_RECOMPOSEONRESIZE  
  
-   OLEMISC_ONLYICONIC  
  
-   OLEMISC_INSERTNOTREPLACE  
  
-   OLEMISC_STATIC  
  
-   OLEMISC_CANTLINKINSIDE  
  
-   OLEMISC_CANLINKBYOLE1  
  
-   OLEMISC_ISLINKOBJECT  
  
-   OLEMISC_INSIDEOUT  
  
-   OLEMISC_ACTIVATEWHENVISIBLE  
  
-   OLEMISC_RENDERINGISDEVICEINDEPENDENT  
  
-   OLEMISC_INVISIBLEATRUNTIME  
  
-   OLEMISC_ALWAYSRUN  
  
-   OLEMISC_ACTSLIKEBUTTON  
  
-   OLEMISC_ACTSLIKELABEL  
  
-   OLEMISC_NOUIACTIVATE  
  
-   OLEMISC_ALIGNABLE  
  
-   OLEMISC_IMEMODE  
  
-   OLEMISC_SIMPLEFRAME  
  
-   OLEMISC_SETCLIENTSITEFIRST  
  
 *tlid*  
 A ID exclusiva da classe de controle.  
  
 `wVerMajor`  
 O número de versão principal da classe de controle.  
  
 `wVerMinor`  
 O número de versão secundária da classe de controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a classe de controle foi registrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que o controle a ser usado por contêineres que estão cientes de controle OLE. `AfxOleRegisterControlClass`atualiza o registro com o nome e o local no sistema de controle e também define o modelo de threading que permite o controle no registro. Para obter mais informações, consulte [64 de observação técnica](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Modelo Apartment Threading em OLE controles," e [sobre processos e Threads](http://msdn.microsoft.com/library/windows/desktop/ms681917) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAxCtl#11](../../mfc/reference/codesnippet/cpp/registering-ole-controls_1.cpp)]  
  
 O exemplo anterior demonstra como `AfxOleRegisterControlClass` é chamado com o sinalizador para inserível e o sinalizador de apartment ORed juntos para criar o sexto parâmetro do modelo:  
  
 [!code-cpp[NVC_MFCAxCtl#12](../../mfc/reference/codesnippet/cpp/registering-ole-controls_2.cpp)]  
  
 O controle será exibido na caixa de diálogo Inserir objeto para contêineres habilitados e será baseado no modelo de apartment. Controles com reconhecimento de modelo Apartment devem garantir que os dados são protegidos por bloqueios, de classe estática para que enquanto um controle em um apartment está acessando os dados estáticos, ele não está desabilitado pelo Agendador antes de ser concluído e outra instância da mesma classe é iniciado usando os mesmos dados estáticos. Qualquer acesso aos dados estáticos é envolvido por código de seção crítica.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="afxoleregisterpropertypageclass"></a>AfxOleRegisterPropertyPageClass  
 Registra a classe de página de propriedade com o banco de dados de registro do Windows.  
  
```  
BOOL AFXAPI AfxOleRegisterPropertyPageClass(
   HINSTANCE hInstance,  
   REFCLSID  clsid,  
   UINT idTypeName,  
   int nRegFlags); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 O identificador de instância do módulo associado à classe de página de propriedade.  
  
 `clsid`  
 A ID exclusiva de classe da página de propriedades.  
  
 `idTypeName`  
 A ID de recurso da cadeia de caracteres que contém um nome legível do usuário para a página de propriedades.  
  
 `nRegFlags`  
 Pode conter o sinalizador:  
  
- `afxRegApartmentThreading`Define o modelo de threading no registro para ThreadingModel = Apartment.  
  
> [!NOTE]
>  Nas versões anteriores do MFC ao MFC 4.2, o `int` `nRegFlags` parâmetro não estava disponível. Observe também que o `afxRegInsertable` sinalizador não é uma opção válida para as páginas de propriedade e fará com que uma declaração no MFC se ele está definido  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a classe de controle foi registrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que a página de propriedade a ser usado por contêineres que estão cientes de controle OLE. `AfxOleRegisterPropertyPageClass`atualiza o registro com o nome da página de propriedade e sua localização no sistema e também define o modelo de threading que permite o controle no registro. Para obter mais informações, consulte [64 de observação técnica](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Modelo Apartment Threading em OLE controles," e [sobre processos e Threads](http://msdn.microsoft.com/library/windows/desktop/ms681917) no SDK do Windows.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="afxoleregistertypelib"></a>AfxOleRegisterTypeLib  
 Registra a biblioteca de tipos com o banco de dados de registro do Windows e permite que a biblioteca de tipo a ser usado por outros contêineres que estão cientes de controle OLE.  
  
```   
BOOL AfxOleRegisterTypeLib(
    HINSTANCE hInstance,  
    REFGUID tlid,  
    LPCTSTR pszFileName = NULL,  
    LPCTSTR pszHelpDir  = NULL); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 O identificador de instância do aplicativo associado com a biblioteca de tipos.  
  
 *tlid*  
 A ID exclusiva da biblioteca de tipos.  
  
 *pszFileName*  
 Aponta para o nome de arquivo opcional de uma biblioteca de tipo localizado (. Arquivos TLB) para o controle.  
  
 *pszHelpDir*  
 O nome do diretório onde o arquivo de ajuda para a biblioteca de tipos pode ser encontrado. Se **nulo**, o arquivo de Ajuda deve para estar no mesmo diretório que a biblioteca de tipos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a biblioteca de tipos foi registrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função atualiza o registro com o nome da biblioteca de tipos e sua localização no sistema.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#7](../../mfc/codesnippet/cpp/registering-ole-controls_3.cpp)]  
  
 [!code-cpp[NVC_MFCAutomation#8](../../mfc/codesnippet/cpp/registering-ole-controls_4.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="afxoleunregisterclass"></a>AfxOleUnregisterClass  
 Remove a entrada de classe de página de propriedade ou o banco de dados de registro do Windows.  
  
```   
BOOL AFXAPI AfxOleUnregisterClass(REFCLSID clsID, LPCSTR pszProgID); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *clsID*  
 A ID de classe exclusivo da página de controle ou propriedade.  
  
 `pszProgID`  
 A ID exclusiva da página de controle ou propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a classe de página de propriedade ou foi cancelada com êxito; Caso contrário, 0.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="afxoleunregistertypelib"></a>AfxOleUnregisterTypeLib  
 Chame essa função para remover a entrada da biblioteca de tipo de banco de dados de registro do Windows.  
  
```   
BOOL AFXAPI AfxOleUnregisterTypeLib(REFGUID tlID); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `tlID`  
 A ID exclusiva da biblioteca de tipos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a biblioteca de tipos foi cancelada com êxito; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAxCtl#13](../../mfc/reference/codesnippet/cpp/registering-ole-controls_5.cpp)]  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
