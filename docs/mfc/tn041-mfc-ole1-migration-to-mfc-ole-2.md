---
title: 'TN041: Migração de MFC-OLE1 para MFC-OLE 2 | Microsoft Docs'
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.ole
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c2f93ffa79c5f737be032ae9edffa6c3e49c7055
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49809012"
---
# <a name="tn041-mfcole1-migration-to-mfcole-2"></a>TN041: migração de MFC/OLE1 para MFC/OLE 2

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

## <a name="general-issues-relating-to-migration"></a>Problemas gerais relacionados à migração

Uma das metas de design para as classes de 2 OLE no MFC 2.5 (e superiores) era manter grande parte da mesma arquitetura colocada em vigor no MFC 2.0 para o suporte ao OLE 1.0. Como resultado, muitas das mesmas classes OLE no MFC 2.0 ainda existem nesta versão do MFC (`COleDocument`, `COleServerDoc`, `COleClientItem`, `COleServerItem`). Além disso, muitas das APIs nessas classes são exatamente iguais. No entanto, o OLE 2 é drasticamente diferente do 1.0 OLE para que você pode esperar que alguns dos detalhes foram alterados. Se você estiver familiarizado com o suporte de OLE1 do MFC 2.0, você se sentirá em casa com suporte de 2.0 do MFC.

Se você estiver levando um aplicativo MFC/OLE1 existente e adicionar funcionalidade OLE 2 a ele, você deve primeiro ler esta nota. Esta Observação aborda alguns problemas gerais que você pode encontrar durante a portabilidade de sua funcionalidade OLE1 para MFC/OLE 2 e, em seguida, aborda os problemas revelados durante a migração do dois aplicativos incluídos no MFC 2.0: os exemplos de OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md).

## <a name="mfc-documentview-architecture-is-important"></a>Arquitetura de documento/exibição do MFC é importante

Se seu aplicativo não usa a arquitetura de documento/exibição do MFC e você deseja adicionar suporte ao OLE 2 ao seu aplicativo, agora é o momento para mover para o documento/exibição. Muitos dos benefícios das classes de 2 OLE do MFC só ocorre depois que seu aplicativo está usando a arquitetura interna e componentes do MFC.

A implementação de um servidor ou um contêiner sem usar a arquitetura do MFC é possível, mas não é recomendado.

## <a name="use-mfc-implementation-instead-of-your-own"></a>Usar a implementação MFC em vez de seu próprio

Classes MFC "implementação gravados", como `CToolBar`, `CStatusBar`, e `CScrollView` têm código interno de caso especial para o suporte do OLE 2. Portanto, se você pode usar essas classes em seu aplicativo você se beneficiará do esforço colocá-los para torná-los OLE ciente. Novamente, é possível "roll seu próprio" classes aqui para esses fins, mas não é sugerida. Se você precisar implementar uma funcionalidade semelhante, o código-fonte MFC é uma referência de excelente para lidar com alguns dos pontos mais refinados de OLE (especialmente quando se trata de ativação no local).

## <a name="examine-the-mfc-sample-code"></a>Examinar o código de exemplo do MFC

Há um número de amostras do MFC que incluem funcionalidade OLE. Cada um desses aplicativos implementa OLE de um ângulo diferente:

- [HIERSVR](../visual-cpp-samples.md) destinada principalmente para uso como um aplicativo de servidor. Ele foi incluído no MFC 2.0 como um aplicativo MFC/OLE1 e foi movido para o MFC/OLE 2 e, em seguida, estendido, de modo que ele implementa vários recursos OLE disponíveis no OLE 2.

- [OCLIENT](../visual-cpp-samples.md) este é um aplicativo de contêiner autônoma, destinado a demonstrar muitos dos recursos OLE de um ponto de vista do contêiner. Ele também foi transferido da MFC 2.0 e, em seguida, estendido para dar suporte a muitos dos recursos mais avançados do OLE, como formatos personalizados de área de transferência e links para itens inseridos.

- [DRAWCLI](../visual-cpp-samples.md) este aplicativo implementa suporte de contêiner OLE muito como OCLIENT faz, exceto que ele faz isso dentro da estrutura de um programa de desenho orientado a objeto existente. Ele mostra como você pode implementar o suporte de contêiner OLE e integrá-lo ao seu aplicativo existente.

