---
title: Classe COleDataSource | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDataSource
- AFXOLE/COleDataSource
- AFXOLE/COleDataSource::COleDataSource
- AFXOLE/COleDataSource::CacheData
- AFXOLE/COleDataSource::CacheGlobalData
- AFXOLE/COleDataSource::DelayRenderData
- AFXOLE/COleDataSource::DelayRenderFileData
- AFXOLE/COleDataSource::DelaySetData
- AFXOLE/COleDataSource::DoDragDrop
- AFXOLE/COleDataSource::Empty
- AFXOLE/COleDataSource::FlushClipboard
- AFXOLE/COleDataSource::GetClipboardOwner
- AFXOLE/COleDataSource::OnRenderData
- AFXOLE/COleDataSource::OnRenderFileData
- AFXOLE/COleDataSource::OnRenderGlobalData
- AFXOLE/COleDataSource::OnSetData
- AFXOLE/COleDataSource::SetClipboard
dev_langs:
- C++
helpviewer_keywords:
- COleDataSource [MFC], COleDataSource
- COleDataSource [MFC], CacheData
- COleDataSource [MFC], CacheGlobalData
- COleDataSource [MFC], DelayRenderData
- COleDataSource [MFC], DelayRenderFileData
- COleDataSource [MFC], DelaySetData
- COleDataSource [MFC], DoDragDrop
- COleDataSource [MFC], Empty
- COleDataSource [MFC], FlushClipboard
- COleDataSource [MFC], GetClipboardOwner
- COleDataSource [MFC], OnRenderData
- COleDataSource [MFC], OnRenderFileData
- COleDataSource [MFC], OnRenderGlobalData
- COleDataSource [MFC], OnSetData
- COleDataSource [MFC], SetClipboard
ms.assetid: 02c8ee7d-8e10-4463-8613-bb2a0305ca69
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d67165d3869ffdd60eff86fa8c33abf275e070b4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209771"
---
# <a name="coledatasource-class"></a>Classe COleDataSource
Atua como um cache no qual um aplicativo coloca os dados que oferecerá durante dados transferência de operações, como a área de transferência ou operações de arrastar e soltar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDataSource : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDataSource::COleDataSource](#coledatasource)|Constrói um objeto `COleDataSource`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDataSource::CacheData](#cachedata)|Oferece dados em um formato especificado usando um `STGMEDIUM` estrutura.|  
|[COleDataSource::CacheGlobalData](#cacheglobaldata)|Oferece dados em um formato especificado usando um HGLOBAL.|  
|[COleDataSource::DelayRenderData](#delayrenderdata)|Oferece dados em um formato especificado usando o processamento atrasado.|  
|[COleDataSource::DelayRenderFileData](#delayrenderfiledata)|Oferece dados em um formato especificado em um `CFile` ponteiro.|  
|[COleDataSource::DelaySetData](#delaysetdata)|Chamado para todos os formatos com suporte no `OnSetData`.|  
|[COleDataSource::DoDragDrop](#dodragdrop)|Executa operações de arrastar e soltar com uma fonte de dados.|  
|[COleDataSource::Empty](#empty)|Esvazia o `COleDataSource` objeto de dados.|  
|[COleDataSource::FlushClipboard](#flushclipboard)|Renderiza todos os dados na área de transferência.|  
|[COleDataSource::GetClipboardOwner](#getclipboardowner)|Verifica se os dados colocados na área de transferência são ainda está lá.|  
|[COleDataSource::OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|  
|[COleDataSource::OnRenderFileData](#onrenderfiledata)|Recupera os dados em um `CFile` como parte da renderização atrasada.|  
|[COleDataSource::OnRenderGlobalData](#onrenderglobaldata)|Recupera os dados em um HGLOBAL como parte da renderização atrasada.|  
|[COleDataSource::OnSetData](#onsetdata)|Chamado para substituir os dados no `COleDataSource` objeto.|  
|[COleDataSource::SetClipboard](#setclipboard)|Coloca um `COleDataSource` objeto na área de transferência.|  
  
## <a name="remarks"></a>Comentários  
 Você pode criar fontes de dados OLE diretamente. Como alternativa, o [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [COleServerItem](../../mfc/reference/coleserveritem-class.md) classes criar fontes de dados OLE em resposta a suas `CopyToClipboard` e `DoDragDrop` funções de membro. Ver [COleServerItem::CopyToClipboard](../../mfc/reference/coleserveritem-class.md#copytoclipboard) para obter uma descrição breve. Substituir a `OnGetClipboardData` função de membro de seu cliente item ou o servidor de classe de item para adicionar outros formatos de área de transferência para os dados na fonte de dados OLE criado para o `CopyToClipboard` ou `DoDragDrop` função de membro.  
  
 Sempre que quiser para preparar dados para uma transferência, você deve criar um objeto dessa classe e preenchê-lo com seus dados usando o método mais apropriado para seus dados. A maneira como ele é inserido em uma fonte de dados é diretamente afetado por se os dados são fornecidos imediatamente (renderização imediata) ou sob demanda (renderização atrasada). Para todos os formatos de área de transferência na qual você está fornecendo dados, passando o formato de área de transferência a ser usado (e um opcional [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura), chame [DelayRenderData](#delayrenderdata).  
  
 Para obter mais informações sobre fontes de dados e transferência de dados, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md). Além disso, o artigo [tópicos da área de transferência](../../mfc/clipboard.md) descreve o mecanismo de área de transferência OLE.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleDataSource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="cachedata"></a>  COleDataSource::CacheData  
 Chame essa função para especificar um formato nos quais dados são oferecidos durante a dados de operações de transferência.  
  
```  
void CacheData(
    CLIPFORMAT cfFormat,  
    LPSTGMEDIUM lpStgMedium,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cfFormat*  
 O formato de área de transferência na qual os dados deve ser oferecido. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.  
  
 *lpStgMedium*  
 Aponta para um [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura que contém os dados no formato especificado.  
  
 *lpFormatEtc*  
 Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Você deve fornecer os dados, porque essa função fornece a ele usando o processamento imediato. Os dados armazenados em cache até que o necessário.  
  
 Fornecer os dados usando um [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura. Você também pode usar o `CacheGlobalData` função de membro, se a quantidade de dados que você está fornecendo é pequena o suficiente para ser transferido com eficiência usando um HGLOBAL.  
  
 Após a chamada para `CacheData` o `ptd` membro `lpFormatEtc` e o conteúdo dos *lpStgMedium* são de propriedade do objeto de dados, não pelo chamador.  
  
 Para usar a renderização atrasada, chame o [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) função de membro. Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estruturas no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.  
  
##  <a name="cacheglobaldata"></a>  COleDataSource::CacheGlobalData  
 Chame essa função para especificar um formato nos quais dados são oferecidos durante a dados de operações de transferência.  
  
```  
void CacheGlobalData(
    CLIPFORMAT cfFormat,  
    HGLOBAL hGlobal,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cfFormat*  
 O formato de área de transferência na qual os dados deve ser oferecido. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.  
  
 *hGlobal*  
 Identificador para o bloco de memória global que contém os dados no formato especificado.  
  
 *lpFormatEtc*  
 Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece os dados usando a renderização de imediato, portanto, você deve fornecer os dados ao chamar a função; os dados armazenados em cache até que o necessário. Use o `CacheData` função de membro, se você estiver fornecendo uma grande quantidade de dados ou se você precisar de uma mídia de armazenamento estruturado.  
  
 Para usar a renderização atrasada, chame o [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) função de membro. Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.  
  
##  <a name="coledatasource"></a>  COleDataSource::COleDataSource  
 Constrói um objeto `COleDataSource`.  
  
```  
COleDataSource();
```  
  
##  <a name="delayrenderdata"></a>  COleDataSource::DelayRenderData  
 Chame essa função para especificar um formato nos quais dados são oferecidos durante a dados de operações de transferência.  
  
```  
void DelayRenderData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cfFormat*  
 O formato de área de transferência na qual os dados deve ser oferecido. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.  
  
 *lpFormatEtc*  
 Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece os dados usando a renderização atrasada, portanto, os dados não são fornecidos imediatamente. O [OnRenderData](#onrenderdata) ou [OnRenderGlobalData](#onrenderglobaldata) função de membro é chamada para solicitar os dados.  
  
 Use essa função se você não pretende fornecer seus dados por meio de um `CFile` objeto. Se você pretende fornecer os dados por meio de um `CFile` do objeto, chame o [DelayRenderFileData](#delayrenderfiledata) função de membro. Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para usar a renderização de imediata, chame o [CacheData](#cachedata) ou [CacheGlobalData](#cacheglobaldata) função de membro.  
  
 Para obter mais informações, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.  
  
##  <a name="delayrenderfiledata"></a>  COleDataSource::DelayRenderFileData  
 Chame essa função para especificar um formato nos quais dados são oferecidos durante a dados de operações de transferência.  
  
```  
void DelayRenderFileData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cfFormat*  
 O formato de área de transferência na qual os dados deve ser oferecido. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.  
  
 *lpFormatEtc*  
 Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados são a oferta. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece os dados usando a renderização atrasada, portanto, os dados não são fornecidos imediatamente. O [OnRenderFileData](#onrenderfiledata) função de membro é chamada para solicitar os dados.  
  
 Use essa função se você pretende usar um `CFile` objeto para fornecer os dados. Se você não pretende usar um `CFile` do objeto, chame o [DelayRenderData](#delayrenderdata) função de membro. Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para usar a renderização de imediata, chame o [CacheData](#cachedata) ou [CacheGlobalData](#cacheglobaldata) função de membro.  
  
 Para obter mais informações, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.  
  
##  <a name="delaysetdata"></a>  COleDataSource::DelaySetData  
 Chame essa função para dar suporte à alteração do conteúdo da fonte de dados.  
  
```  
void DelaySetData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cfFormat*  
 O formato de área de transferência na qual os dados deve ser colocado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.  
  
 *lpFormatEtc*  
 Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados são a ser substituído. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="remarks"></a>Comentários  
 [OnSetData](#onsetdata) será chamado pelo framework quando isso acontece. Isso é usado somente quando o framework retorna a fonte de dados do [COleServerItem::GetDataSource](../../mfc/reference/coleserveritem-class.md#getdatasource). Se `DelaySetData` não for chamado, seu `OnSetData` função nunca será chamada. `DelaySetData` deve ser chamado para cada área de transferência ou `FORMATETC` formato você oferece suporte.  
  
 Para obter mais informações, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.  
  
##  <a name="dodragdrop"></a>  COleDataSource::DoDragDrop  
 Chame o `DoDragDrop` função de membro para executar uma operação de arrastar e soltar para esta fonte de dados, normalmente em um [CWnd::OnLButtonDown](../../mfc/reference/cwnd-class.md#onlbuttondown) manipulador.  
  
```  
DROPEFFECT DoDragDrop(
    DWORD dwEffects = DROPEFFECT_COPY|DROPEFFECT_MOVE|DROPEFFECT_LINK,  
    LPCRECT lpRectStartDrag = NULL,  
    COleDropSource* pDropSource = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
*dwEffects*  
Arrastar e soltar operações que são permitidas nessa fonte de dados. Pode ser um ou mais destes procedimentos:  
  
 - DROPEFFECT_COPY pôde ser executada uma operação de cópia.  
      
 - DROPEFFECT_MOVE pôde ser executada uma operação de movimentação.  
      
 - Foi possível estabelecer o link de um DROPEFFECT_LINK dos dados soltos para os dados originais.  
      
 - DROPEFFECT_SCROLL indica que uma operação de rolagem de arrastar pode ocorrer.  
  
*lpRectStartDrag*  
Ponteiro para o retângulo que define onde realmente inicia a operação de arrastar. Para obter mais informações, consulte a seção Comentários a seguir.  
  
*pDropSource*  
Aponta para uma origem para soltar. Se nulo, em seguida, uma implementação padrão de [COleDropSource](../../mfc/reference/coledropsource-class.md) será usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Descartar efeito gerado pela operação de arrastar e soltar; Caso contrário DROPEFFECT_NONE se a operação nunca é iniciada porque o usuário soltou o botão do mouse antes de deixar o retângulo fornecido.  
  
### <a name="remarks"></a>Comentários  
 A operação de arrastar e soltar não é iniciado imediatamente. Ele aguarda até que o cursor do mouse deixa o retângulo especificado por *lpRectStartDrag* ou até que um número especificado de milissegundos tiver passado. Se *lpRectStartDrag* for NULL, o tamanho do retângulo é um pixel.  
  
 O tempo de atraso é especificado por uma configuração de chave do registro. Você pode alterar o tempo de atraso, chamando [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, é usado um valor padrão de 200 milissegundos. Tempo de atraso de arrastar é armazenado da seguinte maneira:  
  
-   Tempo de atraso de arrastar do Windows NT é armazenado no HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.  
  
-   Tempo de atraso de arrastar do Windows 3. x é armazenado no arquivo o WIN. Arquivo INI, sob a [seção Windows}.  
  
-   Tempo de atraso de arrastar do Windows 95/98 é armazenado em uma versão em cache do WIN. INI.  
  
 Para obter mais informações sobre como arrastar informações de atraso são armazenadas no registro ou o. O arquivo INI, consulte [WriteProfileString](/windows/desktop/api/winbase/nf-winbase-writeprofilestringa) no SDK do Windows.  
  
 Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando uma origem para soltar](../../mfc/drag-and-drop-implementing-a-drop-source.md).  
  
##  <a name="empty"></a>  COleDataSource::Empty  
 Chame essa função para esvaziar o `COleDataSource` objeto de dados.  
  
```  
void Empty();
```  
  
### <a name="remarks"></a>Comentários  
 Ambos em cache e formatos de renderização de atraso são removidos, de forma que possam ser reutilizados.  
  
 Para obter mais informações, consulte [ReleaseStgMedium](/windows/desktop/api/ole2/nf-ole2-releasestgmedium) no SDK do Windows.  
  
##  <a name="flushclipboard"></a>  COleDataSource::FlushClipboard  
 Processa os dados que está na área de transferência e, em seguida, permite que você colar os dados da área de transferência depois que seu aplicativo é desligado.  
  
```  
static void PASCAL FlushClipboard();
```  
  
### <a name="remarks"></a>Comentários  
 Use [SetClipboard](#setclipboard) para colocar dados na área de transferência.  
  
##  <a name="getclipboardowner"></a>  COleDataSource::GetClipboardOwner  
 Determina se os dados na área de transferência foi alterado desde [SetClipboard](#setclipboard) foi chamado pela última vez e, nesse caso, identifica o proprietário atual.  
  
```  
static COleDataSource* PASCAL GetClipboardOwner();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados de origem no momento na área de transferência, ou NULL se não há nada na área de transferência ou se o aplicativo de chamada não pertence a área de transferência.  
  
##  <a name="onrenderdata"></a>  COleDataSource::OnRenderData  
 Chamado pelo framework para recuperar dados no formato especificado.  
  
```  
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato no qual as informações são solicitadas.  
  
 *lpStgMedium*  
 Aponta para um [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura na qual os dados deve ser retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente na `COleDataSource` do objeto usando o [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) a função de membro para renderização atrasada. A implementação padrão dessa função chamará [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata) se a mídia de armazenamento fornecido é um arquivo ou a memória, respectivamente. Se nenhum desses formatos são fornecidos, a implementação padrão retornará 0 e não faça nada. Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Se *lpStgMedium*-> *tymed* é TYMED_NULL, o `STGMEDIUM` deve ser alocado e preenchido conforme especificado pelo *lpFormatEtc -> tymed*. Se não for TYMED_NULL, o `STGMEDIUM` deve ser preenchido em vigor com os dados.  
  
 Isso é um avançado substituível. Substitua essa função para fornecer seus dados no formato solicitado e média. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se os dados forem pequenos e com o tamanho fixo, substituir `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estruturas, a [TYMED](/windows/desktop/api/objidl/ne-objidl-tagtymed) tipo de enumeração, e [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) no Windows SDK.  
  
##  <a name="onrenderfiledata"></a>  COleDataSource::OnRenderFileData  
 Chamado pelo framework para recuperar dados no formato especificado quando a mídia de armazenamento especificado é um arquivo.  
  
```  
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,  
    CFile* pFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato no qual as informações são solicitadas.  
  
 *pFile*  
 Aponta para um [CFile](../../mfc/reference/cfile-class.md) objeto no qual os dados a serem renderizados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente na `COleDataSource` do objeto usando o [DelayRenderData](#delayrenderdata) a função de membro para renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.  
  
 Isso é um avançado substituível. Substitua essa função para fornecer seus dados no formato solicitado e média. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`. Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura e [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.  
  
##  <a name="onrenderglobaldata"></a>  COleDataSource::OnRenderGlobalData  
 Chamado pelo framework para recuperar dados no formato especificado quando a mídia de armazenamento especificado é memória global.  
  
```  
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,  
    HGLOBAL* phGlobal);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato no qual as informações são solicitadas.  
  
 *phGlobal*  
 Aponta para um identificador para a memória global no qual os dados deve ser retornado. Se um ainda não foi alocado, esse parâmetro pode ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente na `COleDataSource` do objeto usando o [DelayRenderData](#delayrenderdata) a função de membro para renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.  
  
 Se *phGlobal* for NULL, e em seguida, um novo HGLOBAL deve ser alocado e retornado na *phGlobal*. Caso contrário, o HGLOBAL especificado por *phGlobal* deve ser preenchido com os dados. A quantidade de dados colocados no HGLOBAL não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.  
  
 Isso é um avançado substituível. Substitua essa função para fornecer seus dados no formato solicitado e média. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substitua [OnRenderFileData](#onrenderfiledata). Para obter mais informações sobre renderização atrasada como manipulados por MFC, consulte o artigo [fontes de dados e objetos de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura e [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.  
  
##  <a name="onsetdata"></a>  COleDataSource::OnSetData  
 Chamado pelo framework para definir ou substituir os dados no `COleDataSource` objeto no formato especificado.  
  
```  
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium,  
    BOOL bRelease);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato de dados no qual está sendo substituídos.  
  
 *lpStgMedium*  
 Aponta para o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura que contém os dados que substituirão o conteúdo atual do `COleDataSource` objeto.  
  
 *bRelease*  
 Indica que é proprietária da mídia de armazenamento depois de concluir a chamada de função. O chamador decide quem é responsável por liberar os recursos alocados em nome da mídia de armazenamento. O chamador faz isso definindo *bRelease*. Se *bRelease* é diferente de zero, a fonte de dados assume a propriedade, liberando a mídia quando ele tiver terminado de usá-lo. Quando *bRelease* é 0, o chamador retém a propriedade e a fonte de dados pode usar a mídia de armazenamento apenas para a duração da chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A fonte de dados não assumir a propriedade dos dados até que ele tenha obtido-lo com êxito. Ou seja, ele não apropriar-se `OnSetData` retornará 0. Se a fonte de dados assume a propriedade, ela libera a mídia de armazenamento por meio da chamada a [ReleaseStgMedium](/windows/desktop/api/ole2/nf-ole2-releasestgmedium) função.  
  
 A implementação padrão não faz nada. Substitua essa função para substituir os dados no formato especificado. Isso é um avançado substituível.  
  
 Para obter mais informações, consulte o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estruturas e os [ReleaseStgMedium](/windows/desktop/api/ole2/nf-ole2-releasestgmedium) e [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) funções no SDK do Windows.  
  
##  <a name="setclipboard"></a>  COleDataSource::SetClipboard  
 Coloca os dados contidos na `COleDataSource` objeto na área de transferência depois de chamar uma das seguintes funções: [CacheData](#cachedata), [CacheGlobalData](#cacheglobaldata), [DelayRenderData](#delayrenderdata), ou [DelayRenderFileData](#delayrenderfiledata).  
  
```  
void SetClipboard();
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDataObject](../../mfc/reference/coledataobject-class.md)
