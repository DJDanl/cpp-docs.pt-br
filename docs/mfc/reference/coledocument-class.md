---
title: Classe COleDocument
ms.date: 11/04/2016
f1_keywords:
- COleDocument
- AFXOLE/COleDocument
- AFXOLE/COleDocument::COleDocument
- AFXOLE/COleDocument::AddItem
- AFXOLE/COleDocument::ApplyPrintDevice
- AFXOLE/COleDocument::EnableCompoundFile
- AFXOLE/COleDocument::GetInPlaceActiveItem
- AFXOLE/COleDocument::GetNextClientItem
- AFXOLE/COleDocument::GetNextItem
- AFXOLE/COleDocument::GetNextServerItem
- AFXOLE/COleDocument::GetPrimarySelectedItem
- AFXOLE/COleDocument::GetStartPosition
- AFXOLE/COleDocument::HasBlankItems
- AFXOLE/COleDocument::OnShowViews
- AFXOLE/COleDocument::RemoveItem
- AFXOLE/COleDocument::UpdateModifiedFlag
- AFXOLE/COleDocument::OnEditChangeIcon
- AFXOLE/COleDocument::OnEditConvert
- AFXOLE/COleDocument::OnEditLinks
- AFXOLE/COleDocument::OnFileSendMail
- AFXOLE/COleDocument::OnUpdateEditChangeIcon
- AFXOLE/COleDocument::OnUpdateEditLinksMenu
- AFXOLE/COleDocument::OnUpdateObjectVerbMenu
- AFXOLE/COleDocument::OnUpdatePasteLinkMenu
- AFXOLE/COleDocument::OnUpdatePasteMenu
helpviewer_keywords:
- COleDocument [MFC], COleDocument
- COleDocument [MFC], AddItem
- COleDocument [MFC], ApplyPrintDevice
- COleDocument [MFC], EnableCompoundFile
- COleDocument [MFC], GetInPlaceActiveItem
- COleDocument [MFC], GetNextClientItem
- COleDocument [MFC], GetNextItem
- COleDocument [MFC], GetNextServerItem
- COleDocument [MFC], GetPrimarySelectedItem
- COleDocument [MFC], GetStartPosition
- COleDocument [MFC], HasBlankItems
- COleDocument [MFC], OnShowViews
- COleDocument [MFC], RemoveItem
- COleDocument [MFC], UpdateModifiedFlag
- COleDocument [MFC], OnEditChangeIcon
- COleDocument [MFC], OnEditConvert
- COleDocument [MFC], OnEditLinks
- COleDocument [MFC], OnFileSendMail
- COleDocument [MFC], OnUpdateEditChangeIcon
- COleDocument [MFC], OnUpdateEditLinksMenu
- COleDocument [MFC], OnUpdateObjectVerbMenu
- COleDocument [MFC], OnUpdatePasteLinkMenu
- COleDocument [MFC], OnUpdatePasteMenu
ms.assetid: dc2ecb99-03e1-44c7-bb69-48056dd1b672
ms.openlocfilehash: b92c796fdaa972966dcbfa85b1e34f267b6c629c
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421096"
---
# <a name="coledocument-class"></a>Classe COleDocument

A classe base para documentos OLE que dão suporte à edição visual.

## <a name="syntax"></a>Sintaxe