- [SUPERPAD](../visual-cpp-samples.md) esse aplicativo, bem como sendo um bom aplicativo autônomo, também é um servidor OLE. O suporte de servidor implementa é bastante minimalista. De interesse particular é como ele usa os serviços de área de transferência OLE para copiar dados para a área de transferência, mas usa a funcionalidade incorporada no controle de edição"Windows" para implementar a funcionalidade de colar da área de transferência. Isso mostra uma mistura interessante de tradicional uso da API do Windows, bem como integração com as novas OLE APIs.

Para obter mais informações sobre os aplicativos de exemplo, consulte a "MFC exemplo ajuda".

## <a name="case-study-oclient-from-mfc-20"></a>Estudo de caso: OCLIENT do MFC 2.0

Como discutido acima, [OCLIENT](../visual-cpp-samples.md) foi incluído no 2.0 MFC e OLE com MFC/OLE1 de implementado. As etapas pelas quais este aplicativo foi inicialmente convertido para usar as classes MFC/OLE 2 são descritas abaixo. Uma série de recursos foram adicionada depois que a porta inicial foi concluída para melhor ilustrar as classes MFC/OLE. Esses recursos não serão abordados aqui; Consulte o exemplo para obter mais informações sobre esses recursos avançados.

> [!NOTE]
> Os erros de compilador e o processo passo a passo foi criado com o Visual C++ 2.0. Locais e mensagens de erro específica podem ter sido alterado com o Visual C++ 4.0, mas as informações conceituais permanecem válidas.

## <a name="getting-it-up-and-running"></a>-Lo em funcionamento

É a abordagem usada para a porta da amostra de OCLIENT para MFC/OLE começar a criá-lo e corrigindo os erros de compilador óbvio que o resultado serão. Se você usar o exemplo OCLIENT do MFC 2.0 e compilá-lo nesta versão do MFC, você encontrará que não há muitos erros para resolver. Os erros na ordem em que eles ocorreram são descritos abaixo.

## <a name="compile-and-fix-errors"></a>Compilação e corrija erros

```Output
\oclient\mainview.cpp(104) : error C2660: 'Draw' : function does not take 4 parameters
```

Primeiras preocupações quanto a erros `COleClientItem::Draw`. No MFC/OLE1 demorou mais parâmetros do que usa a versão MFC/OLE. Os parâmetros extras geralmente não eram necessárias e geralmente NULL (como neste exemplo). Esta versão do MFC pode determinar automaticamente os valores para o lpWBounds quando o CDC que está sendo desenhado para é um metarquivo do controlador de domínio. Além disso, o parâmetro pFormatDC não é necessário, pois a estrutura criará um do "atributo do controlador de domínio" do pDC passado. Portanto, para corrigir esse problema, basta remover as duas nulo extra de parâmetros para a chamada de desenho.

```Output
\oclient\mainview.cpp(273) : error C2065: 'OLE_MAXNAMESIZE' : undeclared identifier
\oclient\mainview.cpp(273) : error C2057: expected constant expression
\oclient\mainview.cpp(280) : error C2664: 'CreateLinkFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '
\oclient\mainview.cpp(286) : error C2664: 'CreateFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '
\oclient\mainview.cpp(288) : error C2664: 'CreateStaticFromClipboard' : cannot convert parameter 1 from 'char [1]' to 'enum ::tagOLERENDER '
```

Os erros acima resultado do fato de que todos os `COleClientItem::CreateXXXX` funções no MFC/OLE1 necessário que um nome exclusivo ser passado para representar o item. Esse era um requisito de OLE API subjacente. Isso não é necessário no MFC/OLE 2 como OLE 2 não usa o DDE como o mecanismo de comunicação subjacente (o nome foi usado em conversas do DDE). Para corrigir esse problema, você pode remover o `CreateNewName` de função, bem como todas as referências a ele. É fácil de descobrir o que cada função MFC/OLE é esperado nesta versão simplesmente, colocando o cursor na chamada e pressionar F1.

Outra área que é significativamente diferente é a manipulação de área de transferência OLE 2. Com OLE1, você usou o Windows da área de transferência que APIs interagem com a área de transferência. Com o OLE 2, isso é feito com um mecanismo diferente. As APIs MFC/OLE1 presume-se a área de transferência estava aberta antes de copiar um `COleClientItem` objeto para a área de transferência. Isso não é mais necessário e fará com que todas as operações de área de transferência MFC/OLE falhe. Enquanto você edita o código para remover dependências em `CreateNewName`, você também deve remover o código que abre e fecha a área de transferência do Windows.

