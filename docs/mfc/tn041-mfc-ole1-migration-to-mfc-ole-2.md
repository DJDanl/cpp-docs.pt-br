---
title: 'TN041: MFC-OLE1 migração para MFC-OLE 2'
ms.date: 10/18/2018
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
ms.openlocfilehash: 7d0381983481278b1410ae0ff11463519d4cbb34
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743146"
---
# <a name="tn041-mfcole1-migration-to-mfcole-2"></a>TN041: migração de MFC/OLE1 para MFC/OLE 2

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

## <a name="general-issues-relating-to-migration"></a>Problemas gerais relacionados à migração

Uma das metas de design para as classes OLE 2 no MFC 2,5 (e superior) foi manter grande parte da mesma arquitetura implementada no MFC 2,0 para o suporte a OLE 1,0. Como resultado, muitas das mesmas classes OLE no MFC 2,0 ainda existem nesta versão do MFC ( `COleDocument` ,, `COleServerDoc` `COleClientItem` , `COleServerItem` ). Além disso, muitas das APIs nessas classes são exatamente as mesmas. No entanto, o OLE 2 é drasticamente diferente do OLE 1,0 para que você possa esperar que alguns dos detalhes tenham mudado. Se você estiver familiarizado com o suporte a OLE1 do MFC 2.0, você sentirá em casa com o suporte 2,0 do MFC.

Se você estiver adotando um aplicativo MFC/OLE1 existente e adicionando a funcionalidade OLE 2 a ele, leia esta observação primeiro. Esta observação aborda alguns problemas gerais que você pode encontrar ao portar sua funcionalidade de OLE1 para o MFC/OLE 2 e, em seguida, discute os problemas descobertos ao portar dois aplicativos incluídos no MFC 2,0: os exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md).

## <a name="mfc-documentview-architecture-is-important"></a>A arquitetura de exibição/documento do MFC é importante

Se seu aplicativo não usa a arquitetura de documento/exibição do MFC e você deseja adicionar suporte a OLE 2 ao seu aplicativo, agora é o momento de mover para o documento/exibição. Muitos dos benefícios das classes OLE 2 do MFC só são percebidos quando seu aplicativo está usando a arquitetura interna e os componentes do MFC.

É possível implementar um servidor ou contêiner sem usar a arquitetura do MFC, mas não é recomendado.

## <a name="use-mfc-implementation-instead-of-your-own"></a>Use a implementação do MFC em vez de sua própria

Classes de "implementação gravada" do MFC, como `CToolBar` , `CStatusBar` e `CScrollView` têm código de caso especial interno para suporte a OLE 2. Portanto, se você puder usar essas classes em seu aplicativo, você se beneficiará do esforço para torná-las com reconhecimento de OLE. Mais uma vez, é possível "distribuir suas aulas" aqui para essas finalidades, mas não é recomendável. Se você precisar implementar uma funcionalidade semelhante, o código-fonte do MFC é uma excelente referência para lidar com alguns dos pontos mais precisos do OLE (especialmente quando se trata de ativação in-loco).

## <a name="examine-the-mfc-sample-code"></a>Examinar o código de exemplo do MFC

Há vários exemplos de MFC que incluem a funcionalidade OLE. Cada um desses aplicativos implementa o OLE de um ângulo diferente:

- [HIERSVR](../overview/visual-cpp-samples.md) Significava principalmente para uso como um aplicativo de servidor. Ele foi incluído no MFC 2,0 como um aplicativo MFC/OLE1 e foi portado para MFC/OLE 2 e, em seguida, foi estendido, de forma que ele implementa muitos recursos OLE disponíveis no OLE 2.

- [OCLIENT](../overview/visual-cpp-samples.md) Esse é um aplicativo de contêiner autônomo, destinado a demonstrar muitos dos recursos OLE de um ponto de vista do contêiner. Ele também foi portado do MFC 2,0 e, em seguida, estendido para dar suporte a muitos dos recursos OLE mais avançados, como formatos de área de transferência personalizados e links para itens inseridos.

- [DRAWCLI](../overview/visual-cpp-samples.md) Esse aplicativo implementa o suporte a contêineres OLE como o OCLIENT, exceto pelo fato de que ele faz parte da estrutura de um programa de desenho orientado a objeto existente. Ele mostra como você pode implementar o suporte a contêiner OLE e integrá-lo a seu aplicativo existente.

- [SUPERPAD](../overview/visual-cpp-samples.md) Esse aplicativo, bem como um aplicativo bem independente, também é um servidor OLE. O suporte do servidor que ele implementa é muito bem. De interesse particular é como ele usa os serviços de área de transferência OLE para copiar dados para a área de transferência, mas usa a funcionalidade interna do controle "Edit" do Windows para implementar a funcionalidade de colar da área de transferência. Isso mostra uma combinação interessante do uso tradicional da API do Windows, bem como a integração com as novas APIs OLE.

Para obter mais informações sobre os aplicativos de exemplo, consulte a "ajuda de exemplo do MFC".

## <a name="case-study-oclient-from-mfc-20"></a>Estudo de caso: OCLIENT da MFC 2,0

Conforme discutido acima, o [OCLIENT](../overview/visual-cpp-samples.md) foi incluído no MFC 2,0 e implementou o OLE com MFC/OLE1. As etapas pelas quais esse aplicativo foi inicialmente convertido para usar as classes MFC/OLE 2 são descritas abaixo. Vários recursos foram adicionados após a conclusão da porta inicial para ilustrar melhor as classes MFC/OLE. Esses recursos não serão abordados aqui; consulte o próprio exemplo para obter mais informações sobre esses recursos avançados.

