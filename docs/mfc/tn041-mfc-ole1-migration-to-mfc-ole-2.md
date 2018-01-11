---
title: "Tn041: migração MFC-OLE1 para MFC-OLE 2 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.mfc.ole
dev_langs: C++
helpviewer_keywords:
- OLE1 [MFC]
- migrating OLE1 to OLE2
- migration [MFC], OLE1 to OLE2
- OLE2 [MFC]
- porting OLE1 to OLE2
- converting OLE1 to OLE2
- upgrading Visual C++ applications [MFC], OLE1 to OLE2
- TN041
ms.assetid: 67f55552-4b04-4ddf-af0b-4d9eaf5da957
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 894c171c025ef125495faad21dba2a98c08e8b88
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn041-mfcole1-migration-to-mfcole-2"></a>TN041: migração de MFC/OLE1 para MFC/OLE 2
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
## <a name="general-issues-relating-to-migration"></a>Problemas gerais relacionados para migração  
 Uma das metas de design para as classes de 2 OLE no MFC 2.5 (e superior) era preservar grande parte da mesma arquitetura colocar no lugar no MFC 2.0 para suporte OLE 1.0. Como resultado, muitas das mesmas classes OLE no MFC 2.0 ainda existem nesta versão do MFC (`COleDocument`, `COleServerDoc`, `COleClientItem`, `COleServerItem`). Além disso, muitas das APIs dessas classes são exatamente iguais. No entanto, 2 OLE é totalmente diferente do OLE 1.0 para que você pode esperar que alguns dos detalhes foram alteradas. Se você estiver familiarizado com o suporte do MFC 2.0 OLE1, você se sentirá em casa com suporte 2.0 do MFC.  
  
 Se você colocar um aplicativo MFC/OLE1 existente e adicionar funcionalidade OLE 2 a ele, você deve primeiro ler esta anotação. Esta anotação aborda alguns problemas gerais, você pode encontrar ao portar sua funcionalidade OLE1 para MFC/OLE 2 e, em seguida, aborda os problemas descobertos durante a portabilidade de dois aplicativos incluídos no MFC 2.0: os exemplos de OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md).  
  
## <a name="mfc-documentview-architecture-is-important"></a>Arquitetura de documento/exibição MFC é importante  
 Se seu aplicativo não usar a arquitetura de documento/exibição do MFC e você deseja adicionar suporte OLE 2 para o seu aplicativo, agora é o momento para mover para a exibição de documentos. Muitos dos benefícios de classes de 2 OLE do MFC só são obtidos quando seu aplicativo está usando a arquitetura interna e os componentes do MFC.  
  
 A implementação de um servidor ou contêiner sem usar a arquitetura MFC é possível, mas não recomendado.  
  
## <a name="use-mfc-implementation-instead-of-your-own"></a>Usar a implementação do MFC em vez de seu próprio  
 Classes MFC "implementação gravados", como `CToolBar`, `CStatusBar`, e `CScrollView` internos código caso especial para suporte OLE 2. Portanto, se você pode usar essas classes em seu aplicativo você aproveitará o esforço colocá-los para torná-los OLE com suporte. Novamente, é possível "roll seu próprio" classes aqui para esses fins, mas não é recomendável. Se você precisa implementar uma funcionalidade semelhante, o código-fonte MFC é uma excelente referência para lidar com alguns dos pontos mais refinados de OLE (especialmente quando se trata de ativação no local).  
  
## <a name="examine-the-mfc-sample-code"></a>Examine o código de exemplo do MFC  
 Há um número de amostras MFC que incluem funcionalidade OLE. Cada um desses aplicativos implementa OLE de um ângulo diferente:  
  
- [HIERSVR](../visual-cpp-samples.md) destinam-se principalmente para uso como um aplicativo de servidor. Ele foi incluído no MFC 2.0 como um aplicativo MFC/OLE1 e foi movido para MFC/OLE 2 e, em seguida, estendido, de modo que ele implementa vários recursos OLE disponíveis no OLE 2.  
  
- [OCLIENT](../visual-cpp-samples.md) é um aplicativo autônomo do contêiner, destinado a demonstrar muitos dos recursos OLE de um ponto de vista do contêiner. Ele também foi movido do MFC 2.0 e então estendido para dar suporte a muitos dos recursos mais avançados do OLE, como formatos personalizados de área de transferência e links para itens incorporados.  
  
- [DRAWCLI](../visual-cpp-samples.md) esse aplicativo implementa o suporte de contêiner OLE muito como OCLIENT, exceto que ele faz isso dentro da estrutura de um programa de desenho e orientada a objeto existente. Ele mostra como implementar o suporte de contêiner OLE e integrá-lo em seu aplicativo existente.  
  
- [SUPERPAD](../visual-cpp-samples.md) esse aplicativo, bem como sendo um bom aplicativo autônomo, também é um servidor OLE. O suporte do servidor que ele implementa é bastante minimalista. De interesse específico é como ele usa os serviços de área de transferência OLE para copiar dados para a área de transferência, mas usa a funcionalidade criada no controle de edição"Windows" para implementar a funcionalidade de colar da área de transferência. Isso mostra uma mistura interessante de uso tradicional de API do Windows, bem como integração com o novo OLE APIs.  
  
 Para obter mais informações sobre os aplicativos de exemplo, consulte a "MFC exemplo ajuda".  
  
## <a name="case-study-oclient-from-mfc-20"></a>Estudo de caso: OCLIENT do MFC 2.0  
 Como discutido acima, [OCLIENT](../visual-cpp-samples.md) foi incluída no MFC 2.0 e implementado OLE com MFC/OLE1. As etapas que este aplicativo foi inicialmente convertido para usar as classes MFC/OLE 2 são descritas abaixo. Uma série de recursos foram adicionada depois que a porta inicial foi concluída para ilustrar melhor as classes MFC/OLE. Esses recursos não serão abordados aqui; Consulte o exemplo para obter mais informações sobre esses recursos avançados.  
  
