---
title: Classe CDataPathProperty | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDataPathProperty
- AFXCTL/CDataPathProperty
- AFXCTL/CDataPathProperty::CDataPathProperty
- AFXCTL/CDataPathProperty::GetControl
- AFXCTL/CDataPathProperty::GetPath
- AFXCTL/CDataPathProperty::Open
- AFXCTL/CDataPathProperty::ResetData
- AFXCTL/CDataPathProperty::SetControl
- AFXCTL/CDataPathProperty::SetPath
dev_langs:
- C++
helpviewer_keywords:
- CDataPathProperty [MFC], CDataPathProperty
- CDataPathProperty [MFC], GetControl
- CDataPathProperty [MFC], GetPath
- CDataPathProperty [MFC], Open
- CDataPathProperty [MFC], ResetData
- CDataPathProperty [MFC], SetControl
- CDataPathProperty [MFC], SetPath
ms.assetid: 1f96efdb-54e4-460b-862c-eba5d4103488
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f2559b4917f16bb8ddc49b73ace8bda6e1a9bafc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33367302"
---
# <a name="cdatapathproperty-class"></a>Classe CDataPathProperty
Implementa uma OLE controla a propriedade que pode ser carregada de forma assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDataPathProperty : public CAsyncMonikerFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDataPathProperty::CDataPathProperty](#cdatapathproperty)|Constrói um objeto `CDataPathProperty`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDataPathProperty::GetControl](#getcontrol)|Recupera o controle OLE assíncrono associado a `CDataPathProperty` objeto.|  
|[CDataPathProperty::GetPath](#getpath)|Recupera o nome do caminho da propriedade.|  
|[CDataPathProperty::Open](#open)|Inicia o carregamento da propriedade assíncrona para o controle ActiveX (OLE) associados.|  
|[CDataPathProperty::ResetData](#resetdata)|Chamadas `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner que alterou as propriedades do controle.|  
|[CDataPathProperty::SetControl](#setcontrol)|Define o controle ActiveX (OLE) assíncrona associado à propriedade.|  
|[CDataPathProperty::SetPath](#setpath)|Define o nome do caminho da propriedade.|  
  
## <a name="remarks"></a>Comentários  
 Propriedades assíncronas são carregadas após a inicialização síncrona.  
  
 A classe `CDataPathProperty` é derivado de **CAysncMonikerFile**. Para implementar propriedades assíncronas em controles OLE, derive uma classe de `CDataPathProperty`e substituir [OnDataAvailable](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable).  
  
 Para obter mais informações sobre como usar monikers assíncronos e controles ActiveX em aplicativos da Internet, consulte os seguintes artigos:  
  
- [Internet primeiras etapas: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)  
  
- [Internet primeiras etapas: Monikers assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [COleStreamFile](../../mfc/reference/colestreamfile-class.md)  
  
 [CMonikerFile](../../mfc/reference/cmonikerfile-class.md)  
  
 [CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)  
  
 `CDataPathProperty`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h  
  
##  <a name="cdatapathproperty"></a>  CDataPathProperty::CDataPathProperty  
 Constrói um objeto `CDataPathProperty`.  
  
```  
CDataPathProperty(COleControl* pControl = NULL);  
CDataPathProperty(LPCTSTR lpszPath, COleControl* pControl = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pControl`  
 Um ponteiro para o objeto de controle OLE a ser associado este `CDataPathProperty` objeto.  
  
 `lpszPath`  
 O caminho, o que pode ser absoluta ou relativa, usado para criar um moniker assíncrona que faz referência a localização absoluta real da propriedade. `CDataPathProperty` usa URLs, nomes de arquivos não. Se você quiser uma `CDataPathProperty` de objeto para um arquivo, preceda `file://` ao caminho.  
  
### <a name="remarks"></a>Comentários  
 O `COleControl` objeto apontada pelo `pControl` é usado pelo **abrir** e recuperados pelas classes derivadas. Se `pControl` é **nulo**, o controle usado com **abrir** deve ser definido com `SetControl`. Se `lpszPath` é **nulo**, você pode passar o caminho por meio de **abrir** ou defini-lo com `SetPath`.  
  
##  <a name="getcontrol"></a>  CDataPathProperty::GetControl  
 Chamar essa função de membro para recuperar o `COleControl` objeto associado a `CDataPathProperty` objeto.  
  
```  
COleControl* GetControl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o controle OLE associado a `CDataPathProperty` objeto. **NULO** se o controle não está associado.  
  
##  <a name="getpath"></a>  CDataPathProperty::GetPath  
 Chamar essa função de membro para recuperar o caminho, defina quando o `CDataPathProperty` objeto foi construído ou especificado no **abrir**, ou especificados em uma chamada anterior para o `SetPath` função de membro.  
  
```  
CString GetPath() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o nome do caminho para a propriedade em si. Pode ser vazio se nenhum caminho tiver sido especificado.  
  
##  <a name="open"></a>  CDataPathProperty::Open  
 Chame essa função de membro para iniciar o carregamento da propriedade assíncrona para o controle associado.  
  
```  
virtual BOOL Open(
    COleControl* pControl,  
    CFileException* pError = NULL);

 
virtual BOOL Open(
    LPCTSTR lpszPath,  
    COleControl* pControl,
    CFileException* pError = NULL);

 
virtual BOOL Open(
    LPCTSTR lpszPath,  
    CFileException* pError = NULL);  
  
virtual BOOL Open(CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pControl`  
 Um ponteiro para o objeto de controle OLE a ser associado este `CDataPathProperty` objeto.  
  
 `pError`  
 Um ponteiro para uma exceção de arquivo. Em caso de erro, será definido como a causa.  
  
 `lpszPath`  
 O caminho, o que pode ser absoluta ou relativa, usado para criar um moniker assíncrona que faz referência a localização absoluta real da propriedade. `CDataPathProperty` usa URLs, nomes de arquivos não. Se você quiser uma `CDataPathProperty` de objeto para um arquivo, preceda `file://` ao caminho.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função tenta obter o `IBindHost` interface do controle.  
  
 Antes de chamar **abrir** sem um caminho, o valor para o caminho da propriedade deve ser definido. Isso pode ser feito quando o objeto for construído, ou chamando o `SetPath` função de membro.  
  
 Antes de chamar **abrir** sem um controle, um controle ActiveX (anteriormente conhecido como um controle OLE) pode ser associado ao objeto. Isso pode ser feito quando o objeto for construído, ou chamando `SetControl`.  
  
 Todas as sobrecargas de [CAsyncMonikerFile::Open](../../mfc/reference/casyncmonikerfile-class.md#open) também estão disponíveis no `CDataPathProperty`.  
  
##  <a name="resetdata"></a>  CDataPathProperty::ResetData  
 Chamar essa função para obter `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner que as propriedades de controle foram alteradas, e todas as informações carregadas de forma assíncrona não são mais útil.  
  
```  
virtual void ResetData();
```  
  
### <a name="remarks"></a>Comentários  
 Abertura deve ser reiniciada. Classes derivadas podem substituir essa função para padrões diferentes.  
  
##  <a name="setcontrol"></a>  CDataPathProperty::SetControl  
 Chamar essa função de membro para associar um controle OLE assíncrono com o `CDataPathProperty` objeto.  
  
```  
void SetControl(COleControl* pControl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pControl`  
 Um ponteiro para o controle OLE assíncrono deve ser associada com a propriedade.  
  
##  <a name="setpath"></a>  CDataPathProperty::SetPath  
 Chame essa função de membro para definir o nome do caminho da propriedade.  
  
```  
void SetPath(LPCTSTR lpszPath);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPath`  
 Um caminho, que pode ser absoluta ou relativa, a propriedade que está sendo carregada de forma assíncrona. `CDataPathProperty` usa URLs, nomes de arquivos não. Se você quiser uma `CDataPathProperty` de objeto para um arquivo, preceda `file://` ao caminho.  
  
## <a name="see-also"></a>Consulte também  
 [Imagem de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