> [!NOTE]
> Os erros do compilador e o processo passo a passo foram criados com Visual C++ 2,0. As mensagens de erro e locais específicos podem ter mudado com Visual C++ 4,0, mas as informações conceituais permanecem válidas.

### <a name="getting-it-up-and-running"></a>Colocá-lo em funcionamento

A abordagem utilizada para portar o exemplo de OCLIENT para MFC/OLE é começar compilando-o e corrigindo os erros de compilador óbvios que resultarão. Se você pegar o exemplo de OCLIENT do MFC 2,0 e compilá-lo nessa versão do MFC, descobrirá que não há muitos erros a serem resolvidos. Os erros na ordem em que eles ocorreram estão descritos abaixo.

### <a name="compile-and-fix-errors"></a>Compilar e corrigir erros

```Output
\oclient\mainview.cpp(104) : error C2660: 'Draw' : function does not take 4 parameters
```

A primeira preocupação com o erro `COleClientItem::Draw` . No MFC/OLE1, foram necessárias mais parâmetros do que a versão do MFC/OLE. Os parâmetros extras geralmente não são necessários e geralmente são nulos (como neste exemplo). Essa versão do MFC pode determinar automaticamente os valores para o lpWBounds quando o CDC que está sendo desenhado for um DC de metarquivo. Além disso, o parâmetro pFormatDC não é mais necessário, já que a estrutura criará um do "atributo DC" do pDC passado. Portanto, para corrigir esse problema, basta remover os dois parâmetros nulos adicionais para a chamada de desenho.

```Output
\oclient\mainview.cpp(273) : error C2065: 'OLE_MAXNAMESIZE' : undeclared identifier
\oclient\mainview.cpp(273) : error C2057: expected constant expression
\oclient\mainview.cpp(280) : error C2664: 'CreateLinkFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '
\oclient\mainview.cpp(286) : error C2664: 'CreateFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '
\oclient\mainview.cpp(288) : error C2664: 'CreateStaticFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '
```

Os erros acima resultam do fato de que todas as `COleClientItem::CreateXXXX` funções no MFC/OLE1 exigiram que um nome exclusivo seja passado para representar o item. Esse era um requisito da API OLE subjacente. Isso não é necessário no MFC/OLE 2, já que o OLE 2 não usa o DDE como o mecanismo de comunicação subjacente (o nome foi usado em conversas DDE). Para corrigir esse problema, você pode remover a `CreateNewName` função, bem como todas as referências a ela. É fácil descobrir o que cada função MFC/OLE está esperando nesta versão simplesmente colocando o cursor na chamada e pressionando F1.

Outra área que é significativamente diferente é a manipulação de área de transferência OLE 2. Com o OLE1, você usou as APIs da área de transferência do Windows para interagir com a área de transferência. Com o OLE 2, isso é feito com um mecanismo diferente. As APIs MFC/OLE1 assumiram que a área de transferência estava aberta antes de copiar um `COleClientItem` objeto para a área de transferência. Isso não é mais necessário e fará com que todas as operações da área de transferência MFC/OLE falhem. Ao editar o código para remover dependências no `CreateNewName` , você também deve remover o código que abre e fecha a área de transferência do Windows.

```Output
\oclient\mainview.cpp(332) : error C2065: 'AfxOleInsertDialog' : undeclared identifier
\oclient\mainview.cpp(332) : error C2064: term does not evaluate to a function
\oclient\mainview.cpp(344) : error C2057: expected constant expression
\oclient\mainview.cpp(347) : error C2039: 'CreateNewObject' : is not a member of 'CRectItem'
```

Esses erros resultam do `CMainView::OnInsertObject` manipulador. Manipular o comando "Inserir novo objeto" é outra área na qual as coisas mudaram um pouco. Nesse caso, é mais fácil simplesmente mesclar a implementação original com aquela fornecida pelo AppWizard para um novo aplicativo de contêiner OLE. Na verdade, essa é uma técnica que você pode aplicar para portar outros aplicativos. No MFC/OLE1, você exibiu a caixa de diálogo "Inserir objeto" chamando `AfxOleInsertDialog` Function. Nesta versão, você constrói um `COleInsertObject` objeto de caixa de diálogo e chama `DoModal` . Além disso, novos itens OLE são criados com um **CLSID** em vez de uma cadeia de caracteres ClassName. O resultado final deve ser semelhante a este

```cpp
COleInsertDialog dlg;
if (dlg.DoModal() != IDOK)
    return;

BeginWaitCursor();

CRectItem* pItem = NULL;
TRY
{
    // First create the C++ object
    pItem = GetDocument()->CreateItem();
    ASSERT_VALID(pItem);

    // Initialize the item from the dialog data.
    if (!dlg.CreateItem(pItem))
        AfxThrowMemoryException();
            // any exception will do
    ASSERT_VALID(pItem);

    // run the object if appropriate
    if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
        pItem->DoVerb(OLEIVERB_SHOW, this);

    // update right away
    pItem->UpdateLink();
    pItem->UpdateItemRectFromServer();

    // set selection to newly inserted item
    SetSelection(pItem);
    pItem->Invalidate();
}
CATCH (CException, e)
{
    // clean up item
    if (pItem != NULL)
        GetDocument()->DeleteItem(pItem);

    AfxMessageBox(IDP_FAILED_TO_CREATE);
}
END_CATCH

EndWaitCursor();
```

> [!NOTE]
> Inserir novo objeto pode ser diferente para seu aplicativo):

