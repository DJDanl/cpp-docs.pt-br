---
title: Classe COleDataSource | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleDataSource
dev_langs:
- C++
helpviewer_keywords:
- drag and drop [C++], MFC support
- Clipboard [C++], OLE support
- uniform data transfer
- OLE [C++], uniform data transfer
- Clipboard [C++], MFC support
- OLE Clipboard [C++], support
- IDataObject, MFC encapsulation
- data transfer [C++], OLE
- COleDataSource class
- OLE data transfer [C++]
- uniform data transfer, OLE
ms.assetid: 02c8ee7d-8e10-4463-8613-bb2a0305ca69
caps.latest.revision: 23
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: cd8f30c3edd7d26b254e7f4a6f153ab0b2fc96da
ms.lasthandoff: 02/25/2017

---
# <a name="coledatasource-class"></a>Classe COleDataSource
Atua como um cache no qual um aplicativo coloca os dados que ele oferecerá durante dados transferir operações, como a área de transferência ou operações de arrastar e soltar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDataSource : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDataSource::COleDataSource](#coledatasource)|Constrói um objeto `COleDataSource`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDataSource::CacheData](#cachedata)|Oferece dados em um formato especificado usando um **STGMEDIUM** estrutura.|  
|[COleDataSource::CacheGlobalData](#cacheglobaldata)|Oferece dados em um formato especificado usando um `HGLOBAL`.|  
|[COleDataSource::DelayRenderData](#delayrenderdata)|Oferece dados em um formato especificado usando o processamento atrasado.|  
|[COleDataSource::DelayRenderFileData](#delayrenderfiledata)|Oferece dados em um formato especificado em um `CFile` ponteiro.|  
|[COleDataSource::DelaySetData](#delaysetdata)|Chamado para cada formato com suporte no `OnSetData`.|  
|[COleDataSource::DoDragDrop](#dodragdrop)|Executa operações de arrastar e soltar com uma fonte de dados.|  
|[COleDataSource::Empty](#empty)|Esvazia o `COleDataSource` objeto de dados.|  
|[COleDataSource::FlushClipboard](#flushclipboard)|Renderiza todos os dados na área de transferência.|  
|[COleDataSource::GetClipboardOwner](#getclipboardowner)|Verifica se os dados inseridos na área de transferência ainda estão lá.|  
|[COleDataSource::OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|  
|[COleDataSource::OnRenderFileData](#onrenderfiledata)|Recupera dados em um `CFile` como parte do processamento atrasado.|  
|[COleDataSource::OnRenderGlobalData](#onrenderglobaldata)|Recupera dados em um `HGLOBAL` como parte do processamento atrasado.|  
|[COleDataSource::OnSetData](#onsetdata)|Chamado para substituir os dados no `COleDataSource` objeto.|  
|[COleDataSource::SetClipboard](#setclipboard)|Coloca um `COleDataSource` objeto na área de transferência.|  
  
## <a name="remarks"></a>Comentários  
 Você pode criar fontes de dados OLE diretamente. Como alternativa, o [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md) classes criarem fontes de dados OLE em resposta a suas `CopyToClipboard` e `DoDragDrop` funções de membro. Consulte [COleServerItem::CopyToClipboard](../../mfc/reference/coleserveritem-class.md#copytoclipboard) para obter uma breve descrição. Substituir o `OnGetClipboardData` a função de membro de seu item ou servidor item classe de cliente para adicionar mais formatos de área de transferência para os dados na fonte de dados OLE criado para o `CopyToClipboard` ou `DoDragDrop` função de membro.  
  
 Sempre que você deseja preparar dados para uma transferência, você deve criar um objeto dessa classe e preenchê-lo com os dados usando o método mais apropriado para seus dados. A maneira como ele é inserido em uma fonte de dados é diretamente afetado por se os dados são fornecidos imediatamente (renderização imediata) ou sob demanda (renderização atrasada). Para cada formato de área de transferência na qual você está fornecendo dados passando o formato da área de transferência a ser usado (e opcional [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura), chame [DelayRenderData](#delayrenderdata).  
  
 Para obter mais informações sobre fontes de dados e transferência de dados, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md). Além disso, o artigo [tópicos da área de transferência](../../mfc/clipboard.md) descreve o mecanismo da área de transferência OLE.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleDataSource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="a-namecachedataa--coledatasourcecachedata"></a><a name="cachedata"></a>COleDataSource::CacheData  
 Chame essa função para especificar um formato em que dados são oferecidos durante dados operações de transferência.  
  
```  
void CacheData(
    CLIPFORMAT cfFormat,  
    LPSTGMEDIUM lpStgMedium,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato de área de transferência na qual os dados são a oferta. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpStgMedium`  
 Aponta para um [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura que contém os dados no formato especificado.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se for **nulo**, valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="remarks"></a>Comentários  
 Você deve fornecer os dados, porque essa função fornece a ele usando renderização imediata. Os dados armazenados em cache até que sejam necessários.  
  
 Fonte de dados usando um [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura. Você também pode usar o `CacheGlobalData` função de membro se a quantidade de dados que você está fornecendo é pequena o suficiente para ser transferido com eficiência usando um `HGLOBAL`.  
  
 Após a chamada para `CacheData` o **ptd** membro do `lpFormatEtc` e o conteúdo de `lpStgMedium` são de propriedade do objeto de dados, não pelo chamador.  
  
 Para usar a renderização atrasada, chame o [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) função de membro. Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namecacheglobaldataa--coledatasourcecacheglobaldata"></a><a name="cacheglobaldata"></a>COleDataSource::CacheGlobalData  
 Chame essa função para especificar um formato em que dados são oferecidos durante dados operações de transferência.  
  
```  
void CacheGlobalData(
    CLIPFORMAT cfFormat,  
    HGLOBAL hGlobal,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato de área de transferência na qual os dados são a oferta. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 *hGlobal*  
 Identificador para o bloco de memória global que contém os dados no formato especificado.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se for **nulo**, valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece os dados usando processamento imediato, portanto você deve fornecer os dados ao chamar a função. os dados armazenados em cache até que sejam necessários. Use o `CacheData` função de membro, se você estiver fornecendo uma grande quantidade de dados ou se você precisar de uma mídia de armazenamento estruturado.  
  
 Para usar a renderização atrasada, chame o [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) função de membro. Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namecoledatasourcea--coledatasourcecoledatasource"></a><a name="coledatasource"></a>COleDataSource::COleDataSource  
 Constrói um objeto `COleDataSource`.  
  
```  
COleDataSource();
```  
  
##  <a name="a-namedelayrenderdataa--coledatasourcedelayrenderdata"></a><a name="delayrenderdata"></a>COleDataSource::DelayRenderData  
 Chame essa função para especificar um formato em que dados são oferecidos durante dados operações de transferência.  
  
```  
void DelayRenderData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato de área de transferência na qual os dados são a oferta. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se for **nulo**, valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece os dados usando a renderização atrasada, para que os dados não são fornecidos imediatamente. O [OnRenderData](#onrenderdata) ou [OnRenderGlobalData](#onrenderglobaldata) função de membro é chamada para solicitar os dados.  
  
 Use essa função se você não pretende fornecer seus dados por meio de uma `CFile` objeto. Se você pretende fornecer os dados por meio de um `CFile` de objeto, chame o [DelayRenderFileData](#delayrenderfiledata) função de membro. Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para usar a renderização de imediata, chame o [CacheData](#cachedata) ou [CacheGlobalData](#cacheglobaldata) função de membro.  
  
 Para obter mais informações, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namedelayrenderfiledataa--coledatasourcedelayrenderfiledata"></a><a name="delayrenderfiledata"></a>COleDataSource::DelayRenderFileData  
 Chame essa função para especificar um formato em que dados são oferecidos durante dados operações de transferência.  
  
```  
void DelayRenderFileData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato de área de transferência na qual os dados são a oferta. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se for **nulo**, valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece os dados usando a renderização atrasada, para que os dados não são fornecidos imediatamente. O [OnRenderFileData](#onrenderfiledata) função de membro é chamada para solicitar os dados.  
  
 Use essa função se você pretende usar um `CFile` objeto para fornecer os dados. Se você não pretender usar um `CFile` de objeto, chame o [DelayRenderData](#delayrenderdata) função de membro. Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para usar a renderização de imediata, chame o [CacheData](#cachedata) ou [CacheGlobalData](#cacheglobaldata) função de membro.  
  
 Para obter mais informações, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namedelaysetdataa--coledatasourcedelaysetdata"></a><a name="delaysetdata"></a>COleDataSource::DelaySetData  
 Chame essa função para dar suporte à alteração do conteúdo da fonte de dados.  
  
```  
void DelaySetData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato da área de transferência na qual os dados são colocado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados são a ser substituído. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se for **nulo**, valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="remarks"></a>Comentários  
 [OnSetData](#onsetdata) será chamado pela estrutura quando isso acontece. Isso é usado apenas quando o framework retorna a fonte de dados [COleServerItem::GetDataSource](../../mfc/reference/coleserveritem-class.md#getdatasource). Se `DelaySetData` não é chamado, o `OnSetData` função nunca será chamada. `DelaySetData`deve ser chamado para cada área de transferência ou **FORMATETC** formato você dá suporte.  
  
 Para obter mais informações, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namedodragdropa--coledatasourcedodragdrop"></a><a name="dodragdrop"></a>COleDataSource::DoDragDrop  
 Chamar o `DoDragDrop` a função de membro para executar uma operação de arrastar e soltar para esta fonte de dados, normalmente em uma [CWnd::OnLButtonDown](../../mfc/reference/cwnd-class.md#onlbuttondown) manipulador.  
  
```  
DROPEFFECT DoDragDrop(
    DWORD dwEffects = DROPEFFECT_COPY|DROPEFFECT_MOVE|DROPEFFECT_LINK,  
    LPCRECT lpRectStartDrag = NULL,  
    COleDropSource* pDropSource = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwEffects`  
 Arrastar e soltar operações que são permitidas nessa fonte de dados. Pode ser um ou mais destes procedimentos:  
  
- `DROPEFFECT_COPY`Uma operação de cópia pode ser executada.  
  
- `DROPEFFECT_MOVE`Uma operação de movimentação pode ser executada.  
  
- `DROPEFFECT_LINK`Foi possível estabelecer um vínculo de dados eliminados para os dados originais.  
  
- `DROPEFFECT_SCROLL`Indica que uma operação de rolagem de arrastar pode ocorrer.  
  
 `lpRectStartDrag`  
 Ponteiro para o retângulo que define onde realmente começa a arrastar. Para obter mais informações, consulte a seção Comentários a seguir.  
  
 *pDropSource*  
 Aponta para uma origem para soltar. Se **nulo** , em seguida, uma implementação padrão de [COleDropSource](../../mfc/reference/coledropsource-class.md) será usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Remover efeito gerado pela operação de arrastar e soltar; Caso contrário, `DROPEFFECT_NONE` se a operação nunca inicia, já que o usuário lançou o botão do mouse antes de deixar o retângulo fornecido.  
  
### <a name="remarks"></a>Comentários  
 A operação de arrastar e soltar não será iniciado imediatamente. Ele aguarda até que o cursor do mouse sai do retângulo especificado por `lpRectStartDrag` ou até que um número especificado de milissegundos tiver passado. Se `lpRectStartDrag` é **nulo**, o tamanho do retângulo é um pixel.  
  
 O tempo de atraso é especificado pela configuração da chave do registro. Você pode alterar o tempo de atraso chamando [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de espera, é usado um valor padrão de 200 milissegundos. Tempo de atraso de arrastar é armazenado da seguinte maneira:  
  
-   Tempo de atraso de arraste do Windows NT é armazenado em HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.  
  
-   Tempo de atraso de arraste do Windows 3. x é armazenado em arquivos WIN. Arquivo INI, em [} seção Windows.  
  
-   Tempo de espera do Windows 95/98 arrastar é armazenado em uma versão em cache do WIN. INI.  
  
 Para obter mais informações sobre como arrastar informações de atraso são armazenadas no registro ou o. O arquivo INI, consulte [WriteProfileString](http://msdn.microsoft.com/library/windows/desktop/ms725504) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando uma origem de descartar](../../mfc/drag-and-drop-implementing-a-drop-source.md).  
  
##  <a name="a-nameemptya--coledatasourceempty"></a><a name="empty"></a>COleDataSource::Empty  
 Chame essa função para esvaziar o `COleDataSource` objeto de dados.  
  
```  
void Empty();
```  
  
### <a name="remarks"></a>Comentários  
 Ambos em cache e formatos de processamento de atraso são removidos para que eles possam ser reutilizados.  
  
 Para obter mais informações, consulte [ReleaseStgMedium](http://msdn.microsoft.com/library/windows/desktop/ms693491) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameflushclipboarda--coledatasourceflushclipboard"></a><a name="flushclipboard"></a>COleDataSource::FlushClipboard  
 Processa dados na área de transferência e, em seguida, permite que você colar os dados da área de transferência após o aplicativo ser encerrado.  
  
```  
static void PASCAL FlushClipboard();
```  
  
### <a name="remarks"></a>Comentários  
 Use [SetClipboard](#setclipboard) para colocar dados na área de transferência.  
  
##  <a name="a-namegetclipboardownera--coledatasourcegetclipboardowner"></a><a name="getclipboardowner"></a>COleDataSource::GetClipboardOwner  
 Determina se os dados na área de transferência mudou desde [SetClipboard](#setclipboard) foi chamado pela última vez e, em caso afirmativo, identifica o proprietário atual.  
  
```  
static COleDataSource* PASCAL GetClipboardOwner();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A fonte de dados no momento na área de transferência, ou **nulo** se não há nada na área de transferência ou se o aplicativo de chamada não pertence a área de transferência.  
  
##  <a name="a-nameonrenderdataa--coledatasourceonrenderdata"></a><a name="onrenderdata"></a>COleDataSource::OnRenderData  
 Chamado pela estrutura para recuperar dados no formato especificado.  
  
```  
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `lpStgMedium`  
 Aponta para um [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura na qual os dados são a ser retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no `COleDataSource` objeto usando o [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) a função de membro para processamento posterior. A implementação padrão dessa função chamará [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata) se a mídia de armazenamento fornecido é um arquivo ou memória, respectivamente. Se nenhum desses formatos são fornecidos, a implementação padrão retornará 0 e não fazer nada. Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Se `lpStgMedium` ->  *tymed* é **TYMED_NULL**, o **STGMEDIUM** deve ser alocado e preenchida conforme especificado por *lpFormatEtc-> tymed*. Se não for **TYMED_NULL**, o **STGMEDIUM** deve ser preenchido no local com os dados.  
  
 Isso é uma avançada substituível. Substitua essa função para fornecer seus dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se os dados forem pequenos e com o tamanho fixo, substituir `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estruturas, o [TYMED](http://msdn.microsoft.com/library/windows/desktop/ms691227) tipo de enumeração e [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
##  <a name="a-nameonrenderfiledataa--coledatasourceonrenderfiledata"></a><a name="onrenderfiledata"></a>COleDataSource::OnRenderFileData  
 Chamado pela estrutura para recuperar dados no formato especificado quando a mídia de armazenamento especificado é um arquivo.  
  
```  
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,  
    CFile* pFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `pFile`  
 Aponta para um [CFile](../../mfc/reference/cfile-class.md) objeto no qual os dados a serem processados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no `COleDataSource` objeto usando o [DelayRenderData](#delayrenderdata) a função de membro para processamento posterior. A implementação padrão dessa função simplesmente retorna **FALSE**.  
  
 Isso é uma avançada substituível. Substitua essa função para fornecer seus dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`. Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura e [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
##  <a name="a-nameonrenderglobaldataa--coledatasourceonrenderglobaldata"></a><a name="onrenderglobaldata"></a>COleDataSource::OnRenderGlobalData  
 Chamado pela estrutura para recuperar dados no formato especificado quando a mídia de armazenamento especificado é memória global.  
  
```  
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,  
    HGLOBAL* phGlobal);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `phGlobal`  
 Aponta para um identificador de memória global na qual os dados são a ser retornado. Se um ainda não foi alocado, esse parâmetro pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no `COleDataSource` objeto usando o [DelayRenderData](#delayrenderdata) a função de membro para processamento posterior. A implementação padrão dessa função simplesmente retorna **FALSE**.  
  
 Se `phGlobal` é **nulo**, em seguida, um novo `HGLOBAL` deve ser alocado e retornados em `phGlobal`. Caso contrário, o `HGLOBAL` especificado por `phGlobal` deve ser preenchido com os dados. A quantidade de dados colocados no `HGLOBAL` não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.  
  
 Isso é uma avançada substituível. Substitua essa função para fornecer seus dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substituir [OnRenderFileData](#onrenderfiledata). Para obter mais informações sobre renderização atrasada como manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura e [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
##  <a name="a-nameonsetdataa--coledatasourceonsetdata"></a><a name="onsetdata"></a>COleDataSource::OnSetData  
 Chamado pela estrutura para definir ou substituir os dados no `COleDataSource` objeto no formato especificado.  
  
```  
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium,  
    BOOL bRelease);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que especifica o formato de dados no qual está sendo substituídos.  
  
 `lpStgMedium`  
 Aponta para a [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura que contém os dados que substituirão o conteúdo atual do `COleDataSource` objeto.  
  
 `bRelease`  
 Indica que é proprietária da mídia de armazenamento depois de concluir a chamada de função. O chamador decide quem é responsável por liberar os recursos alocados em nome de mídia de armazenamento. O chamador faz isso definindo `bRelease`. Se `bRelease` é diferente de zero, a fonte de dados assume a propriedade, liberando a mídia quando ele tiver terminado de usá-lo. Quando `bRelease` é 0, o chamador reterá a propriedade e a fonte de dados pode usar a mídia de armazenamento apenas para a duração da chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A fonte de dados não assumir a propriedade dos dados até que ele obteve com êxito-lo. Ou seja, ele não apropriar-se `OnSetData` retornará 0. Se a fonte de dados se apropria, libera a mídia de armazenamento, chamando o [ReleaseStgMedium](http://msdn.microsoft.com/library/windows/desktop/ms693491) função.  
  
 A implementação padrão não faz nada. Substitua essa função para substituir os dados no formato especificado. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estruturas e [ReleaseStgMedium](http://msdn.microsoft.com/library/windows/desktop/ms693491) e [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) funciona no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
##  <a name="a-namesetclipboarda--coledatasourcesetclipboard"></a><a name="setclipboard"></a>COleDataSource::SetClipboard  
 Coloca os dados contidos no `COleDataSource` objeto na área de transferência depois de chamar uma das seguintes funções: [CacheData](#cachedata), [CacheGlobalData](#cacheglobaldata), [DelayRenderData](#delayrenderdata), ou [DelayRenderFileData](#delayrenderfiledata).  
  
```  
void SetClipboard();
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDataObject](../../mfc/reference/coledataobject-class.md)