```Output
\oclient\mainview.cpp(332) : error C2065: 'AfxOleInsertDialog' : undeclared identifier
\oclient\mainview.cpp(332) : error C2064: term does not evaluate to a function
\oclient\mainview.cpp(344) : error C2057: expected constant expression
\oclient\mainview.cpp(347) : error C2039: 'CreateNewObject' : is not a member of 'CRectItem'
```

Esses erros são provenientes de `CMainView::OnInsertObject` manipulador. Tratar o comando "Inserir o novo objeto" é outra área em que as coisas mudaram bastante. Nesse caso, é mais fácil simplesmente mesclar a implementação original com que o fornecido pelo AppWizard para um novo aplicativo de contêiner OLE. Na verdade, essa é uma técnica que você pode aplicar a portabilidade de outros aplicativos. No MFC/OLE1, é exibida a caixa de diálogo "Inserir o objeto" ao chamar `AfxOleInsertDialog` função. Nesta versão, você constrói uma `COleInsertObject` o objeto de caixa de diálogo e chamada `DoModal`. Além disso, os novos itens OLE são criados com um **CLSID** em vez de uma cadeia de caracteres do nome da classe. O resultado final deve ser semelhante a

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

Também é necessário incluir \<afxodlgs.h >, que contém a declaração para o `COleInsertObject` classe de caixa de diálogo, bem como as outras caixas de diálogo padrão fornecidas pelo MFC.

```Output
\oclient\mainview.cpp(367) : error C2065: 'OLEVERB_PRIMARY' : undeclared identifier
\oclient\mainview.cpp(367) : error C2660: 'DoVerb' : function does not take 1 parameters
```

Esses erros são causados pelo fato de que algumas constantes OLE1 foram alterados no OLE 2, mesmo que no conceito de que eles são os mesmos. Nesse caso `OLEVERB_PRIMARY` foi alterado para `OLEIVERB_PRIMARY`. No OLE1 e OLE 2, o verbo primário geralmente é executado por um contêiner quando o usuário clica duas vezes em um item.

Além disso, `DoVerb` agora usa um parâmetro extra — um ponteiro para um modo de exibição (`CView`*). Esse parâmetro só é usado para implementar "Edição Visual" (ou ativação in-loco). Por enquanto você definir esse parâmetro como NULL, porque você não estiver implementando esse recurso no momento.

Para certificar-se de que a estrutura nunca tenta in-loco ativar, você deve substituir `COleClientItem::CanActivate` da seguinte maneira:

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

No MFC/OLE1, `COleClientItem::GetBounds` e `SetBounds` foram usados para consultar e manipular a extensão de um item (o `left` e `top` membros foram sempre zero). No MFC/OLE 2 isso é suportado por mais diretamente `COleClientItem::GetExtent` e `SetExtent`, que lidam com um **tamanho** ou `CSize` em vez disso.

O código para seu novo SetItemRectToServer, e chamadas de UpdateItemRectFromServer ter esta aparência:

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

Na API síncrona de MFC/OLE1 chamadas de um contêiner para um servidor eram *simulado*, pois OLE1 foi inerentemente assíncrona em muitos casos. Foi necessário verificar se há uma chamada assíncrona pendente em andamento antes de processar os comandos do usuário. MFC/OLE1 fornecido a `COleClientItem::InWaitForRelease` função para fazer isso. No MFC/OLE 2 isso não é necessário, para que você possa remover a substituição do OnCommand CMainFrame juntos.

Neste ponto, OCLIENT irá compilar e vincular.

## <a name="other-necessary-changes"></a>Outras alterações necessárias

Há algumas coisas que não são executadas que irá manter OCLIENT execução, no entanto. É melhor corrigir esses problemas agora, em vez de mais tarde.

Primeiro, é necessário inicializar as bibliotecas OLE. Isso é feito chamando `AfxOleInit` de `InitInstance`:

```cpp
if (!AfxOleInit())
{
    AfxMessageBox("Failed to initialize OLE libraries");
    return FALSE;
}
```

Também é uma boa ideia verificar se há funções virtuais para alterações da lista de parâmetros. Uma dessas funções é `COleClientItem::OnChange`, substituídos em cada aplicativo de contêiner do MFC/OLE. Ao examinar a Ajuda online, você verá que um 'DWORD dwParam' extra foi adicionado. O novo CRectItem::OnChange será semelhante ao seguinte:

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