Também é necessário incluir \<afxodlgs.h> , que contém a declaração da `COleInsertObject` classe Dialog, bem como as outras caixas de diálogo padrão fornecidas pelo MFC.

```Output
\oclient\mainview.cpp(367) : error C2065: 'OLEVERB_PRIMARY' : undeclared identifier
\oclient\mainview.cpp(367) : error C2660: 'DoVerb' : function does not take 1 parameters
```

Esses erros são causados pelo fato de que algumas constantes de OLE1 foram alteradas no OLE 2, embora em conceito sejam as mesmas. Nesse caso, `OLEVERB_PRIMARY` foi alterado para `OLEIVERB_PRIMARY` . Tanto em OLE1 quanto em OLE 2, o verbo primário é geralmente executado por um contêiner quando o usuário clica duas vezes em um item.

Além disso, `DoVerb` o agora usa um parâmetro extra, um ponteiro para uma exibição ( `CView` *). Esse parâmetro é usado apenas para implementar a "edição visual" (ou ativação in-loco). Por enquanto, você define esse parâmetro como NULL, porque você não está implementando esse recurso no momento.

Para garantir que a estrutura nunca tente fazer a ativação in-loco, você deve substituir da `COleClientItem::CanActivate` seguinte maneira:

```cpp
BOOL CRectItem::CanActivate()
{
    return FALSE;
}
```

```Output
\oclient\rectitem.cpp(53) : error C2065: 'GetBounds' : undeclared identifier
\oclient\rectitem.cpp(53) : error C2064: term does not evaluate to a function
\oclient\rectitem.cpp(84) : error C2065: 'SetBounds' : undeclared identifier
\oclient\rectitem.cpp(84) : error C2064: term does not evaluate to a function
```

No MFC/OLE1, `COleClientItem::GetBounds` e `SetBounds` foram usados para consultar e manipular a extensão de um item (o `left` e os `top` membros eram sempre zero). No MFC/OLE 2, isso é mais diretamente suportado pelo `COleClientItem::GetExtent` e `SetExtent` , que lidam com um **tamanho** ou `CSize` em vez disso.

O código para seu novo SetItemRectToServer e chamadas UpdateItemRectFromServer têm esta aparência:

```cpp
BOOL CRectItem::UpdateItemRectFromServer()
{
    ASSERT(m_bTrackServerSize);
    CSize size;
    if (!GetExtent(&size))
        return FALSE;    // blank

    // map from HIMETRIC to screen coordinates
    {
        CClientDC screenDC(NULL);
        screenDC.SetMapMode(MM_HIMETRIC);
        screenDC.LPtoDP(&size);
    }
    // just set the item size
    if (m_rect.Size() != size)
    {
        // invalidate the old size/position
        Invalidate();
        m_rect.right = m_rect.left + size.cx;
        m_rect.bottom = m_rect.top + size.cy;
        // as well as the new size/position
        Invalidate();
    }
    return TRUE;
}

BOOL CRectItem::SetItemRectToServer()
{
    // set the official bounds for the embedded item
    CSize size = m_rect.Size();
    {
        CClientDC screenDC(NULL);
        screenDC.SetMapMode(MM_HIMETRIC);
        screenDC.DPtoLP(&size);
    }
    TRY
    {
        SetExtent(size);    // may do a wait
    }
    CATCH(CException, e)
    {
        return FALSE;  // links will not allow SetBounds
    }
    END_CATCH
    return TRUE;
}
```

```Output
\oclient\frame.cpp(50) : error C2039: 'InWaitForRelease' : is not a member of 'COleClientItem'
\oclient\frame.cpp(50) : error C2065: 'InWaitForRelease' : undeclared identifier
\oclient\frame.cpp(50) : error C2064: term does not evaluate to a function
```

Em chamadas de API síncronas do MFC/OLE1 de um contêiner para um servidor foram *simuladas*, porque o OLE1 era inerentemente assíncrona em muitos casos. Era necessário verificar se há uma chamada assíncrona pendente em andamento antes de processar comandos do usuário. O MFC/OLE1 fornecia a `COleClientItem::InWaitForRelease` função para fazer isso. No MFC/OLE 2, isso não é necessário, portanto, você pode remover a substituição de OnCommand em CMainFrame todos juntos.

Neste ponto, o OCLIENT será compilado e vinculado.

### <a name="other-necessary-changes"></a>Outras alterações necessárias

No entanto, há algumas coisas que não são feitas que impedirão a execução do OCLIENT. É melhor corrigir esses problemas agora, em vez de mais tarde.

Primeiro, é necessário inicializar as bibliotecas OLE. Isso é feito chamando `AfxOleInit` de `InitInstance` :

```cpp
if (!AfxOleInit())
{
    AfxMessageBox("Failed to initialize OLE libraries");
    return FALSE;
}
```

Também é uma boa ideia verificar se há funções virtuais para alterações na lista de parâmetros. Uma dessas funções é `COleClientItem::OnChange` , substituída em cada aplicativo de contêiner MFC/OLE. Ao examinar a ajuda online, você verá que um ' DWORD dwParam ' extra foi adicionado. O novo CRectItem:: OnChange tem a seguinte aparência:

```cpp
void
CRectItem::OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam)
{
    if (m_bTrackServerSize && !UpdateItemRectFromServer())
    {
        // Blank object
        if (wNotification == OLE_CLOSED)
        {
            // no data received for the object - destroy it
            ASSERT(!IsVisible());
            GetDocument()->DeleteItem(this);
            return; // no update (item is gone now)
        }
    }
    if (wNotification != OLE_CLOSED)
        Dirty();
    Invalidate();
    // any change will cause a redraw
}
```