> [!NOTE]
>  Os erros de compilador e o processo passo a passo foi criado com o Visual C++ 2.0. Locais e mensagens de erro específicas podem ter sido alterado com Visual C++ 4.0, mas as informações conceituais permanecem válidas.  
  
## <a name="getting-it-up-and-running"></a>-Lo e em execução  
 A abordagem usada para a porta do exemplo OCLIENT a MFC/OLE é iniciar compilá-la e corrigir os erros de compilador óbvio que resultarão. Se você usar o exemplo OCLIENT do MFC 2.0 e compilá-lo com esta versão do MFC, você encontrará que não haja muitos erros para resolver. Os erros na ordem em que elas ocorreram são descritos abaixo.  
  
## <a name="compile-and-fix-errors"></a>Compilação e corrigir erros  
  
```  
\oclient\mainview.cpp(104) : error C2660: 'Draw' : function does not take 4 parameters  
```  
  
 A primeira preocupação de erro `COleClientItem::Draw`. Em MFC/OLE1 demorou mais parâmetros do que a versão MFC/OLE usa. Os parâmetros adicionais foram geralmente não são necessários e normalmente NULL (como neste exemplo). Esta versão do MFC pode determinar os valores para o lpWBounds automaticamente quando o CDC que está sendo desenhado para é um controlador de domínio de metarquivo. Além disso, o parâmetro pFormatDC não é necessário porque a estrutura criará um do "atributo do controlador de domínio" do pDC passado. Portanto para corrigir esse problema, basta remover as duas extra NULL parâmetros para a chamada de desenho.  
  
```  
\oclient\mainview.cpp(273) : error C2065: 'OLE_MAXNAMESIZE' : undeclared identifier  
\oclient\mainview.cpp(273) : error C2057: expected constant expression  
\oclient\mainview.cpp(280) : error C2664: 'CreateLinkFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '  
\oclient\mainview.cpp(286) : error C2664: 'CreateFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '  
\oclient\mainview.cpp(288) : error C2664: 'CreateStaticFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '  
```  
  
 Os erros acima resultado do fato de que todos os **COleClientItem::CreateXXXX** funções em MFC/OLE1 necessário que um nome exclusivo passadas para representar o item. Isso era um requisito de OLE API subjacente. Isso não é necessário no MFC/OLE 2 como 2 OLE não usa o DDE como o mecanismo de comunicação subjacente (o nome foi usado em conversas DDE). Para corrigir esse problema, você pode remover o **CreateNewName** de função, bem como todas as referências a ele. É fácil de descobrir o que cada função MFC/OLE é esperado nesta versão simplesmente, colocando o cursor na chamada e pressionando F1.  
  
 Outra área que é significativamente diferente é tratamento de área de transferência OLE 2. Com OLE1, você usou a transferência do Windows que APIs interagem com a área de transferência. Com o OLE 2, isso é feito com um mecanismo diferente. As APIs MFC/OLE1 assumido que a área de transferência foi aberta antes de copiar um `COleClientItem` objeto para a área de transferência. Isso não é mais necessário e fará com que todas as operações de área de transferência do MFC/OLE falha. Enquanto você editar o código para remover dependências em **CreateNewName**, você também deve remover o código que abre e fecha a área de transferência do Windows.  
  
```  
\oclient\mainview.cpp(332) : error C2065: 'AfxOleInsertDialog' : undeclared identifier  
\oclient\mainview.cpp(332) : error C2064: term does not evaluate to a function  
\oclient\mainview.cpp(344) : error C2057: expected constant expression  
\oclient\mainview.cpp(347) : error C2039: 'CreateNewObject' : is not a member of 'CRectItem'  
```  
  
 Esses erros são provenientes de **CMainView::OnInsertObject** manipulador. Tratar o comando "Inserir o novo objeto" é outra área em que as coisas tenham mudado um pouco. Nesse caso, é mais fácil simplesmente mesclar a implementação original com aquela fornecida pelo AppWizard para um novo aplicativo de contêiner OLE. Na verdade, essa é uma técnica que você pode aplicar a portabilidade de outros aplicativos. Em MFC/OLE1, é exibida a caixa de diálogo 'Inserir objeto' chamando **AfxOleInsertDialog** função. Nesta versão, você construir um **COleInsertObject** o objeto de caixa de diálogo e chame `DoModal`. Além disso, novos itens OLE são criados com um **CLSID** em vez de uma cadeia de caracteres do nome da classe. O resultado final deve ser semelhante este  
  
```  
COleInsertDialog dlg;  
if (dlg.DoModal() != IDOK)  
    return; 
 
BeginWaitCursor();

 
CRectItem* pItem = NULL;  
TRY  
{ *// First create the C++ object  
    pItem = GetDocument()->CreateItem();
ASSERT_VALID(pItem);

 *// Initialize the item from the dialog data.  
    if (!dlg.CreateItem(pItem))  
    AfxThrowMemoryException();
*// any exception will do  
    ASSERT_VALID(pItem);

 *// run the object if appropriate  
    if (dlg.GetSelectionType() == 
    COleInsertDialog::createNewItem) 
    pItem->DoVerb(OLEIVERB_SHOW,
    this);

 *// update right away  
    pItem->UpdateLink();
pItem->UpdateItemRectFromServer();

 *// set selection to newly inserted item  
    SetSelection(pItem);

 pItem->Invalidate();

}  
CATCH (CException,
    e)  
{ *// clean up item  
    if (pItem != NULL)  
    GetDocument()->DeleteItem(pItem);

 
    AfxMessageBox(IDP_FAILED_TO_CREATE);

} 
END_CATCH  
 
EndWaitCursor();
```  
  
> [!NOTE]
>  Inserir novo objeto pode ser diferente para seu aplicativo):  
  
 Também é necessário incluir \<afxodlgs.h >, que contém a declaração para o **COleInsertObject** classe de caixa de diálogo, bem como as outras caixas de diálogo padrão fornecidas pelo MFC.  
  