Em MFC/OLE1, aplicativos de contêiner derivada a classe de documento do `COleClientDoc`. No MFC/OLE 2 essa classe foi removida e substituída por `COleDocument` (essa nova organização facilita a criação de aplicativos de contêiner/servidor). Há um **#define** que mapeia `COleClientDoc` para `COleDocument` para simplificar a portabilidade de aplicativos do MFC/OLE1 para MFC/OLE 2, como OCLIENT. Um dos recursos não fornecidos pelo `COleDocument` que foi fornecido pelo `COleClientDoc` é a mensagem de comando padrão entradas de mapa. Isso é feito isso que aplicativos de servidor, que também usam `COleDocument` (indiretamente), não carregam com eles a sobrecarga de um desses manipuladores de comando, a menos que eles são um aplicativo de contêiner/servidor. Você precisará adicionar as seguintes entradas no mapa de mensagem CMainDoc:

```cpp
ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdatePasteMenu)
ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, OnUpdatePasteLinkMenu)
ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, OnUpdateEditLinksMenu)
ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, OnUpdateObjectVerbMenu)
ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, OnUpdateObjectVerbMenu)
ON_COMMAND(ID_OLE_EDIT_CONVERT, OnEditConvert)
```

A implementação de todos esses comandos está em `COleDocument`, que é a classe base para seu documento.

Neste ponto, OCLIENT é um aplicativo de contêiner OLE funcional. É possível inserir itens de qualquer tipo (OLE1 ou OLE 2). Uma vez que o código necessário para habilitar a ativação no local não for implementado, os itens são editados em uma janela separada que funcionam como com OLE1. A próxima seção discute as alterações necessárias para habilitar a edição in-loco (às vezes chamado de "Edição Visual").

## <a name="adding-visual-editing"></a>Adicionando "Edição Visual"

Um dos recursos mais interessantes do OLE é ativação no local (ou "Edição Visual"). Esse recurso permite que o aplicativo de servidor assumir o controle partes da interface do usuário do contêiner fornecido uma interface de edição mais transparente para o usuário. Para implementar a ativação in-loco OCLIENT, alguns recursos especiais precisarão ser adicionadas, além de algum código adicional. Esses recursos e o código normalmente são fornecidas pelo AppWizard — na verdade, grande parte do código aqui foi emprestado diretamente de um aplicativo por AppWizard atualizado com o suporte de "Contêiner".