No MFC/OLE1, os aplicativos de contêiner derivados da classe de documento de `COleClientDoc` . No MFC/OLE 2, essa classe foi removida e substituída pelo `COleDocument` (essa nova organização torna mais fácil criar aplicativos de contêiner/servidor). Há um **#define** que mapeia `COleClientDoc` para o `COleDocument` para simplificar a portabilidade de aplicativos MFC/OLE1 para MFC/OLE 2, como OCLIENT. Um dos recursos não fornecidos pelo `COleDocument` foi fornecido pelo `COleClientDoc` são as entradas de mapa de mensagem de comando padrão. Isso é feito para que os aplicativos de servidor, que também usam `COleDocument` (indiretamente), não transportam a sobrecarga desses manipuladores de comando, a menos que sejam um aplicativo de contêiner/servidor. Você precisa adicionar as seguintes entradas ao mapa de mensagens CMainDoc:

```cpp
ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdatePasteMenu)
ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, OnUpdatePasteLinkMenu)
ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, OnUpdateEditLinksMenu)
ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, OnUpdateObjectVerbMenu)
ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, OnUpdateObjectVerbMenu)
ON_COMMAND(ID_OLE_EDIT_CONVERT, OnEditConvert)
```

A implementação de todos esses comandos está em `COleDocument` , que é a classe base do seu documento.

Neste ponto, o OCLIENT é um aplicativo de contêiner OLE funcional. É possível inserir itens de qualquer tipo (OLE1 ou OLE 2). Como o código necessário para habilitar a ativação in-loco não está implementado, os itens são editados em uma janela separada de forma semelhante ao OLE1. A próxima seção aborda as alterações necessárias para habilitar a edição in-loco (às vezes chamada de "edição visual").

### <a name="adding-visual-editing"></a>Adicionando "edição visual"

Um dos recursos mais interessantes do OLE é a ativação in-loco (ou "edição visual"). Esse recurso permite que o aplicativo de servidor assuma sobre partes da interface do usuário do contêiner para fornecer uma interface de edição mais direta para o usuário. Para implementar a ativação in-loco no OCLIENT, alguns recursos especiais precisam ser adicionados, bem como alguns códigos adicionais. Esses recursos e o código normalmente são fornecidos pelo AppWizard — na verdade, grande parte do código foi emprestado diretamente de um aplicativo AppWizard novo com suporte a "contêiner".