```  
\oclient\mainview.cpp(367) : error C2065: 'OLEVERB_PRIMARY' : undeclared identifier  
\oclient\mainview.cpp(367) : error C2660: 'DoVerb' : function does not take 1 parameters  
```  
  
 Esses erros são causados pelo fato de que algumas constantes OLE1 foram alterados em OLE 2, embora o conceito sejam os mesmos. Nesse caso **OLEVERB_PRIMARY** foi alterado para `OLEIVERB_PRIMARY`. OLE1 e OLE 2, o verbo primário geralmente é executado por um contêiner quando o usuário clica duas vezes em um item.  
  
 Além disso, `DoVerb` agora assume um parâmetro extra — um ponteiro para um modo de exibição (`CView`*). Esse parâmetro só é usado para implementar "Edição Visual" (ou a ativação no local). Agora você definir esse parâmetro como NULL, porque você não está implementando esse recurso no momento.  
  
 Para certificar-se de que a estrutura nunca tenta in-loco ativar, você deve substituir `COleClientItem::CanActivate` da seguinte maneira:  
  
```  
BOOL CRectItem::CanActivate()  
{  
    return FALSE;  
}  
 
\oclient\rectitem.cpp(53) : error C2065: 'GetBounds' : undeclared identifier  
\oclient\rectitem.cpp(53) : error C2064: term does not evaluate to a function  
\oclient\rectitem.cpp(84) : error C2065: 'SetBounds' : undeclared identifier  
\oclient\rectitem.cpp(84) : error C2064: term does not evaluate to a function  
```  
  
 Em MFC/OLE1, **COleClientItem::GetBounds** e **SetBounds** foram usadas para consultar e manipular a extensão de um item (o **esquerdo** e **superior**membros foram sempre zero). Em MFC/OLE 2 isso é mais diretamente suportado por `COleClientItem::GetExtent` e `SetExtent`, que lidam com uma **tamanho** ou `CSize` em vez disso.  
  
 O código para seu novo SetItemRectToServer, e chamadas UpdateItemRectFromServer ter esta aparência:  
  
```  
BOOL CRectItem::UpdateItemRectFromServer()  
{  
    ASSERT(m_bTrackServerSize);

 CSize size;  
    if (!GetExtent(&size))  
    return FALSE;    // blank  
 *// map from HIMETRIC to screen coordinates  
 {  
    CClientDC screenDC(NULL);

    screenDC.SetMapMode(MM_HIMETRIC);

 screenDC.LPtoDP(&size);

 } *// just set the item size  
    if (m_rect.Size() != size)  
 { *// invalidate the old size/position  
    Invalidate();
m_rect.right = m_rect.left + size.cx;  
    m_rect.bottom = m_rect.top + size.cy; *// as well as the new size/position  
    Invalidate();

 }  
    return TRUE;  
}  
 
BOOL CRectItem::SetItemRectToServer()  
{ *// set the official bounds for the embedded item  
    CSize size = m_rect.Size();

 {  
    CClientDC screenDC(NULL);

    screenDC.SetMapMode(MM_HIMETRIC);

 screenDC.DPtoLP(&size);

 }  
    TRY 
 {  
    SetExtent(size);
*// may do a wait  
 }  
    CATCH(CException, e)  
 {  
    return FALSE;  // links will not allow SetBounds  
 }  
    END_CATCH 
    return TRUE;  
}  
 
\oclient\frame.cpp(50) : error C2039: 'InWaitForRelease' : is not a member of 'COleClientItem'  
\oclient\frame.cpp(50) : error C2065: 'InWaitForRelease' : undeclared identifier  
\oclient\frame.cpp(50) : error C2064: term does not evaluate to a function  
```  
  
 Na API síncrona MFC/OLE1 chamadas de um contêiner para um servidor foram *simulada*, pois OLE1 foi inerentemente assíncrona em muitos casos. É necessário verificar se há uma chamada assíncrona pendente em andamento antes de processar comandos do usuário. MFC/OLE1 fornecido a **COleClientItem::InWaitForRelease** função para fazer isso. Em MFC/OLE 2 isso não é necessário, para que você possa remover a substituição de OnCommand CMainFrame juntos.  
  
 Neste ponto, OCLIENT irá compilar e vincular.  
  
## <a name="other-necessary-changes"></a>Outras alterações necessárias  
 Há algumas coisas que não são feitas que evitará OCLIENT em execução, no entanto. É melhor corrigir esses problemas agora, em vez de mais tarde.  
  
 Primeiro, é necessário inicializar as bibliotecas OLE. Isso é feito chamando **AfxOleInit** de `InitInstance`:  
  
```  
if (!AfxOleInit())  
{  
    AfxMessageBox("Failed to initialize OLE libraries");

    return FALSE;  
}  
```  
  
 Também é uma boa ideia verificar funções virtuais para alterações da lista de parâmetros. É uma função `COleClientItem::OnChange`, substituídos em cada aplicativo de contêiner MFC/OLE. Ao examinar a Ajuda online, você verá que um extra 'DWORD dwParam' foi adicionado. O novo CRectItem::OnChange será semelhante ao seguinte:  
  