Em primeiro lugar, é necessário adicionar um recurso de menu a ser usada quando há um item que está ativo no local. Você pode criar esse recurso de menu adicionais no Visual C++, copiando o recurso IDR_OCLITYPE e remoção de tudo, exceto os arquivo e a janela pop-ups. Duas barras de separação são inseridas entre os arquivo e janela pop-ups para indicar a separação de grupos de (deve se parecer com: arquivo de &#124; &#124; janela). Para obter mais informações sobre o que significam esses separadores e como os menus de servidor e um contêiner são mesclados, consulte [Menus e recursos: mesclagem de Menu](../mfc/menus-and-resources-menu-merging.md).

Uma vez que esses menus criados, você precisa informar o framework sobre eles. Isso é feito chamando `CDocTemplate::SetContainerInfo` para o modelo de documento antes de adicioná-lo à lista de modelos de documento em seu InitInstance. O novo código para registrar o modelo de documento tem esta aparência:

```cpp
CDocTemplate* pTemplate = new CMultiDocTemplate(
    IDR_OLECLITYPE,
    RUNTIME_CLASS(CMainDoc),
    RUNTIME_CLASS(CMDIChildWnd), // standard MDI child frame
    RUNTIME_CLASS(CMainView));

pTemplate->SetContainerInfo(IDR_OLECLITYPE_INPLACE);

AddDocTemplate(pTemplate);
```

O recurso IDR_OLECLITYPE_INPLACE é um recurso no local especial criado no Visual C++.

Para habilitar a ativação in-loco, há algumas coisas que precisam alterar em ambos os `CView` classe derivada de (CMainView), bem como a `COleClientItem` (CRectItem) da classe derivada. Todas essas substituições são fornecidas por AppWizard e a maioria da implementação virão diretamente de um aplicativo de AppWizard padrão.

Na primeira etapa dessa porta, a ativação no local foi desabilitada inteiramente, substituindo `COleClientItem::CanActivate`. Essa substituição deve ser removida para permitir a ativação in-loco. Além disso, nula é passada para todas as chamadas para `DoVerb` (há dois deles) porque só era necessária para a ativação in-loco fornecer o modo de exibição. Para implementar totalmente ativação in-loco, é necessário passar a exibição correta no `DoVerb` chamar. Uma dessas chamadas está em `CMainView::OnInsertObject`:

```cpp
pItem->DoVerb(OLEIVERB_SHOW, this);
```

Outro exemplo é na `CMainView::OnLButtonDblClk`:

```cpp
m_pSelection->DoVerb(OLEIVERB_PRIMARY, this);
```

É necessário substituir `COleClientItem::OnGetItemPosition`. Isso informa ao servidor onde colocar sua janela em relação à janela do contêiner quando o item é ativado no local. Para OCLIENT, a implementação é trivial:

```cpp
void CRectItem::OnGetItemPosition(CRect& rPosition)
{
    rPosition = m_rect;
}
```

A maioria dos servidores também implementar o que chamamos de "in-loco redimensionando." Isso permite que a janela do servidor ser dimensionado e movido enquanto o usuário está editando o item. O contêiner deve participar dessa ação, como mover ou redimensionar a janela geralmente afeta a posição e tamanho dentro do próprio documento contêiner. A implementação para OCLIENT sincroniza o retângulo interno mantido pelo m_rect com a nova posição e tamanho.

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

Neste ponto, há código suficiente para permitir que um item a ser ativado no local e para lidar com dimensionamento e a movimentação do item quando ele estiver ativo, mas nenhum código permitirá que o usuário saia da sessão de edição. Embora alguns servidores fornecerá essa funcionalidade em si ao manipular a tecla ESC, é recomendável que os contêineres fornecem duas maneiras para desativar um item: (1), clicando fora do item e (2), pressionando a tecla ESCAPE.

Para a chave ESCAPE, adicionar um acelerador com o Visual C++ que mapeia a chave VK_ESCAPE para um comando, ID_CANCEL_EDIT é adicionado aos recursos. O manipulador para este comando a seguir:

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

Para manipular o caso em que o usuário clica fora do item, você deve adicionar o código a seguir ao início do `CMainView::SetSelection`:

```cpp
if (pNewSel != m_pSelection || pNewSel == NULL)
{
    COleClientItem* pActiveItem =
        GetDocument()->GetInPlaceActiveItem(this);
    if (pActiveItem != NULL&& pActiveItem != pNewSel)
        pActiveItem->Close();
}
```

Quando um item é ativado, ele deve ter o foco. Para verificar se que esse for o caso, você manipular OnSetFocus, de modo que foco sempre é transferido para o item ativo quando o modo de exibição recebe o foco:

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

Quando o modo de exibição for redimensionado, você precisa notificar o item Active Directory que o retângulo de recorte foi alterado. Para fazer isso é fornecer um manipulador para `OnSize`:

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

## <a name="case-study-hiersvr-from-mfc-20"></a>Estudo de caso: HIERSVR do MFC 2.0

[HIERSVR](../visual-cpp-samples.md) também foi incluído no MFC 2.0 e implementado OLE com MFC/OLE1. Essa observação descreve brevemente as etapas pelas quais este aplicativo foi inicialmente convertido para usar as classes MFC/OLE 2. Uma série de recursos foram adicionada depois que a porta inicial foi concluída para melhor ilustrar as classes MFC/OLE 2. Esses recursos não serão abordados aqui; Consulte o exemplo para obter mais informações sobre esses recursos avançados.

> [!NOTE]
> Os erros de compilador e o processo passo a passo foi criado com o Visual C++ 2.0. Locais e mensagens de erro específica podem ter sido alterado com o Visual C++ 4.0, mas as informações conceituais permanecem válidas.

## <a name="getting-it-up-and-running"></a>-Lo em funcionamento

É a abordagem usada para a porta da amostra de HIERSVR para MFC/OLE começar a criá-lo e corrigindo os erros de compilador óbvio que o resultado serão. Se você usar o exemplo HIERSVR do MFC 2.0 e compilá-lo nesta versão do MFC, você encontrará que não há muitos erros para resolver (Apesar de haver mais de com o exemplo OCLIENT). Os erros na ordem em que elas ocorrem geralmente são descritos abaixo.

## <a name="compile-and-fix-errors"></a>Compilação e corrija erros

```Output
\hiersvr\hiersvr.cpp(83) : error C2039: 'RunEmbedded' : is not a member of 'COleTemplateServer'
```

Este primeiro erro indica um problema muito maior com o `InitInstance` função para servidores. A inicialização necessária para um servidor OLE é provavelmente uma das maiores alterações que você terá que fazer ao seu aplicativo do MFC/OLE1 para executá-lo. A melhor coisa a fazer é examinar o que o AppWizard não cria para um servidor OLE e modificar seu código conforme apropriado. Aqui estão alguns pontos a ter em mente:

É necessário inicializar as bibliotecas OLE chamando `AfxOleInit`

Chamar SetServerInfo no objeto de modelo de documento para definir identificadores de recurso de servidor e informações de classe de tempo de execução que não podem ser definidas com o `CDocTemplate` construtor.

Não mostra a janela principal do seu aplicativo se a opção /Embedding está presente na linha de comando.

Você precisará de uma **GUID** para seu documento. Este é um identificador exclusivo para o tipo do documento (128 bits). O AppWizard criará um para você — portanto, se você usar a técnica descrita aqui de copiar o novo código de um novo aplicativo de servidor AppWizard gerado, você pode simplesmente "roube" o GUID do aplicativo. Caso contrário, você pode usar o GUIDGEN. Utilitário do EXE no diretório BIN.

É necessário se "conectar" sua `COleTemplateServer` objeto para o modelo de documento chamando `COleTemplateServer::ConnectTemplate`.

Atualize o registro do sistema quando seu aplicativo for executado autônomo. Dessa forma, se o usuário move o. EXE para seu aplicativo, executá-lo no seu novo local atualizará o banco de dados de registro do Windows system para apontar para o novo local.

Após a aplicação de todas essas alterações com base no qual o AppWizard não cria para `InitInstance`, o `InitInstance` (e relacionados ao GUID) para HIERSVR deve ler da seguinte maneira:

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

Você observará que o código acima se refere a uma nova ID de recurso, IDR_HIERSVRTYPE_SRVR_EMB. Este é o recurso de menu a ser usado quando um documento que está inserido em outro contêiner é editado. Em MFC/OLE1 os itens de menu específicos para editar um item inserido foram modificados em tempo real. Usar uma estrutura de menu totalmente diferente ao editar um item inserido em vez de editar um documento baseado em arquivo torna muito mais fácil fornecer diferentes interfaces de usuário para esses dois modos separados. Como você verá mais tarde, um recurso de menu totalmente separada é usado ao editar um objeto inserido no local.

Para criar esse recurso, carregar o script de recurso no Visual C++ e copiar o recurso de menu IDR_HIERSVRTYPE existente. Renomeie o novo recurso para IDR_HIERSVRTYPE_SRVR_EMB (essa é a mesma convenção de nomenclatura AppWizard usa). Em seguida alterar "Arquivo Salvar" para "Atualização do arquivo"; Dê a ele comando ID_FILE_UPDATE ID. Além disso, alterar "Arquivo Salvar como" para "Arquivo Salvar cópia como"; Dê a ele comando ID_FILE_SAVE_COPY_AS ID. O framework fornece a implementação dos dois desses comandos.

```Output
\hiersvr\svritem.h(60) : error C2433: 'OLESTATUS' : 'virtual' not permitted on data declarations
\hiersvr\svritem.h(60) : error C2501: 'OLESTATUS' : missing decl-specifiers
\hiersvr\svritem.h(60) : error C2146: syntax error : missing ';' before identifier 'OnSetData'
\hiersvr\svritem.h(60) : error C2061: syntax error : identifier 'OLECLIPFORMAT'
\hiersvr\svritem.h(60) : error C2501: 'OnSetData' : missing decl-specifiers
```

Há um número de erros resultantes de substituição do `OnSetData`, uma vez que ele está se referindo a **OLESTATUS** tipo. **OLESTATUS** era a maneira OLE1 retornados os erros. Isso foi alterado para **HRESULT** no OLE 2, embora o MFC geralmente converte um **HRESULT** em um `COleException` que contém o erro. Nesse caso específico, a substituição do `OnSetData` não é mais necessária, portanto, a coisa mais fácil a fazer é removê-lo.

```Output
\hiersvr\svritem.cpp(30) : error C2660: 'COleServerItem::COleServerItem' : function does not take 1 parameters
```

O `COleServerItem` construtor aceita um parâmetro de 'BOOL' extra. Este sinalizador determina como o gerenciamento de memória é feito na `COleServerItem` objetos. Definindo-o como TRUE, a estrutura lida com o gerenciamento de memória desses objetos — excluí-los quando eles não são mais necessários. Usa HIERSVR `CServerItem` (derivado de `COleServerItem`) objetos como parte de seus dados nativos, portanto, você definirá esse sinalizador como FALSE. Isso permite HIERSVR determinar quando cada item do servidor é excluído.

```Output
\hiersvr\svritem.cpp(44) : error C2259: 'CServerItem' : illegal attempt to instantiate abstract class
\hiersvr\svritem.cpp(44) : error C2259: 'CServerItem' : illegal attempt to instantiate abstract class
```

Como esses erros sugerem, há algumas funções 'pura virtual' que não foram substituídas no CServerItem. Provavelmente, isso é causado pelo fato de que a lista de parâmetros do OnDraw foi alterado. Para corrigir esse erro, altere `CServerItem::OnDraw` da seguinte maneira (bem como a declaração em svritem.h):

```cpp
BOOL CServerItem::OnDraw(CDC* pDC, CSize& rSize)
{
    // request from OLE to draw node
    pDC->SetMapMode(MM_TEXT); // always in pixels
    return DoDraw(pDC, CPoint(0, 0), FALSE);
}
```

O novo parâmetro é 'rSize'. Isso permite que você preencha o tamanho de desenho, se for conveniente. Esse tamanho deve estar no **HIMETRIC**. Nesse caso, ele não é conveniente preencher esse valor, portanto, o framework chama `OnGetExtent` para recuperar a extensão. Para que isso funcione, você precisará implementar `OnGetExtent`:

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

Na função CServerItem::CalcNodeSize o tamanho do item é convertido em **HIMETRIC** e armazenado em *m_rectBounds*. O não-documentadas '*m_rectBounds*' membro da `COleServerItem` não existe (foi parcialmente substituído por *m_sizeExtent*, mas no OLE 2 Este membro tem um uso de um pouco diferente de *m_rectBounds* fazia no OLE1). Em vez de definir a **HIMETRIC** tamanho nessa variável de membro, você vai retorná-lo. Esse valor de retorno é usado em `OnGetExtent`, implementado anteriormente.

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

Também substitui CServerItem `COleServerItem::OnGetTextData`. Essa função está obsoleta no MFC/OLE e é substituída por um mecanismo diferente. A versão 3.0 do MFC o exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md) implementa essa funcionalidade por meio da substituição `COleServerItem::OnRenderFileData`. Essa funcionalidade não é importante para essa porta básica, portanto, você pode remover a substituição de OnGetTextData.