Em primeiro lugar, é necessário adicionar um recurso de menu a ser usado quando houver um item ativo no local. Você pode criar esse recurso de menu extra no Visual C++ copiando o recurso de IDR_OCLITYPE e removendo todos, exceto os pop-ups de arquivo e janela. Duas barras separadoras são inseridas entre os pop-ups de arquivo e de janela para indicar a separação de grupos (deve ser semelhante a: arquivo &#124;&#124; janela). Para obter mais informações sobre o que esses separadores significam e como os menus de servidor e contêiner são mesclados, consulte [menus e recursos: mesclagem de menu](../mfc/menus-and-resources-menu-merging.md).

Depois que esses menus forem criados, você precisará permitir que a estrutura saiba sobre eles. Isso é feito chamando `CDocTemplate::SetContainerInfo` o modelo de documento antes de adicioná-lo à lista de modelos de documento em seu InitInstance. O novo código para registrar o modelo de documento tem esta aparência:

```cpp
CDocTemplate* pTemplate = new CMultiDocTemplate(
    IDR_OLECLITYPE,
    RUNTIME_CLASS(CMainDoc),
    RUNTIME_CLASS(CMDIChildWnd), // standard MDI child frame
    RUNTIME_CLASS(CMainView));

pTemplate->SetContainerInfo(IDR_OLECLITYPE_INPLACE);

AddDocTemplate(pTemplate);
```

O recurso de IDR_OLECLITYPE_INPLACE é o recurso in-loco especial criado em Visual C++.

Para habilitar a ativação in-loco, há algumas coisas que precisam ser alteradas na `CView` classe derivada (CMainView), bem como na `COleClientItem` classe derivada (CRectItem). Todas essas substituições são fornecidas por AppWizard e a maior parte da implementação virá diretamente de um aplicativo AppWizard padrão.

Na primeira etapa desta porta, a ativação in-loco foi desabilitada inteiramente pela substituição `COleClientItem::CanActivate` . Essa substituição deve ser removida para permitir a ativação in-loco. Além disso, NULL foi passado para todas as chamadas para `DoVerb` (há duas delas) porque fornecer a exibição só era necessária para ativação in-loco. Para implementar totalmente a ativação in-loco, é necessário passar a exibição correta na `DoVerb` chamada. Uma dessas chamadas está em `CMainView::OnInsertObject` :

```cpp
pItem->DoVerb(OLEIVERB_SHOW, this);
```

Outro está em `CMainView::OnLButtonDblClk` :

```cpp
m_pSelection->DoVerb(OLEIVERB_PRIMARY, this);
```

É necessário substituir `COleClientItem::OnGetItemPosition` . Isso informa ao servidor onde colocar sua janela em relação à janela do contêiner quando o item está ativado no local. Para OCLIENT, a implementação é trivial:

```cpp
void CRectItem::OnGetItemPosition(CRect& rPosition)
{
    rPosition = m_rect;
}
```

A maioria dos servidores também implementa o que é chamado de "redimensionamento in-loco". Isso permite que a janela do servidor seja dimensionada e movida enquanto o usuário estiver editando o item. O contêiner deve participar desta ação, uma vez que mover ou redimensionar a janela geralmente afeta a posição e o tamanho no próprio documento do contêiner. A implementação para OCLIENT sincroniza o retângulo interno mantido por m_rect com a nova posição e o mesmo tamanho.

```cpp
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

Neste ponto, há código suficiente para permitir que um item seja ativado no local e para lidar com o dimensionamento e a movimentação do item quando ele estiver ativo, mas nenhum código permitirá que o usuário saia da sessão de edição. Embora alguns servidores forneçam essa funcionalidade manipulando a tecla escape, é recomendável que os contêineres forneçam duas maneiras de desativar um item: (1) clicando fora do item e (2) pressionando a tecla ESCAPE.

Para a tecla ESCAPE, adicione um acelerador com Visual C++ que mapeie a chave de VK_ESCAPE para um comando, ID_CANCEL_EDIT será adicionado aos recursos. O manipulador para este comando segue:

```cpp
// The following command handler provides the standard
// keyboard user interface to cancel an in-place
// editing session.void CMainView::OnCancelEdit()
{
    // Close any in-place active item on this view.
    COleClientItem* pActiveItem =
        GetDocument()->GetInPlaceActiveItem(this);
    if (pActiveItem != NULL)
        pActiveItem->Close();
    ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}
```

Para lidar com o caso em que o usuário clica fora do item, você adiciona o seguinte código ao início de `CMainView::SetSelection` :

```cpp
if (pNewSel != m_pSelection || pNewSel == NULL)
{
    COleClientItem* pActiveItem =
        GetDocument()->GetInPlaceActiveItem(this);
    if (pActiveItem != NULL&& pActiveItem != pNewSel)
        pActiveItem->Close();
}
```

Quando um item está ativo no local, ele deve ter o foco. Para certificar-se de que esse é o caso, você lida com OnSetFocus para que o foco sempre seja transferido para o item ativo quando a exibição receber o foco:

```cpp
// Special handling of OnSetFocus and OnSize are required
// when an object is being edited in-place.
void CMainView::OnSetFocus(CWnd* pOldWnd)
{
    COleClientItem* pActiveItem =
        GetDocument()->GetInPlaceActiveItem(this);

    if (pActiveItem != NULL &&
        pActiveItem->GetItemState() == COleClientItem::activeUIState)
    {
        // need to set focus to this item if it is same view
        CWnd* pWnd = pActiveItem->GetInPlaceWindow();
        if (pWnd != NULL)
        {
            pWnd->SetFocus();   // don't call the base class
            return;
        }
    }

    CView::OnSetFocus(pOldWnd);
}
```

Quando a exibição for redimensionada, você precisará notificar o item ativo de que o retângulo de recorte foi alterado. Para fazer isso, você fornece um manipulador para `OnSize` :

```cpp
void CMainView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);
    COleClientItem* pActiveItem =
        GetDocument()->GetInPlaceActiveItem(this);
    if (pActiveItem != NULL)
        pActiveItem->SetItemRects();
}
```

## <a name="case-study-hiersvr-from-mfc-20"></a>Estudo de caso: HIERSVR da MFC 2,0

O [HIERSVR](../overview/visual-cpp-samples.md) também foi incluído no MFC 2,0 e implementou o OLE com MFC/OLE1. Esta observação descreve brevemente as etapas pelas quais esse aplicativo foi inicialmente convertido para usar as classes MFC/OLE 2. Vários recursos foram adicionados após a conclusão da porta inicial para ilustrar melhor as classes MFC/OLE 2. Esses recursos não serão abordados aqui; consulte o próprio exemplo para obter mais informações sobre esses recursos avançados.

> [!NOTE]
> Os erros do compilador e o processo passo a passo foram criados com Visual C++ 2,0. As mensagens de erro e locais específicos podem ter mudado com Visual C++ 4,0, mas as informações conceituais permanecem válidas.

### <a name="getting-it-up-and-running"></a>Colocá-lo em funcionamento

A abordagem utilizada para portar o exemplo de HIERSVR para MFC/OLE é começar compilando-o e corrigindo os erros de compilador óbvios que resultarão. Se você pegar o exemplo de HIERSVR do MFC 2,0 e compilá-lo nesta versão do MFC, descobrirá que não há muitos erros a serem resolvidos (embora haja mais do que com o exemplo OCLIENT). Os erros na ordem em que normalmente ocorrem são descritos abaixo.

### <a name="compile-and-fix-errors"></a>Compilar e corrigir erros

```Output
\hiersvr\hiersvr.cpp(83) : error C2039: 'RunEmbedded' : is not a member of 'COleTemplateServer'
```

Esse primeiro erro indica um problema muito maior com a `InitInstance` função para servidores. A inicialização necessária para um servidor OLE é provavelmente uma das maiores alterações que você precisará fazer em seu aplicativo MFC/OLE1 para que ele seja executado. A melhor coisa a fazer é ver o que o AppWizard cria para um servidor OLE e modificar seu código conforme apropriado. Aqui estão alguns pontos para ter em mente:

É necessário inicializar as bibliotecas OLE chamando `AfxOleInit`

Chame SetServerInfo no objeto de modelo de documento para definir identificadores de recurso de servidor e informações de classe de tempo de execução que você não pode definir com o `CDocTemplate` Construtor.

Não mostre a janela principal do seu aplicativo se/Embedding estiver presente na linha de comando.

Você precisará de um **GUID** para seu documento. Este é um identificador exclusivo para o tipo do documento (128 bits). O AppWizard criará um para você – portanto, se você usar a técnica descrita aqui para copiar o novo código de um novo aplicativo de servidor AppWizard gerado, você pode simplesmente "roubar" o GUID desse aplicativo. Caso contrário, você pode usar o utilitário GUIDGEN.EXE no diretório BIN.

É necessário "conectar" o `COleTemplateServer` objeto ao modelo de documento chamando `COleTemplateServer::ConnectTemplate` .

Atualize o registro do sistema quando seu aplicativo for executado de forma autônoma. Dessa forma, se o usuário mover o. EXE para seu aplicativo, executando-o de seu novo local atualizará o banco de dados de registro do sistema do Windows para apontar para o novo local.

Depois de aplicar todas essas alterações com base no que o AppWizard cria para `InitInstance` , o `InitInstance` (e o GUID relacionado) para HIERSVR devem ser lidos da seguinte maneira:

```cpp
// this is the GUID for HIERSVR documents
static const GUID BASED_CODE clsid =
{ 0xA0A16360L, 0xC19B, 0x101A, { 0x8C, 0xE5, 0x00, 0xDD, 0x01, 0x11, 0x3F, 0x12 } };