```  
void   
CRectItem::OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam)  
{  
    if (m_bTrackServerSize&& 
 !UpdateItemRectFromServer())  
 { *// Blank object  
    if (wNotification == OLE_CLOSED)  
 { *// no data received for the object - destroy it  
    ASSERT(!IsVisible());

 GetDocument()->DeleteItem(this);

    return; // no update (item is gone now)  
 }  
 }  
    if (wNotification != OLE_CLOSED)  
    Dirty();
Invalidate();
*// any change will cause a redraw  
}  
```  
  
 Em MFC/OLE1, aplicativos de contêiner derivada a classe de documento do **COleClientDoc**. Em MFC/OLE 2 essa classe foi removida e substituída pelo `COleDocument` (essa nova organização facilita a criação de aplicativos de contêiner/servidor). Há um `#define` que mapeia **COleClientDoc** para `COleDocument` para simplificar a portabilidade de aplicativos MFC/OLE1 para MFC/OLE 2, como OCLIENT. Um dos recursos não fornecidos pelo `COleDocument` que foi fornecida pelo **COleClientDoc** é a mensagem de comando padrão entradas do mapa. Isso é feito isso que aplicativos de servidor, que também usam `COleDocument` (indiretamente), não serão transferidos com eles a sobrecarga desses manipuladores de comando, a menos que eles são um aplicativo de contêiner/servidor. É necessário adicionar as seguintes entradas no mapa de mensagem CMainDoc:  
  
```  
ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE,
    OnUpdatePasteMenu)  
ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK,
    OnUpdatePasteLinkMenu)  
ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS,
    OnUpdateEditLinksMenu)  
ON_COMMAND(ID_OLE_EDIT_LINKS,
    COleDocument::OnEditLinks)  
ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST,
    OnUpdateObjectVerbMenu)  
ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT,
    OnUpdateObjectVerbMenu)  
ON_COMMAND(ID_OLE_EDIT_CONVERT,
    OnEditConvert)  
```  
  
 É a implementação de todos esses comandos em `COleDocument`, que é a classe base para o documento.  
  
 Neste ponto, OCLIENT é um aplicativo de contêiner OLE funcional. É possível inserir itens de qualquer tipo (OLE1 ou OLE 2). Desde que o código necessário para habilitar a ativação no local não é implementado, os itens são editados em uma janela separada que funcionam como com OLE1. A próxima seção discute as alterações necessárias para habilitar a edição no local (às vezes chamado de "Edição Visual").  
  