Há muito mais erros na svritem.cpp que não foram resolvidos. Eles não são erros "reais" – apenas erros causados por erros anteriores.

```Output
\hiersvr\svrview.cpp(325) : error C2660: 'CopyToClipboard' : function does not take 2 parameters
```

`COleServerItem::CopyToClipboard` não é compatível com o `bIncludeNative` sinalizador. Os dados nativos (os dados gravados pela função de serialização do item de servidor) sempre são copiados, portanto, você remover o primeiro parâmetro. Além disso, `CopyToClipboard` lançará uma exceção quando ocorrer um erro em vez de retornar FALSE. Altere o código para CServerView::OnEditCopy da seguinte maneira:

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

Embora houvesse mais erros resultantes da compilação da versão 2.0 do MFC do HIERSVR que havia para a mesma versão do OCLIENT, havia realmente menos alterações.

Neste ponto HIERSVR compilar e vincular e funcionar como um servidor OLE, mas sem o recurso de edição in-loco, que será implementado em seguida.

## <a name="adding-visual-editing"></a>Adicionando "Edição Visual"

Para adicionar "Edição Visual" (ou ativação in-loco) para este aplicativo de servidor, há apenas algumas coisas que você precisa se encarregar:

- Você precisa de um recurso de menu especial a ser usado quando o item ativo no local.