/////////////////////////////////////////////////////////////////////////////
// COLEServerApp initialization

BOOL COLEServerApp::InitInstance()
{
    // OLE 2 initialization
    if (!AfxOleInit())
    {
        AfxMessageBox("Initialization of the OLE failed!");
        return FALSE;
    }

    // Standard initialization
    LoadStdProfileSettings();   // Load standard INI file options

    // Register document templates
    CDocTemplate* pDocTemplate;
    pDocTemplate = new CMultiDocTemplate(IDR_HIERSVRTYPE,
        RUNTIME_CLASS(CServerDoc),
        RUNTIME_CLASS(CMDIChildWnd),
        RUNTIME_CLASS(CServerView));
    pDocTemplate->SetServerInfo(IDR_HIERSVRTYPE_SRVR_EMB);
    AddDocTemplate(pDocTemplate);

    // create main MDI Frame window
    CMainFrame* pMainFrame = new CMainFrame;
    if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
        return FALSE;
    m_pMainWnd = pMainFrame;

    SetDialogBkColor(); // gray look

    // enable file manager drag/drop and DDE Execute open
    m_pMainWnd->DragAcceptFiles();
    EnableShellOpen();

    m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
    COleTemplateServer::RegisterAll();

    // try to launch as an OLE server
    if (RunEmbedded())
    {
        // "short-circuit" initialization -- run as server!
        return TRUE;
    }
    m_server.UpdateRegistry();
    RegisterShellFileTypes();

    // not run as OLE server, so show the main window
    if (m_lpCmdLine[0] == '\0')
    {
        // create a new (empty) document
        OnFileNew();
    }
    else
    {
        // open an existing document
        OpenDocumentFile(m_lpCmdLine);
    }

    pMainFrame->ShowWindow(m_nCmdShow);
    pMainFrame->UpdateWindow();

    return TRUE;
}
```

Você observará que o código acima se refere a uma nova ID de recurso, IDR_HIERSVRTYPE_SRVR_EMB. Esse é o recurso de menu a ser usado quando um documento inserido em outro contêiner é editado. Em MFC/OLE1, os itens de menu específicos à edição de um item inserido foram modificados de forma dinâmica. Usar uma estrutura de menu totalmente diferente ao editar um item incorporado em vez de editar um documento baseado em arquivo torna muito mais fácil fornecer diferentes interfaces de usuário para esses dois modos separados. Como você verá posteriormente, um recurso de menu totalmente separado é usado ao editar um objeto inserido in-loco.

Para criar esse recurso, carregue o script de recurso em Visual C++ e copie o recurso de menu IDR_HIERSVRTYPE existente. Renomeie o novo recurso como IDR_HIERSVRTYPE_SRVR_EMB (essa é a mesma convenção de nomenclatura que o AppWizard usa). Em seguida, altere "File Save" para "File Update"; forneça a ID de comando ID_FILE_UPDATE. Também altere "arquivo salvar como" para "salvar arquivo copiar como"; forneça a ID de comando ID_FILE_SAVE_COPY_AS. A estrutura fornece a implementação de ambos os comandos.

```Output
\hiersvr\svritem.h(60) : error C2433: 'OLESTATUS' : 'virtual' not permitted on data declarations
\hiersvr\svritem.h(60) : error C2501: 'OLESTATUS' : missing decl-specifiers
\hiersvr\svritem.h(60) : error C2146: syntax error : missing ';' before identifier 'OnSetData'
\hiersvr\svritem.h(60) : error C2061: syntax error : identifier 'OLECLIPFORMAT'
\hiersvr\svritem.h(60) : error C2501: 'OnSetData' : missing decl-specifiers
```

Há vários erros resultantes da substituição de `OnSetData` , pois ele está se referindo ao tipo **OleStatus** . **OleStatus** foi a maneira como o OLE1 retornou erros. Isso mudou para **HRESULT** no OLE 2, embora o MFC geralmente Converta um **HRESULT** em um `COleException` que contenha o erro. Nesse caso em particular, a substituição de `OnSetData` não é mais necessária, portanto, a coisa mais fácil é removê-lo.

```Output
\hiersvr\svritem.cpp(30) : error C2660: 'COleServerItem::COleServerItem' : function does not take 1 parameters
```

O `COleServerItem` construtor usa um parâmetro ' bool ' extra. Esse sinalizador determina como o gerenciamento de memória é feito nos `COleServerItem` objetos. Ao defini-lo como TRUE, a estrutura lida com o gerenciamento de memória desses objetos, excluindo-os quando não forem mais necessários. O HIERSVR usa `CServerItem` objetos (derivados de `COleServerItem` ) como parte de seus dados nativos, portanto, você definirá esse sinalizador como false. Isso permite que o HIERSVR determine quando cada item do servidor é excluído.

```Output
\hiersvr\svritem.cpp(44) : error C2259: 'CServerItem' : illegal attempt to instantiate abstract class
\hiersvr\svritem.cpp(44) : error C2259: 'CServerItem' : illegal attempt to instantiate abstract class
```

Como esses erros sugerem, há algumas funções "puramente virtual" que não foram substituídas em CServerItem. É muito provável que isso seja causado pelo fato de que a lista de parâmetros de OnDraw foi alterada. Para corrigir esse erro, altere da `CServerItem::OnDraw` seguinte maneira (bem como a declaração em svritem. h):

```cpp
BOOL CServerItem::OnDraw(CDC* pDC, CSize& rSize)
{
    // request from OLE to draw node
    pDC->SetMapMode(MM_TEXT); // always in pixels
    return DoDraw(pDC, CPoint(0, 0), FALSE);
}
```

O novo parâmetro é ' rSize '. Isso permite que você preencha o tamanho do desenho, se conveniente. Esse tamanho deve estar em **HIMETRIC**. Nesse caso, não é conveniente preencher esse valor em, portanto, a estrutura chama `OnGetExtent` para recuperar a extensão. Para que isso funcione, você precisará implementar `OnGetExtent` :

```cpp
BOOL CServerItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
    if (dwDrawAspect != DVASPECT_CONTENT)
        return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

    rSize = CalcNodeSize();
    return TRUE;
}
```

```Output
\hiersvr\svritem.cpp(104) : error C2065: 'm_rectBounds' : undeclared identifier
\hiersvr\svritem.cpp(104) : error C2228: left of '.SetRect' must have class/struct/union type
\hiersvr\svritem.cpp(106) : error C2664: 'void __pascal __far DPtoLP(struct ::tagPOINT __far *,
    int)__far const ' : cannot convert parameter 1 from 'int __far *' to 'struct ::tagPOINT __far *'