```
class COleDocument : public CDocument
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDocument::COleDocument](#coledocument)|Constrói um objeto `COleDocument`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDocument:: AddItem](#additem)|Adiciona um item à lista de itens mantidos pelo documento.|
|[COleDocument::ApplyPrintDevice](#applyprintdevice)|Define o dispositivo de destino de impressão para todos os itens do cliente no documento.|
|[COleDocument::EnableCompoundFile](#enablecompoundfile)|Faz com que os documentos sejam armazenados usando o formato de arquivo de armazenamento estruturado OLE.|
|[COleDocument::GetInPlaceActiveItem](#getinplaceactiveitem)|Retorna o item OLE que está ativo no local no momento.|
|[COleDocument::GetNextClientItem](#getnextclientitem)|Obtém o próximo item do cliente para iteração.|
|[COleDocument::GetNextItem](#getnextitem)|Obtém o próximo item de documento para iteração.|
|[COleDocument::GetNextServerItem](#getnextserveritem)|Obtém o próximo item de servidor para iteração.|
|[COleDocument::GetPrimarySelectedItem](#getprimaryselecteditem)|Retorna o item OLE selecionado primário no documento.|
|[COleDocument:: GetStartPosition](#getstartposition)|Obtém a posição inicial para iniciar a iteração.|
|[COleDocument::HasBlankItems](#hasblankitems)|Verifica se há itens em branco no documento.|
|[COleDocument::OnShowViews](#onshowviews)|Chamado quando o documento se torna visível ou invisível.|
|[COleDocument:: RemoveItem](#removeitem)|Remove um item da lista de itens mantidos pelo documento.|
|[COleDocument::UpdateModifiedFlag](#updatemodifiedflag)|Marca o documento como modificado se algum dos itens OLE contidos tiver sido modificado.|

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDocument::OnEditChangeIcon](#oneditchangeicon)|Manipula eventos no comando de menu Alterar ícone.|
|[COleDocument::OnEditConvert](#oneditconvert)|Manipula a conversão de um objeto inserido ou vinculado de um tipo para outro.|
|[COleDocument::OnEditLinks](#oneditlinks)|Manipula eventos no comando links no menu Editar.|
|[COleDocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de email com o documento anexado.|
|[COleDocument::OnUpdateEditChangeIcon](#onupdateeditchangeicon)|Chamado pelo Framework para atualizar a interface do usuário do comando para a opção de menu Editar/Alterar ícone.|
|[COleDocument::OnUpdateEditLinksMenu](#onupdateeditlinksmenu)|Chamado pelo Framework para atualizar a interface do usuário do comando para a opção de menu Editar/vincular.|
|[COleDocument::OnUpdateObjectVerbMenu](#onupdateobjectverbmenu)|Chamado pelo Framework para atualizar a interface do usuário do comando para a opção de menu Editar/ *objectname* e o submenu verbo acessado em Editar/ *objectname*.|
|[COleDocument::OnUpdatePasteLinkMenu](#onupdatepastelinkmenu)|Chamado pelo Framework para atualizar a interface do usuário do comando para a opção Colar especial menu.|
|[COleDocument::OnUpdatePasteMenu](#onupdatepastemenu)|Chamado pelo Framework para atualizar a interface do usuário do comando para a opção de menu colar.|

## <a name="remarks"></a>Comentários

`COleDocument` é derivado de `CDocument`, que permite que seus aplicativos OLE usem a arquitetura de documento/exibição fornecida pelo biblioteca MFC.

`COleDocument` trata um documento como uma coleção de objetos [CDocItem](../../mfc/reference/cdocitem-class.md) para manipular itens OLE. Os aplicativos de contêiner e de servidor exigem essa arquitetura, pois seus documentos devem ser capazes de conter itens OLE. As classes [COleServerItem](../../mfc/reference/coleserveritem-class.md) e [COleClientItem](../../mfc/reference/coleclientitem-class.md) , derivadas de `CDocItem`, gerenciam as interações entre aplicativos e itens OLE.

Se você estiver escrevendo um aplicativo de contêiner simples, derive sua classe de documento de `COleDocument`. Se você estiver escrevendo um aplicativo de contêiner que dá suporte à vinculação com os itens inseridos contidos por seus documentos, derive a classe de documento de [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md). Se você estiver escrevendo um aplicativo de servidor ou um contêiner/servidor de combinação, derive a classe de documento de [COleServerDoc](../../mfc/reference/coleserverdoc-class.md). `COleLinkingDoc` e `COleServerDoc` derivam de `COleDocument`, portanto, essas classes herdam todos os serviços disponíveis em `COleDocument` e `CDocument`.

Para usar `COleDocument`, derive uma classe dela e adicione funcionalidade para gerenciar os dados não OLE do aplicativo, bem como itens incorporados ou vinculados. Se você definir classes derivadas de `CDocItem`para armazenar os dados nativos do aplicativo, poderá usar a implementação padrão definida por `COleDocument` para armazenar seus dados OLE e não OLE. Você também pode criar suas próprias estruturas de dados para armazenar seus dados não OLE separadamente dos itens OLE. Para obter mais informações, consulte o artigo [contêineres: arquivos compostos](../../mfc/containers-compound-files.md)..

`CDocument` dá suporte ao envio de seu documento por email se o MAPI (suporte de email) estiver presente. `COleDocument` atualizou o [OnFileSendMail](#onfilesendmail) para lidar com documentos compostos corretamente. Para obter mais informações, consulte os artigos suporte [MAPI](../../mfc/mapi.md) e [MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocument](../../mfc/reference/cdocument-class.md)

`COleDocument`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="additem"></a>COleDocument:: AddItem

Chame essa função para adicionar um item ao documento.

```
virtual void AddItem(CDocItem* pItem);
```

### <a name="parameters"></a>parâmetros

*pItem*<br/>
Ponteiro para o item de documento que está sendo adicionado.

### <a name="remarks"></a>Comentários

Você não precisa chamar essa função explicitamente quando ela é chamada pelo Construtor `COleClientItem` ou `COleServerItem` que aceita um ponteiro para um documento.

##  <a name="applyprintdevice"></a>COleDocument::ApplyPrintDevice

Chame essa função para alterar o dispositivo de destino de impressão para todos os itens [COleClientItem](../../mfc/reference/coleclientitem-class.md) inseridos no documento de contêiner do seu aplicativo.

```
BOOL ApplyPrintDevice(const DVTARGETDEVICE* ptd);
BOOL ApplyPrintDevice(const PRINTDLG* ppd);
```

### <a name="parameters"></a>parâmetros

*ptd*<br/>
Ponteiro para uma estrutura de dados `DVTARGETDEVICE`, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.

*PPD*<br/>
Ponteiro para uma estrutura de dados `PRINTDLG`, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função atualiza o dispositivo de destino de impressão para todos os itens, mas não atualiza o cache de apresentação para esses itens. Para atualizar o cache de apresentação de um item, chame [COleClientItem:: UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink).

Os argumentos para essa função contêm informações que o OLE usa para identificar o dispositivo de destino. A estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) contém informações que o Windows usa para inicializar a caixa de diálogo Imprimir comum. Depois que o usuário fecha a caixa de diálogo, o Windows retorna informações sobre as seleções do usuário nesta estrutura. O membro de `m_pd` de um objeto [CPrintDialog](../../mfc/reference/cprintdialog-class.md) é uma estrutura de `PRINTDLG`.

Para obter mais informações, consulte a estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) no SDK do Windows.

Para obter mais informações, consulte a estrutura [DVTARGETDEVICE](/windows/win32/api/objidl/ns-objidl-dvtargetdevice) no SDK do Windows.

##  <a name="coledocument"></a>COleDocument::COleDocument

Constrói um objeto `COleDocument`.

```
COleDocument();
```

##  <a name="enablecompoundfile"></a>COleDocument::EnableCompoundFile

Chame essa função se desejar armazenar o documento usando o formato de arquivo composto.

```
void EnableCompoundFile(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>parâmetros

*bEnable*<br/>
Especifica se o suporte ao arquivo composto está habilitado ou desabilitado.

### <a name="remarks"></a>Comentários

Isso também é chamado de armazenamento estruturado. Normalmente, você chama essa função do construtor de sua classe derivada de `COleDocument`. Para obter mais informações sobre documentos compostos, consulte o artigo [contêineres: arquivos compostos](../../mfc/containers-compound-files.md)..

Se você não chamar essa função de membro, os documentos serão armazenados em um formato de arquivo não estruturado ("plano").

Depois que o suporte a arquivos compostos estiver habilitado ou desabilitado para um documento, a configuração não deverá ser alterada durante o tempo de vida do documento.

##  <a name="getinplaceactiveitem"></a>COleDocument::GetInPlaceActiveItem

Chame essa função para obter o item OLE que está atualmente ativado no local na janela do quadro que contém a exibição identificada por *pWnd*.

```
virtual COleClientItem* GetInPlaceActiveItem(CWnd* pWnd);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Ponteiro para a janela que exibe o documento de contêiner.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o único item OLE ativo no local; NULL se não houver nenhum item OLE atualmente no estado "ativo no local".

##  <a name="getnextclientitem"></a>COleDocument::GetNextClientItem

Chame essa função repetidamente para acessar cada um dos itens do cliente em seu documento.

```
COleClientItem* GetNextClientItem(POSITION& pos) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Uma referência a um valor de posição definido por uma chamada anterior para `GetNextClientItem`; o valor inicial é retornado pela função membro `GetStartPosition`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo item de cliente no documento, ou NULL se não houver mais itens de cliente.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor de *pos* é definido para o próximo item no documento, que pode ou não ser um item de cliente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#1](../../mfc/codesnippet/cpp/coledocument-class_1.cpp)]

##  <a name="getnextitem"></a>COleDocument::GetNextItem

Chame essa função repetidamente para acessar cada um dos itens em seu documento.

```
virtual CDocItem* GetNextItem(POSITION& pos) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Uma referência a um valor de posição definido por uma chamada anterior para `GetNextItem`; o valor inicial é retornado pela função membro `GetStartPosition`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o item de documento na posição especificada.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor de *pos* é definido como o valor de posição do próximo item no documento. Se o elemento recuperado for o último elemento do documento, o novo valor de *pos* será nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#2](../../mfc/codesnippet/cpp/coledocument-class_2.cpp)]

##  <a name="getnextserveritem"></a>COleDocument::GetNextServerItem

Chame essa função repetidamente para acessar cada um dos itens do servidor em seu documento.

```
COleServerItem* GetNextServerItem(POSITION& pos) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Uma referência a um valor de posição definido por uma chamada anterior para `GetNextServerItem`; o valor inicial é retornado pela função membro `GetStartPosition`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo item de servidor no documento, ou NULL se não houver mais itens de servidor.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor de *pos* é definido para o próximo item no documento, que pode ou não ser um item de servidor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleServer#2](../../mfc/codesnippet/cpp/coledocument-class_3.cpp)]

##  <a name="getprimaryselecteditem"></a>COleDocument::GetPrimarySelectedItem

Chamado pelo Framework para recuperar o item OLE selecionado no momento no modo de exibição especificado.

```
virtual COleClientItem* GetPrimarySelectedItem(CView* pView);
```

### <a name="parameters"></a>parâmetros

*pView*<br/>
Ponteiro para o objeto de modo de exibição ativo que exibe o documento.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o único item OLE selecionado; NULL se nenhum item OLE for selecionado ou se houver mais de um selecionado.

### <a name="remarks"></a>Comentários

A implementação padrão pesquisa a lista de itens OLE contidos em um único item selecionado e retorna um ponteiro para ele. Se não houver nenhum item selecionado, ou se houver mais de um item selecionado, a função retornará NULL. Você deve substituir a função de membro `CView::IsSelected` na sua classe de exibição para que essa função funcione. Substitua essa função se você tiver seu próprio método de armazenar itens OLE contidos.

##  <a name="getstartposition"></a>COleDocument:: GetStartPosition

Chame essa função para obter a posição do primeiro item no documento.

```
virtual POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para começar a iterar por meio dos itens do documento; NULL se o documento não tiver nenhum item.

### <a name="remarks"></a>Comentários

Passe o valor retornado para `GetNextItem`, `GetNextClientItem`ou `GetNextServerItem`.

##  <a name="hasblankitems"></a>COleDocument::HasBlankItems

Chame essa função para determinar se o documento contém itens em branco.

```
BOOL HasBlankItems() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento contiver qualquer item em branco; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item em branco é aquele cujo retângulo está vazio.

##  <a name="oneditchangeicon"></a>COleDocument::OnEditChangeIcon

Exibe a caixa de diálogo ícone de alteração OLE e altera o ícone que representa o item OLE selecionado no momento para o ícone que o usuário seleciona na caixa de diálogo.

```
afx_msg void OnEditChangeIcon();
```

### <a name="remarks"></a>Comentários

`OnEditChangeIcon` cria e inicia uma caixa de diálogo `COleChangeIconDialog` ícone de alteração.

##  <a name="oneditconvert"></a>COleDocument::OnEditConvert

Exibe a caixa de diálogo conversão OLE e converte ou ativa o item OLE selecionado de acordo com as seleções do usuário na caixa de diálogo.

```
afx_msg void OnEditConvert();
```

### <a name="remarks"></a>Comentários

`OnEditConvert` cria e inicia uma caixa de diálogo `COleConvertDialog` converter.

Um exemplo de conversão é converter um documento do Microsoft Word em um documento do WordPad.

##  <a name="oneditlinks"></a>COleDocument::OnEditLinks

Exibe a caixa de diálogo Editar/vincular OLE.

```
afx_msg void OnEditLinks();
```

### <a name="remarks"></a>Comentários

`OnEditLinks` cria e inicia uma caixa de diálogo links de `COleLinksDialog` que permite ao usuário alterar os objetos vinculados.

##  <a name="onfilesendmail"></a>COleDocument::OnFileSendMail

Envia uma mensagem por meio do host de email residente (se houver) com o documento como um anexo.

```
afx_msg void OnFileSendMail();
```

### <a name="remarks"></a>Comentários

`OnFileSendMail` chama `OnSaveDocument` para serializar (salvar) documentos sem título e modificados em um arquivo temporário, que é enviado por email. Se o documento não tiver sido modificado, um arquivo temporário não será necessário; o original é enviado. `OnFileSendMail` carrega MAPI32. DLL se ainda não tiver sido carregado.

Ao contrário da implementação de `OnFileSendMail` para `CDocument`, essa função trata os arquivos compostos corretamente.

Para obter mais informações, consulte os [tópicos sobre MAPI](../../mfc/mapi.md) e [suporte MAPI em MFC](../../mfc/mapi-support-in-mfc.md) .

##  <a name="onshowviews"></a>COleDocument::OnShowViews

A estrutura chama essa função depois que o estado de visibilidade do documento é alterado.

```
virtual void OnShowViews(BOOL bVisible);
```

### <a name="parameters"></a>parâmetros

*bVisible*<br/>
Indica se o documento tornou-se visível ou invisível.

### <a name="remarks"></a>Comentários

A versão padrão dessa função não faz nada. Substitua-o se seu aplicativo precisar executar qualquer processamento especial quando a visibilidade do documento for alterada.

##  <a name="onupdateeditchangeicon"></a>COleDocument::OnUpdateEditChangeIcon

Chamado pelo Framework para atualizar o comando Alterar ícone no menu Editar.

```
afx_msg void OnUpdateEditChangeIcon(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>parâmetros

*pCmdUI*<br/>
Um ponteiro para uma estrutura de `CCmdUI` que representa o menu que gerou o comando de atualização. O manipulador de atualização chama a função de membro `Enable` da estrutura de `CCmdUI` por meio do *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

`OnUpdateEditChangeIcon` atualiza a interface do usuário do comando dependendo se um ícone válido existe ou não no documento. Substitua essa função para alterar o comportamento.

##  <a name="onupdateeditlinksmenu"></a>COleDocument::OnUpdateEditLinksMenu

Chamado pelo Framework para atualizar o comando links no menu Editar.

```
afx_msg void OnUpdateEditLinksMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>parâmetros

*pCmdUI*<br/>
Um ponteiro para uma estrutura de `CCmdUI` que representa o menu que gerou o comando de atualização. O manipulador de atualização chama a função de membro `Enable` da estrutura de `CCmdUI` por meio do *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

Começando com o primeiro item OLE no documento, `OnUpdateEditLinksMenu` acessa cada item, testa se o item é um link e, se for um link, habilita o comando links. Substitua essa função para alterar o comportamento.

##  <a name="onupdateobjectverbmenu"></a>COleDocument::OnUpdateObjectVerbMenu

Chamado pelo Framework para atualizar o comando *objectname* no menu Editar e o submenu verbo acessado a partir do comando *objectname* , em que *objectname* é o nome do objeto OLE inserido no documento.

```
afx_msg void OnUpdateObjectVerbMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>parâmetros

*pCmdUI*<br/>
Um ponteiro para uma estrutura de `CCmdUI` que representa o menu que gerou o comando de atualização. O manipulador de atualização chama a função de membro `Enable` da estrutura de `CCmdUI` por meio do *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

`OnUpdateObjectVerbMenu` atualiza a interface do usuário do comando *objectname* , dependendo se um objeto válido existe ou não no documento. Se houver um objeto, o comando *objectname* no menu Editar será habilitado. Quando esse comando de menu é selecionado, o submenu verbo é exibido. O submenu verbo contém todos os comandos de verbo disponíveis para o objeto, como editar, propriedades e assim por diante. Substitua essa função para alterar o comportamento.

##  <a name="onupdatepastelinkmenu"></a>COleDocument::OnUpdatePasteLinkMenu

Chamado pelo Framework para determinar se um item OLE vinculado pode ser colado da área de transferência.

```
afx_msg void OnUpdatePasteLinkMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>parâmetros

*pCmdUI*<br/>
Um ponteiro para uma estrutura de `CCmdUI` que representa o menu que gerou o comando de atualização. O manipulador de atualização chama a função de membro `Enable` da estrutura de `CCmdUI` por meio do *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

O comando colar especial menu é habilitado ou desabilitado dependendo se o item pode ser colado no documento ou não.

##  <a name="onupdatepastemenu"></a>COleDocument::OnUpdatePasteMenu

Chamado pelo Framework para determinar se um item OLE incorporado pode ser colado da área de transferência.

```
afx_msg void OnUpdatePasteMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>parâmetros

*pCmdUI*<br/>
Um ponteiro para uma estrutura de `CCmdUI` que representa o menu que gerou o comando de atualização. O manipulador de atualização chama a função de membro `Enable` da estrutura de `CCmdUI` por meio do *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

O comando de menu colar e o botão são habilitados ou desabilitados, dependendo se o item pode ser colado no documento ou não.

##  <a name="removeitem"></a>COleDocument:: RemoveItem

Chame essa função para remover um item do documento.

```
virtual void RemoveItem(CDocItem* pItem);
```

### <a name="parameters"></a>parâmetros

*pItem*<br/>
Ponteiro para o item de documento a ser removido.

### <a name="remarks"></a>Comentários

Normalmente, você não precisa chamar essa função explicitamente; Ele é chamado pelos destruidores para `COleClientItem` e `COleServerItem`.

##  <a name="updatemodifiedflag"></a>COleDocument::UpdateModifiedFlag

Chame essa função para marcar o documento como modificado se algum dos itens OLE contidos tiver sido modificado.

```
virtual void UpdateModifiedFlag();
```

### <a name="remarks"></a>Comentários

Isso permite que a estrutura solicite ao usuário que salve o documento antes de fechá-lo, mesmo que os dados nativos no documento não tenham sido modificados.

## <a name="see-also"></a>Confira também

[CONTÊINER de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de MFCBIND do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