- Este aplicativo tem uma barra de ferramentas, portanto, você precisará de uma barra de ferramentas com apenas um subconjunto da barra de ferramentas normal para coincidir com os comandos de menu disponíveis no servidor (coincide com o recurso de menu mencionado acima).

- Você precisa de uma nova classe derivada `COleIPFrameWnd` que fornece a interface do usuário no local (assim como na CMainFrame, derivada de `CMDIFrameWnd`, fornece a interface do usuário MDI).

- Você precisa dizer à estrutura sobre essas classes e recursos especiais.

O recurso de menu é fácil de criar. Executar o Visual C++, copiar o recurso de menu IDR_HIERSVRTYPE para um recurso de menu chamado IDR_HIERSVRTYPE_SRVR_IP. Modifique o menu para que somente as edição e a Ajuda do menu pop-ups são deixados. Adicionar dois separadores ao menu entre menus editar e ajuda (deve se parecer com: editar &#124; &#124; ajuda). Para obter mais informações sobre o que significam esses separadores e como os menus de servidor e um contêiner são mesclados, consulte [Menus e recursos: mesclagem de Menu](../mfc/menus-and-resources-menu-merging.md).

O bitmap para a barra de ferramentas do subconjunto pode ser criado facilmente, copiando aquele de um aplicativo atualizado do AppWizard gerado com uma opção "Servidor" marcada. Esse bitmap pode ser importado para o Visual C++. Certifique-se de dar a um ID de IDR_HIERSVRTYPE_SRVR_IP o bitmap.

A classe derivada de `COleIPFrameWnd` podem ser copiadas de um aplicativo por AppWizard gerado com suporte do servidor também. Copie os dois arquivos, IPFRAME. CPP e IPFRAME. H e adicioná-los ao projeto. Certifique-se de que o `LoadBitmap` chamada refere-se ao IDR_HIERSVRTYPE_SRVR_IP, o bitmap criado na etapa anterior.

Agora que todos os novos recursos e classes são criadas, adicione o código necessário para que o framework sabe sobre esses (e sabe que esse aplicativo agora dá suporte a edição in-loco). Isso é feito pela adição de alguns parâmetros mais para o `SetServerInfo` chamar o `InitInstance` função:

```cpp
pDocTemplate->SetServerInfo(IDR_HIERSVRTYPE_SRVR_EMB,
    IDR_HIERSVRTYPE_SRVR_IP,
    RUNTIME_CLASS(CInPlaceFrame));
```

Agora está pronto para ser executado no local em qualquer contêiner que também dá suporte à ativação no local. Mas, há um pequeno bug ainda preciosa escondida no código. HIERSVR dá suporte a um menu de contexto exibido quando o usuário pressiona o botão direito do mouse. Esse menu funciona quando HIERSVR está totalmente aberto, mas não funciona quando você editar um inserção no local. O motivo pode ser fixado para baixo para essa única linha de código em CServerView::OnRButtonDown:

```cpp
pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,
    point.x,
    point.y,
    AfxGetApp()->m_pMainWnd);
```

Observe a referência ao `AfxGetApp()->m_pMainWnd`. Quando o servidor está ativado no local, ele tem uma janela principal e m_pMainWnd é definido, mas é geralmente invisível. Além disso, esta janela refere-se para o *principal* janela do aplicativo, a janela do quadro MDI que aparece quando o servidor está totalmente abrir ou executar autônoma. Ele não faz referência à janela do quadro ativo — que quando in-loco ativado é um quadro de janela é derivado de `COleIPFrameWnd`. Para obter a janela ativa correta, mesmo quando a ativação in-loco, esta versão do MFC adiciona uma nova função, `AfxGetMainWnd`. Em geral, você deve usar essa função em vez de `AfxGetApp()->m_pMainWnd`. Esse código necessitará de alteração da seguinte maneira:

```cpp
pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,
    point.x,
    point.y,
    AfxGetMainWnd());
```

Agora você tem um servidor OLE minimamente habilitado para a ativação in-loco funcional. Mas há ainda muitos recursos disponíveis com o MFC/OLE 2 que não estavam disponíveis no MFC/OLE1. Veja o exemplo HIERSVR para obter mais ideias sobre os recursos que você talvez queira implementar. Alguns dos recursos que implementa HIERSVR estão listados abaixo:

- Aplicar zoom para o verdadeiro comportamento WYSIWYG em relação ao contêiner.

- Arrastar / soltar e um formato personalizado da área de transferência.

- Rolar a janela de contêiner como a seleção é alterada.

O exemplo HIERSVR no MFC 3.0 também usa um design ligeiramente diferente para seus itens de servidor. Isso ajuda a conservar a memória e torna os links mais flexível. Com a versão 2.0 do HIERSVR cada nó na árvore *é um* `COleServerItem`. `COleServerItem` executa um pouco mais sobrecarga do que é estritamente necessária para cada um de nós, mas um `COleServerItem` é necessária para cada link ativo. Mas, geralmente, há muito poucos links ativos em um determinado momento. Para tornar mais eficiente, o HIERSVR nesta versão do MFC separa o nó a partir de `COleServerItem`. Ele tem dois CServerNode um e um `CServerItem` classe. O `CServerItem` (derivado de `COleServerItem`) é criado somente conforme necessário. Quando o contêiner (ou contêineres) parar de usar esse link específico para esse nó em particular, o objeto de CServerItem associado com o CServerNode será excluído. Esse design é mais eficiente e mais flexível. Sua flexibilidade vem em ao lidar com vários links de seleção. Nenhuma dessas duas versões do HIERSVR suporte à seleção múltipla, mas ele seria muito mais fácil para adicionar (e para dar suporte a links para essas seleções) com a versão de MFC 3.0 do HIERSVR, já que o `COleServerItem` é separado de dados nativos.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