```

Na função CServerItem:: CalcNodeSize, o tamanho do item é convertido em **HIMETRIC** e armazenado em *m_rectBounds*. O membro '*m_rectBounds*' não documentado não `COleServerItem` existe (ele foi parcialmente substituído por *m_sizeExtent*, mas, em OLE 2, esse membro tem um uso ligeiramente diferente do que *m_rectBounds* fez em OLE1). Em vez de definir o tamanho de **HIMETRIC** nessa variável de membro, você a retornará. Esse valor de retorno é usado no `OnGetExtent` , implementado anteriormente.

```cpp
CSize CServerItem::CalcNodeSize()
{
    CClientDC dcScreen(NULL);

    m_sizeNode = dcScreen.GetTextExtent(m_strDescription,
        m_strDescription.GetLength());
    m_sizeNode += CSize(CX_INSET * 2, CY_INSET * 2);

    // set suggested HIMETRIC size
    CSize size(m_sizeNode.cx, m_sizeNode.cy);
    dcScreen.SetMapMode(MM_HIMETRIC);
    dcScreen.DPtoLP(&size);
    return size;
}
```

CServerItem também substitui `COleServerItem::OnGetTextData` . Essa função é obsoleta no MFC/OLE e é substituída por um mecanismo diferente. A versão do MFC 3,0 do exemplo OLE MFC [HIERSVR](../overview/visual-cpp-samples.md) implementa essa funcionalidade substituindo `COleServerItem::OnRenderFileData` . Essa funcionalidade não é importante para essa porta básica, portanto, você pode remover a substituição OnGetTextData.

Há muitos outros erros em svritem. cpp que não foram resolvidos. Eles não são erros "reais" — apenas erros causados por erros anteriores.

```Output
\hiersvr\svrview.cpp(325) : error C2660: 'CopyToClipboard' : function does not take 2 parameters
```

`COleServerItem::CopyToClipboard` Não dá mais suporte ao `bIncludeNative` sinalizador. Os dados nativos (os dados gravados pela função Serialize do item do servidor) são sempre copiados, portanto, você remove o primeiro parâmetro. Além disso, `CopyToClipboard` o gerará uma exceção quando ocorrer um erro em vez de retornar false. Altere o código para CServerView:: OnEditCopy da seguinte maneira:

```cpp
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

Embora haja mais erros resultantes da compilação da versão do MFC 2,0 do HIERSVR do que havia para a mesma versão do OCLIENT, havia, na verdade, menos alterações.

Neste ponto, o HIERSVR será compilado e vinculado e funcionará como um servidor OLE, mas sem o recurso de edição in-loco, que será implementado em seguida.

### <a name="adding-visual-editing"></a>Adicionando "edição visual"

Para adicionar "edição visual" (ou ativação in-loco) a este aplicativo de servidor, há apenas algumas coisas que você deve cuidar:

- Você precisa de um recurso de menu especial para ser usado quando o item estiver ativo no local.

- Esse aplicativo tem uma barra de ferramentas, portanto, você precisará de uma barra de ferramentas com apenas um subconjunto da barra de ferramentas normal para corresponder aos comandos de menu disponíveis no servidor (corresponde ao recurso de menu mencionado acima).