## <a name="adding-visual-editing"></a>Adicionando "Edição Visual"  
 Um dos recursos mais interessantes de OLE é ativação no local (ou "Edição Visual"). Esse recurso permite que o aplicativo de servidor assumir partes da interface de usuário do contêiner fornecido uma interface de edição mais consistente para o usuário. Para implementar a ativação no local OCLIENT, alguns recursos especiais precisam ser adicionados, bem como um código adicional. Esses recursos e o código normalmente são fornecidas pelo AppWizard — na verdade, grande parte do código aqui foi emprestado diretamente a partir de um novo aplicativo de AppWizard com suporte "Contêiner".  
  
 Em primeiro lugar, é necessário adicionar um recurso de menu a ser usado quando há um item que está ativo no local. Você pode criar esse recurso de menu adicionais no Visual C++, copiando o recurso IDR_OCLITYPE e remoção de todos, exceto os arquivo e a janela pop-ups. Duas barras de separação são inseridas entre os arquivo e janela pop-ups para indicar a separação de grupos (deve se parecer com: arquivo &#124; &#124; Janela). Para obter mais informações sobre o que significam esses separadores e como os menus do contêiner e de servidor são mesclados consulte "Menus e recursos: mesclagem de Menu" *OLE 2 Classes*.  
  
 Uma vez que esses menus criados, você precisa informar o framework sobre eles. Isso é feito chamando `CDocTemplate::SetContainerInfo` para o modelo de documento antes de adicioná-lo à lista de modelo de documento no seu InitInstance. O novo código para registrar o modelo de documento tem esta aparência:  
  
```  
CDocTemplate* pTemplate = new CMultiDocTemplate(
    IDR_OLECLITYPE, 
    RUNTIME_CLASS(CMainDoc), 
    RUNTIME_CLASS(CMDIChildWnd), // standard MDI child frame  
    RUNTIME_CLASS(CMainView));

pTemplate->SetContainerInfo(IDR_OLECLITYPE_INPLACE);

AddDocTemplate(pTemplate);
```   
  
 O recurso IDR_OLECLITYPE_INPLACE é um recurso local especial criado no Visual C++.  
  
 Para habilitar a ativação no local, há algumas coisas que precisam alterar em ambos os `CView` (CMainView) a classe derivada, bem como a `COleClientItem` (CRectItem) de classe derivada. Todas essas substituições são fornecidas pelo AppWizard e a maioria da implementação virão diretamente de um aplicativo de AppWizard padrão.  
  
 Na primeira etapa desta porta, a ativação no local foi desabilitada inteiramente substituindo `COleClientItem::CanActivate`. Essa substituição deve ser removida para permitir a ativação no local. Além disso, nulo foi passado para todas as chamadas para `DoVerb` (há duas delas) porque fornecer o modo de exibição somente era necessária para a ativação no local. Para implementar completamente a ativação no local, é necessário passar a exibição correta no `DoVerb` chamar. Uma dessas chamadas está em **CMainView::OnInsertObject**:  
  
```  
pItem->DoVerb(OLEIVERB_SHOW, this);
```  
  
 Outro está em **CMainView::OnLButtonDblClk**:  
  
```  
m_pSelection->DoVerb(OLEIVERB_PRIMARY, this);
```  
  
 É necessário substituir `COleClientItem::OnGetItemPosition`. Isso informa ao servidor onde colocar sua janela relativa à janela do contêiner quando o item está ativado no local. Para OCLIENT, a implementação é simples:  
  
```  
void CRectItem::OnGetItemPosition(CRect& rPosition)  
{  
    rPosition = m_rect;  
}  
```  
  
 A maioria dos servidores também implementam o que é chamado de "in-loco redimensionando." Isso permite que a janela do servidor ser dimensionada e movidos enquanto o usuário estiver editando o item. O contêiner deve participar esta ação, como mover ou redimensionar a janela geralmente afeta a posição e tamanho no próprio documento contêiner. A implementação para OCLIENT sincroniza o retângulo interno mantido pelo m_rect com a nova posição e tamanho.  
  
```  
BOOL CRectItem::OnChangeItemPosition(const CRect& rectPos)  
{  
    ASSERT_VALID(this);

 
    if (!COleClientItem::OnChangeItemPosition(rectPos))  
    return FALSE;  
 
    Invalidate();
m_rect = rectPos;  
    Invalidate();
GetDocument()->SetModifiedFlag();

 
    return TRUE;  
}  
```  
  
 Neste ponto, há código suficiente para permitir que um item a ser ativado no local e para lidar com dimensionamento e a movimentação do item quando ele estiver ativo, mas nenhum código permite que o usuário encerra a sessão de edição. Embora alguns servidores fornecem essa funcionalidade próprios manipulando a chave de escape, é recomendável que os contêineres fornecem duas maneiras para desativar um item: (1) clicando fora do item e (2), pressionando a tecla ESC.  
  
 Para a chave ESCAPE, adicionar um acelerador com Visual C++ que a chave VK_ESCAPE é mapeado para um comando, ID_CANCEL_EDIT é adicionado aos recursos. O manipulador desse comando é:  
  
```  
// The following command handler provides the standard  
// keyboard user interface to cancel an in-place  
// editing session.void CMainView::OnCancelEdit()  
{ *// Close any in-place active item on this view.  
    COleClientItem* pActiveItem = 
    GetDocument()->GetInPlaceActiveItem(this);

 if (pActiveItem != NULL)  
    pActiveItem->Close();
ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);

}  
```  
  
 Para lidar com o caso em que o usuário clica fora do item, adicione o seguinte código ao início da **CMainView::SetSelection**:  
  
```  
if (pNewSel != m_pSelection || pNewSel == NULL)  
{  
    COleClientItem* pActiveItem = 
    GetDocument()->GetInPlaceActiveItem(this);

 if (pActiveItem != NULL&& pActiveItem != pNewSel)  
    pActiveItem->Close();

} 
 
```  
  
 Quando um item está ativo no local, ele deve ter o foco. Para verificar se que esse for o caso, você manipula OnSetFocus para que o foco sempre é transferido para o item ativo quando o modo de exibição recebe o foco:  
  
```  
// Special handling of OnSetFocus and OnSize are required   
// when an object is being edited in-place.  
void CMainView::OnSetFocus(CWnd* pOldWnd)  
{  
    COleClientItem* pActiveItem = 
    GetDocument()->GetInPlaceActiveItem(this);

 if (pActiveItem != NULL&& 
    pActiveItem->GetItemState() == COleClientItem::activeUIState)  
 { *// need to set focus to this item if it is same view  
    CWnd* pWnd = pActiveItem->GetInPlaceWindow();
if (pWnd != NULL)  
 {  
    pWnd->SetFocus();
*// don't call the base class  
    return; 
 }  
 }  
 
    CView::OnSetFocus(pOldWnd);

} 
```  
  
 Quando o modo de exibição é redimensionado, você precisa notificar o item ativo que alterou o retângulo de recorte. Para fazer isso é fornecer um manipulador para `OnSize`:  
  
```  
void CMainView::OnSize(UINT nType,
    int cx,
    int cy)  
{  
    CView::OnSize(nType,
    cx,
    cy);

    COleClientItem* pActiveItem = 
    GetDocument()->GetInPlaceActiveItem(this);

 if (pActiveItem != NULL)  
    pActiveItem->SetItemRects();

} 
```  
  
## <a name="case-study-hiersvr-from-mfc-20"></a>Estudo de caso: HIERSVR do MFC 2.0  
 [HIERSVR](../visual-cpp-samples.md) também foi incluído no MFC 2.0 e implementado OLE com MFC/OLE1. Esta anotação descreve brevemente as etapas pelo qual este aplicativo foi inicialmente convertido para usar as classes MFC/OLE 2. Uma série de recursos foram adicionada depois que a porta inicial foi concluída para ilustrar melhor as classes MFC/OLE 2. Esses recursos não serão abordados aqui; Consulte o exemplo para obter mais informações sobre esses recursos avançados.  
  
> [!NOTE]
>  Os erros de compilador e o processo passo a passo foi criado com o Visual C++ 2.0. Locais e mensagens de erro específicas podem ter sido alterado com Visual C++ 4.0, mas as informações conceituais permanecem válidas.  
  
## <a name="getting-it-up-and-running"></a>-Lo e em execução  
 A abordagem usada para a porta do exemplo HIERSVR a MFC/OLE é iniciar compilá-la e corrigir os erros de compilador óbvio que resultarão. Se você usar o exemplo HIERSVR do MFC 2.0 e compilá-lo com esta versão do MFC, você encontrará que não haja muitos erros para resolver (embora não haja mais de com o exemplo OCLIENT). Os erros na ordem em que eles ocorrem normalmente são descritos abaixo.  
  
## <a name="compile-and-fix-errors"></a>Compilação e corrigir erros  
  
```  
\hiersvr\hiersvr.cpp(83) : error C2039: 'RunEmbedded' : is not a member of 'COleTemplateServer'  
```  
  
 O primeiro erro indica um maior problema com o `InitInstance` função para servidores. A inicialização necessária para um servidor OLE é provavelmente uma das maiores alterações que você precisa fazer ao seu aplicativo do MFC/OLE1 para executá-lo. A melhor coisa a fazer é examinar o que AppWizard cria para um servidor OLE e modificar seu código conforme apropriado. Aqui estão alguns pontos a serem considerados:  
  
 É necessário inicializar as bibliotecas OLE chamando **AfxOleInit**  
  
 Chamar SetServerInfo no objeto de modelo de documento para definir identificadores de recursos de servidor e informações de classe de tempo de execução não pode ser definida com o `CDocTemplate` construtor.  
  
 Não mostra a janela principal do seu aplicativo se a opção /Embedding está presente na linha de comando.  
  
 Você precisará de um **GUID** do seu documento. Este é um identificador exclusivo para o tipo do documento (128 bits). AppWizard será criada para você, portanto, se você usar a técnica descrita aqui de copiar o novo código de um novo aplicativo de servidor AppWizard gerado, você pode simplesmente "roubar" o GUID do aplicativo. Caso contrário, você pode usar o GUIDGEN. Utilitário EXE no diretório BIN.  
  
 É necessário para "conectar" seu `COleTemplateServer` objeto para o modelo de documento chamando `COleTemplateServer::ConnectTemplate`.  
  
 Atualize o registro do sistema quando seu aplicativo for executado autônomo. Dessa forma, se o usuário move o. EXE para o seu aplicativo, executá-lo em seu novo local atualizará o banco de dados de registro do Windows system para apontar para o novo local.  
  
 Após a aplicação de todas essas alterações com base no qual AppWizard cria para `InitInstance`, o `InitInstance` (e relacionados GUID) para HIERSVR deve ser o seguinte:  
  
```  
// this is the GUID for HIERSVR documents  
static const GUID BASED_CODE clsid = 
 { 0xA0A16360L,
    0xC19B,
    0x101A, { 0x8C,
    0xE5,
    0x00,
    0xDD,
    0x01,
    0x11,
    0x3F,
    0x12 } };  
 
/////////////////////////////////////////////////////////////////////////////  
// COLEServerApp initialization  
 
BOOL COLEServerApp::InitInstance()  
{ *// OLE 2 initialization  
    if (!AfxOleInit())  
 {  
    AfxMessageBox("Initialization of the OLE failed!");

    return FALSE;  
 }  
 *// Standard initialization  
    LoadStdProfileSettings();

// Load standard INI file options   
 *// Register document templates  
    CDocTemplate* pDocTemplate;  
    pDocTemplate = new CMultiDocTemplate(IDR_HIERSVRTYPE,  
    RUNTIME_CLASS(CServerDoc), 
    RUNTIME_CLASS(CMDIChildWnd), 
    RUNTIME_CLASS(CServerView));

 pDocTemplate->SetServerInfo(IDR_HIERSVRTYPE_SRVR_EMB);

    AddDocTemplate(pDocTemplate);

 *// create main MDI Frame window  
    CMainFrame* pMainFrame = new CMainFrame;  
    if (!pMainFrame->LoadFrame(IDR_MAINFRAME))  
    return FALSE;  
    m_pMainWnd = pMainFrame;  
 
    SetDialogBkColor();
*// gray look  
 *// enable file manager drag/drop and DDE Execute open  
    m_pMainWnd->DragAcceptFiles();
EnableShellOpen();

 
    m_server.ConnectTemplate(clsid,
    pDocTemplate,
    FALSE);

    COleTemplateServer::RegisterAll();

 *// try to launch as an OLE server  
    if (RunEmbedded())  
 { *// "short-circuit" initialization -- run as server!  
    return TRUE;  
 }  
    m_server.UpdateRegistry();
RegisterShellFileTypes();

 *// not run as OLE server,
    so show the main window  
    if (m_lpCmdLine[0] == '\0')  
 { *// create a new (empty) document  
    OnFileNew();

 }  
    else 
 { *// open an existing document  
    OpenDocumentFile(m_lpCmdLine);

 }  
 
    pMainFrame->ShowWindow(m_nCmdShow);

 pMainFrame->UpdateWindow();

 
    return TRUE;  
}  
```  
  
 Você observará que o código acima se refere a uma nova ID de recurso, IDR_HIERSVRTYPE_SRVR_EMB. Este é o recurso de menu a ser usado quando um documento incorporado em outro contêiner é editado. Em MFC/OLE1 os itens de menu específicos para editar um item inserido foram modificados em tempo real. Usar uma estrutura de menu completamente diferente ao editar um item inserido em vez de editar um documento baseado em arquivo torna mais fácil fornecer interfaces de usuário diferentes para esses dois modos separados. Como você verá posteriormente, um recurso de menu totalmente separada será usado para editar um objeto inserido no local.  
  
 Para criar esse recurso, carregar o script de recurso no Visual C++ e copiar o recurso de menu IDR_HIERSVRTYPE existente. Renomeie o novo recurso para IDR_HIERSVRTYPE_SRVR_EMB (essa é a mesma convenção de nomenclatura que usa AppWizard). Em seguida alterar "Salvar arquivo" para "Atualização do arquivo"; Dê a ele ID de comando **ID_FILE_UPDATE**. Também alterar "Arquivo-Salvar como" para "Arquivo Salvar cópia como"; Dê a ele ID de comando **ID_FILE_SAVE_COPY_AS**. O framework fornece a implementação de ambos esses comandos.  
  
```  
\hiersvr\svritem.h(60) : error C2433: 'OLESTATUS' : 'virtual' not permitted on data declarations  
\hiersvr\svritem.h(60) : error C2501: 'OLESTATUS' : missing decl-specifiers  
\hiersvr\svritem.h(60) : error C2146: syntax error : missing ';' before identifier 'OnSetData'  
\hiersvr\svritem.h(60) : error C2061: syntax error : identifier 'OLECLIPFORMAT'  
\hiersvr\svritem.h(60) : error C2501: 'OnSetData' : missing decl-specifiers  
```  
  
 Há um número de erros resultantes de substituição do `OnSetData`, pois ele está se referindo a **OLESTATUS** tipo. **OLESTATUS** era a maneira OLE1 retornados os erros. Isso foi alterado para `HRESULT` OLE 2, embora MFC geralmente converte um `HRESULT` em um `COleException` que contém o erro. Nesse caso específico, a substituição de `OnSetData` não é mais necessário, para o mais fácil de fazer é removê-lo.  
  
```  
\hiersvr\svritem.cpp(30) : error C2660: 'COleServerItem::COleServerItem' : function does not take 1 parameters  
```  
  
 O `COleServerItem` construtor aceita um parâmetro de 'BOOL' extra. Esse sinalizador que determina como o gerenciamento de memória é feito na `COleServerItem` objetos. Definindo-a como TRUE, a estrutura lida com o gerenciamento de memória desses objetos — excluí-los quando eles não são mais necessários. Usa HIERSVR **CServerItem** (derivado de `COleServerItem`) objetos como parte de seus dados nativo, para que você vai definir esse sinalizador como FALSE. Isso permite HIERSVR determinar quando cada item do servidor é excluído.  
  
```  
\hiersvr\svritem.cpp(44) : error C2259: 'CServerItem' : illegal attempt to instantiate abstract class  
\hiersvr\svritem.cpp(44) : error C2259: 'CServerItem' : illegal attempt to instantiate abstract class  
```  
  
 Como esses erros implicam, há algumas funções 'puro virtual' que não foram substituídas no CServerItem. Provavelmente, isso é causado pelo fato de que a lista de parâmetros do OnDraw foi alterado. Para corrigir esse erro, altere **CServerItem::OnDraw** da seguinte maneira (bem como a declaração no svritem.h):  
  
```  
BOOL CServerItem::OnDraw(CDC* pDC,
    CSize& rSize)  
{ *// request from OLE to draw node  
    pDC->SetMapMode(MM_TEXT);

// always in pixels  
    return DoDraw(pDC,
    CPoint(0,
    0),
    FALSE);

}  
```  
  
 O novo parâmetro é 'rSize'. Isso permite que você preencha o tamanho do desenho, se for conveniente. Esse tamanho deve estar no **HIMETRIC**. Nesse caso, não é conveniente preencher esse valor, portanto, o framework chama `OnGetExtent` para recuperar a extensão. Para que isso funcione, você precisará implementar `OnGetExtent`:  
  
```  
BOOL CServerItem::OnGetExtent(DVASPECT dwDrawAspect,
    CSize& rSize)  
{  
    if (dwDrawAspect != DVASPECT_CONTENT)  
    return COleServerItem::OnGetExtent(dwDrawAspect,
    rSize);

 
    rSize = CalcNodeSize();
return TRUE;  
}  
 
\hiersvr\svritem.cpp(104) : error C2065: 'm_rectBounds' : undeclared identifier  
\hiersvr\svritem.cpp(104) : error C2228: left of '.SetRect' must have class/struct/union type  
\hiersvr\svritem.cpp(106) : error C2664: 'void __pascal __far DPtoLP(struct ::tagPOINT __far *,
    int)__far const ' : cannot convert parameter 1 from 'int __far *' to 'struct ::tagPOINT __far *'  
```  
  
 Na função CServerItem::CalcNodeSize o tamanho do item é convertido em **HIMETRIC** e armazenados em **m_rectBounds**. O não documentado '**m_rectBounds**' membro de `COleServerItem` não existe (foi parcialmente substituído por `m_sizeExtent`, mas em OLE 2 esse membro possui um uso ligeiramente diferente que **m_rectBounds**no OLE1). Em vez de configuração o **HIMETRIC** tamanho nessa variável de membro, você poderá retorná-la. Esse valor de retorno é usado em `OnGetExtent`, implementado anteriormente.  
  
```  
CSize CServerItem::CalcNodeSize()  
{  
    CClientDC dcScreen(NULL);

 
    m_sizeNode = dcScreen.GetTextExtent(m_strDescription,  
    m_strDescription.GetLength());

 m_sizeNode += CSize(CX_INSET* 2,
    CY_INSET* 2);

 *// set suggested HIMETRIC size  
    CSize size(m_sizeNode.cx,
    m_sizeNode.cy);

    dcScreen.SetMapMode(MM_HIMETRIC);

 dcScreen.DPtoLP(&size);

    return size;  
}  
```  
  
 Também substitui CServerItem **COleServerItem::OnGetTextData**. Essa função está obsoleta em MFC/OLE e é substituída por um mecanismo diferente. A versão 3.0 do MFC do MFC OLE exemplo [HIERSVR](../visual-cpp-samples.md) implementa essa funcionalidade, substituindo `COleServerItem::OnRenderFileData`. Essa funcionalidade não é importante para essa porta básica, portanto você pode remover a substituição de OnGetTextData.  
  
 Há muitos mais erros na svritem.cpp que não foram resolvidos. Eles não são erros de "reais" – apenas erros devidos a erros anteriores.  
  
```  
\hiersvr\svrview.cpp(325) : error C2660: 'CopyToClipboard' : function does not take 2 parameters  
```  
  
 `COleServerItem::CopyToClipboard`não suporta o sinalizador 'bIncludeNative'. Os dados nativos (os dados gravados pela função de serialização do item de servidor) sempre são copiados para remover o primeiro parâmetro. Além disso, `CopyToClipboard` lançará uma exceção quando ocorre um erro em vez de retornar FALSE. Altere o código de CServerView::OnEditCopy da seguinte maneira:  
  
```  
void CServerView::OnEditCopy()  
{  
    if (m_pSelectedNode == NULL)  
    AfxThrowNotSupportedException();

 
    TRY 
 {  
    m_pSelectedNode->CopyToClipboard(TRUE);

 }  
    CATCH_ALL(e) 
 {  
    AfxMessageBox("Copy to clipboard failed");

 }  
    END_CATCH_ALL 
}  
```  
  
 Embora houvesse mais erros resultantes de compilação da versão 2.0 do MFC do HIERSVR que ocorreram para a mesma versão do OCLIENT, havia realmente menos alterações.  
  
 Neste ponto HIERSVR compilar e vincular e funcionar como um servidor OLE, mas sem o recurso de edição no local, que será implementado em seguida.  
  
## <a name="adding-visual-editing"></a>Adicionando "Edição Visual"  
 Para adicionar "Edição Visual" (ou a ativação no local) para este aplicativo de servidor, há apenas algumas coisas que você precisa se encarregar:  
  
-   Você precisa de um recurso de menu especial a ser usado quando o item está ativo no local.  
  
-   Este aplicativo tem uma barra de ferramentas, por isso você terá uma barra de ferramentas com apenas um subconjunto da barra de ferramentas normal para corresponder os comandos de menu disponíveis no servidor (coincide com o recurso de menu mencionado acima).  
  
-   Você precisa de uma nova classe derivada de `COleIPFrameWnd` que fornece a interface de usuário local (assim como CMainFrame, derivada de `CMDIFrameWnd`, fornece a interface de usuário MDI).  
  
-   Você precisa informar o framework sobre esses recursos especiais e classes.  
  
 O recurso de menu é fácil de criar. Execute o Visual C++, copie o recurso de menu IDR_HIERSVRTYPE para um recurso de menu chamado IDR_HIERSVRTYPE_SRVR_IP. Modifique o menu para que somente as edição e a Ajuda do menu pop-ups estão à esquerda. Adicionar dois separadores ao menu entre menus editar e ajuda (deve se parecer com: Editar &#124; &#124; Ajuda). Para obter mais informações sobre o que significam esses separadores e como os menus do contêiner e de servidor são mesclados, consulte "Menus e recursos: mesclagem de Menu" *OLE 2 Classes*.  
  
 O bitmap da barra de ferramentas do subconjunto pode ser criado facilmente, copiando um de um aplicativo AppWizard gerado atualizado com uma opção "Servidor" marcada. Este bitmap pode ser importado para o Visual C++. Certifique-se de dar a um ID de IDR_HIERSVRTYPE_SRVR_IP o bitmap.  
  
 A classe derivada de `COleIPFrameWnd` podem ser copiadas de um aplicativo AppWizard gerado com o suporte do servidor também. Copie os dois arquivos, IPFRAME. CPP e IPFRAME. H e adicioná-los ao projeto. Verifique se o `LoadBitmap` chamada refere-se ao IDR_HIERSVRTYPE_SRVR_IP, o bitmap criado na etapa anterior.  
  
 Agora que todos os novos recursos e classes são criadas, adicione o código necessário para que a estrutura sabe sobre esses (e sabe que esse aplicativo agora oferece suporte a edição no local). Isso é feito pela adição de mais alguns parâmetros para o `SetServerInfo` chamar o `InitInstance` função:  
  
```  
pDocTemplate->SetServerInfo(IDR_HIERSVRTYPE_SRVR_EMB,  
    IDR_HIERSVRTYPE_SRVR_IP,
    RUNTIME_CLASS(CInPlaceFrame));
```  
  
 Agora está pronto para ser executado no local em qualquer contêiner que também oferece suporte à ativação no local. Mas, há um bug secundário que ainda escondido no código. HIERSVR oferece suporte a um menu de contexto exibido quando o usuário pressiona o botão direito do mouse. Esse menu funciona quando HIERSVR está totalmente aberto, mas não funciona quando você editar um inserção no local. O motivo pode ser fixado para baixo para essa única linha de código em CServerView::OnRButtonDown:  
  
```  
pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,  
    point.x,
    point.y,
    AfxGetApp()->m_pMainWnd);
```  
  
 Observe a referência ao **AfxGetApp() -> m_pMainWnd**. Quando o servidor está ativado no local, ele tem uma janela principal e m_pMainWnd está definida, mas é geralmente invisível. Além disso, essa janela refere-se para o *principal* janela do aplicativo, a janela do quadro MDI que aparece quando o servidor está totalmente abrir ou executar autônoma. Ele não faz referência para a janela do quadro ativo — que quando in-loco ativado é um quadro de janela derivadas de `COleIPFrameWnd`. Para obter a janela ativa correta, mesmo quando o local de edição, esta versão do MFC adiciona uma nova função, `AfxGetMainWnd`. Geralmente, você deve usar essa função em vez de **AfxGetApp() -> m_pMainWnd**. Esse código precisa da seguinte forma:  
  
```  
pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,  
    point.x,
    point.y,
    AfxGetMainWnd());
```  
  
 Agora você tem um servidor OLE minimamente habilitado para ativação de in-loco funcional. Mas ainda há muitos recursos disponíveis no MFC/OLE 2 que não estavam disponíveis no MFC/OLE1. Consulte o exemplo HIERSVR para obter mais ideias sobre os recursos que talvez você queira implementar. Alguns dos recursos que implementa HIERSVR estão listados abaixo:  
  
-   Aplicar zoom para true comportamento objetiva em relação ao contêiner.  
  
-   Arrastar / soltar e um formato personalizado de área de transferência.  
  
-   Rolar a janela de contêiner, como a seleção é alterada.  
  
 O exemplo de HIERSVR MFC 3.0 também usa um design ligeiramente diferente para os itens do servidor. Isso ajuda a conservar a memória e torna os links mais flexível. Com a versão 2.0 do HIERSVR cada nó na árvore de *é um* `COleServerItem`. `COleServerItem`executa um pouco mais sobrecarga do que é estritamente necessária para cada um de nós, mas um `COleServerItem` é necessária para cada link ativo. Mas a maior parte do tempo, há muito poucos links ativos a qualquer momento. Para tornar isso o mais eficiente, HIERSVR nesta versão do MFC separa o nó a partir de `COleServerItem`. Ele tem dois CServerNode um e um **CServerItem** classe. O **CServerItem** (derivado de `COleServerItem`) é criado somente quando necessário. Quando o contêiner (ou contêineres) parar de usar esse link específico para esse nó em particular, o objeto de CServerItem associado a CServerNode será excluído. Esse design é mais flexível e mais eficientes. Sua flexibilidade vem em ao lidar com vários links de seleção. Nenhuma dessas duas versões do HIERSVR suporte para seleção múltipla, mas seria muito mais fácil para adicionar (e para dar suporte a links para essas seleções) com a versão 3.0 do MFC de HIERSVR, desde que o `COleServerItem` é separada dos dados nativos.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