- Você precisa de uma nova classe derivada de `COleIPFrameWnd` que fornece a interface do usuário in-loco (muito semelhante a CMainFrame, derivada de `CMDIFrameWnd` , fornece a interface do usuário do MDI).

- Você precisa informar à estrutura sobre esses recursos e classes especiais.

O recurso de menu é fácil de criar. Execute Visual C++, copie o IDR_HIERSVRTYPE de recursos de menu para um recurso de menu chamado IDR_HIERSVRTYPE_SRVR_IP. Modifique o menu para que apenas os pop-ups de menu Editar e ajuda sejam deixados. Adicione dois separadores ao menu entre os menus editar e ajuda (deve ser semelhante a: editar &#124;&#124; ajuda). Para obter mais informações sobre o que esses separadores significam e como os menus de servidor e contêiner são mesclados, consulte [menus e recursos: mesclagem de menu](../mfc/menus-and-resources-menu-merging.md).

O bitmap para a barra de ferramentas de subconjunto pode ser facilmente criado copiando-o de um aplicativo novo AppWizard gerado com uma opção de "servidor" marcada. Esse bitmap pode então ser importado para o Visual C++. Certifique-se de dar ao bitmap uma ID IDR_HIERSVRTYPE_SRVR_IP.

A classe derivada de `COleIPFrameWnd` pode ser copiada de um aplicativo AppWizard gerado com suporte a servidor também. Copie os dois arquivos, IPFRAME. CPP e IPFRAME. H e adicioná-las ao projeto. Certifique-se de que a `LoadBitmap` chamada se refere a IDR_HIERSVRTYPE_SRVR_IP, o bitmap criado na etapa anterior.

Agora que todos os novos recursos e classes são criados, adicione o código necessário para que a estrutura saiba sobre eles (e saiba que agora esse aplicativo dá suporte à edição in-loco). Isso é feito adicionando mais alguns parâmetros à `SetServerInfo` chamada na `InitInstance` função:

```cpp
pDocTemplate->SetServerInfo(IDR_HIERSVRTYPE_SRVR_EMB,
    IDR_HIERSVRTYPE_SRVR_IP,
    RUNTIME_CLASS(CInPlaceFrame));
```

Agora ele está pronto para ser executado no local em qualquer contêiner que também ofereça suporte à ativação in-loco. Mas, há um pequeno bug que ainda está escondida no código. O HIERSVR dá suporte a um menu de contexto, exibido quando o usuário pressiona o botão direito do mouse. Esse menu funciona quando o HIERSVR está totalmente aberto, mas não funciona ao editar uma incorporação in-loco. O motivo pode ser fixado nessa única linha de código em CServerView:: OnRButtonDown:

```cpp
pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,
    point.x,
    point.y,
    AfxGetApp()->m_pMainWnd);
```

Observe a referência para `AfxGetApp()->m_pMainWnd` . Quando o servidor é ativado no local, ele tem uma janela principal e m_pMainWnd é definido, mas normalmente é invisível. Além disso, essa janela refere-se à janela *principal* do aplicativo, a janela de quadro MDI que aparece quando o servidor está totalmente aberto ou executado de forma autônoma. Ele não se refere à janela do quadro ativo — que quando ativada in-loco é uma janela de quadro derivada de `COleIPFrameWnd` . Para obter a janela ativa correta mesmo quando a edição in-loco, essa versão do MFC adiciona uma nova função, `AfxGetMainWnd` . Em geral, você deve usar essa função em vez de `AfxGetApp()->m_pMainWnd` . Esse código precisa ser alterado da seguinte maneira:

```cpp
pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,
    point.x,
    point.y,
    AfxGetMainWnd());
```

Agora você tem um servidor OLE habilitado minimamente para ativação in-loco funcional. Mas ainda há muitos recursos disponíveis com MFC/OLE 2 que não estavam disponíveis no MFC/OLE1. Consulte o exemplo de HIERSVR para obter mais ideias sobre os recursos que você pode desejar implementar. Alguns dos recursos que o HIERSVR implementa estão listados abaixo:

- Aplicando zoom, para comportamento WYSIWYG verdadeiro em relação ao contêiner.

- Arraste/solte e um formato de área de transferência personalizado.

- Rolando a janela do contêiner à medida que a seleção é alterada.

O exemplo HIERSVR no MFC 3,0 também usa um design ligeiramente diferente para seus itens de servidor. Isso ajuda a conservar a memória e torna seus links mais flexíveis. Com a versão 2,0 do HIERSVR, cada nó na árvore *é-a* `COleServerItem` . `COleServerItem` tem um pouco mais de sobrecarga do que é estritamente necessário para cada um desses nós, mas um `COleServerItem` é necessário para cada link ativo. Mas, na maior parte, há poucos links ativos em um determinado momento. Para tornar isso mais eficiente, o HIERSVR nesta versão do MFC separa o nó do `COleServerItem` . Ele tem um CServerNode e uma `CServerItem` classe. O `CServerItem` (derivado de `COleServerItem` ) é criado somente conforme necessário. Depois que o contêiner (ou contêineres) parar de usar esse link específico para esse nó específico, o objeto CServerItem associado ao CServerNode será excluído. Esse design é mais eficiente e mais flexível. Sua flexibilidade chega ao lidar com vários links de seleção. Nenhuma dessas duas versões do HIERSVR dão suporte à seleção múltipla, mas seria muito mais fácil adicionar (e dar suporte a links para essas seleções) com a versão do MFC 3,0 do HIERSVR, pois o `COleServerItem` é separado dos dados nativos.

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
