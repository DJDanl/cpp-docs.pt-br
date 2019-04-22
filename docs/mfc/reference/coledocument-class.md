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
ms.openlocfilehash: d1922c2f2d804c2a93d30dc0708b2d3ae037414d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58768699"
---
# <a name="coledocument-class"></a>Classe COleDocument

A classe base para documentos OLE que dão suporte à edição visual.

## <a name="syntax"></a>Sintaxe

```
class COleDocument : public CDocument
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDocument::COleDocument](#coledocument)|Constrói um objeto `COleDocument`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDocument::AddItem](#additem)|Adiciona um item à lista de itens mantidos pelo documento.|
|[COleDocument::ApplyPrintDevice](#applyprintdevice)|Define o dispositivo de destino de impressão para todos os itens de cliente no documento.|
|[COleDocument::EnableCompoundFile](#enablecompoundfile)|Faz com que os documentos a serem armazenados usando o formato de arquivo de armazenamento estruturado OLE.|
|[COleDocument::GetInPlaceActiveItem](#getinplaceactiveitem)|Retorna o item OLE que está ativo no momento no local.|
|[COleDocument::GetNextClientItem](#getnextclientitem)|Obtém o próximo item do cliente para a iteração.|
|[COleDocument::GetNextItem](#getnextitem)|Obtém o próximo item de documento para a iteração.|
|[COleDocument::GetNextServerItem](#getnextserveritem)|Obtém o próximo item de servidor para a iteração.|
|[COleDocument::GetPrimarySelectedItem](#getprimaryselecteditem)|Retorna o item OLE selecionado primário no documento.|
|[COleDocument::GetStartPosition](#getstartposition)|Obtém a posição inicial para começar a iteração.|
|[COleDocument::HasBlankItems](#hasblankitems)|Verifica se há itens em branco no documento.|
|[COleDocument::OnShowViews](#onshowviews)|Chamado quando o documento se torna visível ou invisível.|
|[COleDocument::RemoveItem](#removeitem)|Remove um item da lista de itens mantidos pelo documento.|
|[COleDocument::UpdateModifiedFlag](#updatemodifiedflag)|Marca o documento como modificado se qualquer um dos itens contidos OLE tiverem sido modificados.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleDocument::OnEditChangeIcon](#oneditchangeicon)|Manipula os eventos no comando de menu Alterar ícone.|
|[COleDocument::OnEditConvert](#oneditconvert)|Lida com a conversão de um objeto incorporado ou vinculado de um tipo para outro.|
|[COleDocument::OnEditLinks](#oneditlinks)|Manipula os eventos no comando Links no menu Editar.|
|[COleDocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de email com o documento anexado.|
|[COleDocument::OnUpdateEditChangeIcon](#onupdateeditchangeicon)|Chamado pelo framework para o comando da interface do usuário para a opção de menu Editar/Alterar ícone Atualizar.|
|[COleDocument::OnUpdateEditLinksMenu](#onupdateeditlinksmenu)|Chamado pelo framework para atualizar a interface de comando para a opção de menu/Links de edição.|
|[COleDocument::OnUpdateObjectVerbMenu](#onupdateobjectverbmenu)|Chamado pelo framework para atualizar o comando da interface do usuário para a edição / *ObjectName* opção de menu e o submenu de verbo acessados de edição / *ObjectName*.|
|[COleDocument::OnUpdatePasteLinkMenu](#onupdatepastelinkmenu)|Chamado pelo framework para atualizar a interface de comando para a opção de menu de colar especial.|
|[COleDocument::OnUpdatePasteMenu](#onupdatepastemenu)|Chamado pelo framework para atualizar a interface de comando para a opção de menu de colar.|

## <a name="remarks"></a>Comentários

`COleDocument` é derivado de `CDocument`, que permite que os aplicativos OLE usam a arquitetura de documento/exibição fornecida pela biblioteca de classes Microsoft Foundation.

`COleDocument` trata de um documento como uma coleção de [CDocItem](../../mfc/reference/cdocitem-class.md) objetos para lidar com itens OLE. Aplicativos de contêiner e o servidor exigir tal arquitetura porque seus documentos devem ser capazes de conter itens OLE. O [COleServerItem](../../mfc/reference/coleserveritem-class.md) e [COleClientItem](../../mfc/reference/coleclientitem-class.md) classes derivadas de `CDocItem`, gerenciar as interações entre os aplicativos e itens OLE.

Se você estiver escrevendo um aplicativo de contêiner simples, derive sua classe de documento da `COleDocument`. Se você estiver escrevendo um aplicativo de contêiner que dá suporte à vinculação aos itens inseridos contidos por seus documentos, derive sua classe de documento da [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md). Se você estiver escrevendo um servidor de aplicativo ou uma combinação de contêiner/servidor, derive sua classe de documento da [COleServerDoc](../../mfc/reference/coleserverdoc-class.md). `COleLinkingDoc` e `COleServerDoc` derivados `COleDocument`, portanto, essas classes herdam todos os serviços disponíveis no `COleDocument` e `CDocument`.

Para usar `COleDocument`, derive uma classe de-lo e adicionar funcionalidade para gerenciar o aplicativo não são OLE dados, bem como os itens inseridos ou vinculados. Se você definir `CDocItem`-derivadas de classes para armazenar os dados do aplicativo nativo, você pode usar a implementação do padrão definida pelo `COleDocument` para armazenar dados não são OLE e o OLE. Você também pode criar suas próprias estruturas de dados para armazenar dados não são OLE separadamente de itens OLE. Para obter mais informações, consulte o artigo [contêineres: Composta arquivos](../../mfc/containers-compound-files.md)...

`CDocument` oferece suporte ao envio seu documento por email se houver suporte mail (MAPI). `COleDocument` atualizou [OnFileSendMail](#onfilesendmail) para manipular documentos compostos corretamente. Para obter mais informações, consulte os artigos [MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md)...

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocument](../../mfc/reference/cdocument-class.md)

`COleDocument`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="additem"></a>  COleDocument::AddItem

Chame essa função para adicionar um item ao documento.

```
virtual void AddItem(CDocItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Ponteiro para o item do documento que está sendo adicionado.

### <a name="remarks"></a>Comentários

Você não precisa chamar essa função explicitamente quando ele é chamado pela `COleClientItem` ou `COleServerItem` construtor que aceita um ponteiro para um documento.

##  <a name="applyprintdevice"></a>  COleDocument::ApplyPrintDevice

Chame essa função para alterar o dispositivo de destino de impressão para todos inseridos [COleClientItem](../../mfc/reference/coleclientitem-class.md) itens no documento de contêiner do seu aplicativo.

```
BOOL ApplyPrintDevice(const DVTARGETDEVICE* ptd);
BOOL ApplyPrintDevice(const PRINTDLG* ppd);
```

### <a name="parameters"></a>Parâmetros

*ptd*<br/>
Ponteiro para um `DVTARGETDEVICE` estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.

*ppd*<br/>
Ponteiro para um `PRINTDLG` estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função atualiza o dispositivo de destino de impressão para todos os itens, mas não atualiza o cache de apresentação para esses itens. Para atualizar o cache de apresentação para um item, chame [COleClientItem::UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink).

Os argumentos para essa função contêm informações que OLE usa para identificar o dispositivo de destino. O [PRINTDLG](/windows/desktop/api/commdlg/ns-commdlg-tagpda) estrutura contém informações que o Windows usa para inicializar a caixa de diálogo de impressão comum. Depois que o usuário fecha a caixa de diálogo, o Windows retorna informações sobre as seleções do usuário nessa estrutura. O `m_pd` membro de uma [CPrintDialog](../../mfc/reference/cprintdialog-class.md) objeto é um `PRINTDLG` estrutura.

Para obter mais informações, consulte o [PRINTDLG](/windows/desktop/api/commdlg/ns-commdlg-tagpda) estrutura no SDK do Windows.

Para obter mais informações, consulte o [DVTARGETDEVICE](/windows/desktop/api/objidl/ns-objidl-tagdvtargetdevice) estrutura no SDK do Windows.

##  <a name="coledocument"></a>  COleDocument::COleDocument

Constrói um objeto `COleDocument`.

```
COleDocument();
```

##  <a name="enablecompoundfile"></a>  COleDocument::EnableCompoundFile

Chame essa função se você quiser armazenar o documento usando o formato de arquivo composto.

```
void EnableCompoundFile(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Especifica se o suporte de arquivo composto é habilitado ou desabilitado.

### <a name="remarks"></a>Comentários

Isso também é chamado de armazenamento estruturado. Normalmente você chama essa função do construtor de seu `COleDocument`-classe derivada. Para obter mais informações sobre documentos compostos, consulte o artigo [contêineres: Composta arquivos](../../mfc/containers-compound-files.md)...

Se você não chamar essa função membro, os documentos serão armazenados em um formato de arquivo ("simples") não estruturada.

Depois que o suporte de arquivo composto está habilitado ou desabilitado para um documento, a configuração não deve ser alterada durante o tempo de vida do documento.

##  <a name="getinplaceactiveitem"></a>  COleDocument::GetInPlaceActiveItem

Chamada para essa função para obter a OLE do item que está ativada no momento em vigor na janela do quadro que contém o modo de exibição identificado pelo *Apropriei*.

```
virtual COleClientItem* GetInPlaceActiveItem(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Ponteiro para a janela que exibe o documento contêiner.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o único, no local OLE item ativo; NULL se não houver nenhum item OLE no momento no estado "ativo no local".

##  <a name="getnextclientitem"></a>  COleDocument::GetNextClientItem

Chame essa função repetidamente para acessar cada um dos itens de cliente no documento.

```
COleClientItem* GetNextClientItem(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
Conjunto de valores de uma referência para uma posição por uma chamada anterior a `GetNextClientItem`; o valor inicial é retornado pelo `GetStartPosition` função de membro.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o próximo cliente do item no documento, ou NULL se não houver nenhum outro item do cliente.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor de *pos* está definido para o próximo item no documento, que pode ou não ser um item do cliente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#1](../../mfc/codesnippet/cpp/coledocument-class_1.cpp)]

##  <a name="getnextitem"></a>  COleDocument::GetNextItem

Chame essa função repetidamente para acessar cada um dos itens no documento.

```
virtual CDocItem* GetNextItem(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
Conjunto de valores de uma referência para uma posição por uma chamada anterior a `GetNextItem`; o valor inicial é retornado pelo `GetStartPosition` função de membro.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o item do documento na posição especificada.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor de *pos* é definido como o valor da posição do próximo item no documento. Se o elemento recuperado é o último elemento no documento, o novo valor de *pos* é NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#2](../../mfc/codesnippet/cpp/coledocument-class_2.cpp)]

##  <a name="getnextserveritem"></a>  COleDocument::GetNextServerItem

Chame essa função repetidamente para acessar cada um dos itens de servidor no seu documento.

```
COleServerItem* GetNextServerItem(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
Conjunto de valores de uma referência para uma posição por uma chamada anterior a `GetNextServerItem`; o valor inicial é retornado pelo `GetStartPosition` função de membro.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o próximo servidor do item no documento, ou NULL se não houver nenhum outro item de servidor.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor de *pos* está definido para o próximo item no documento, que pode ou não ser um item de servidor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleServer#2](../../mfc/codesnippet/cpp/coledocument-class_3.cpp)]

##  <a name="getprimaryselecteditem"></a>  COleDocument::GetPrimarySelectedItem

Chamado pelo framework para recuperar o item OLE selecionado no momento no modo de exibição especificado.

```
virtual COleClientItem* GetPrimarySelectedItem(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pView*<br/>
Ponteiro para o objeto de modo de exibição ativo exibindo o documento.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o item OLE selecionado, único; NULL se nenhum item OLE forem selecionadas ou se mais de um é selecionado.

### <a name="remarks"></a>Comentários

A implementação padrão de pesquisa a lista de independente OLE itens para um único item selecionado e retorna um ponteiro para ele. Se não houver nenhum item selecionado, ou se não houver mais de um item selecionado, a função retornará NULL. Você deve substituir o `CView::IsSelected` a função de membro em sua classe de exibição para essa função funcione. Substitua essa função se você tiver seu próprio método para armazenar os itens contidos OLE.

##  <a name="getstartposition"></a>  COleDocument::GetStartPosition

Chame essa função para obter a posição do primeiro item no documento.

```
virtual POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor da posição que pode ser usado para iniciar a iteração por meio de itens do documento; NULL se o documento não tiver nenhum item.

### <a name="remarks"></a>Comentários

Passar o valor retornado a `GetNextItem`, `GetNextClientItem`, ou `GetNextServerItem`.

##  <a name="hasblankitems"></a>  COleDocument::HasBlankItems

Chame essa função para determinar se o documento contém todos os itens em branco.

```
BOOL HasBlankItems() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o documento contém todos os itens em branco; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item em branco é aquele cujo retângulo está vazio.

##  <a name="oneditchangeicon"></a>  COleDocument::OnEditChangeIcon

Exibe a caixa de diálogo Alterar ícone do OLE e altera o ícone que representa o item OLE selecionado no momento para o ícone que o usuário seleciona na caixa de diálogo.

```
afx_msg void OnEditChangeIcon();
```

### <a name="remarks"></a>Comentários

`OnEditChangeIcon` cria e inicia um `COleChangeIconDialog` caixa de diálogo Alterar ícone.

##  <a name="oneditconvert"></a>  COleDocument::OnEditConvert

Exibe a caixa de diálogo converter OLE e converte ou ativa o item OLE selecionado no momento de acordo com a seleções do usuário na caixa de diálogo.

```
afx_msg void OnEditConvert();
```

### <a name="remarks"></a>Comentários

`OnEditConvert` cria e inicia um `COleConvertDialog` caixa de diálogo Converter.

Um exemplo de conversão está convertendo um documento do Word em um documento do WordPad.

##  <a name="oneditlinks"></a>  COleDocument::OnEditLinks

Exibe a caixa de diálogo OLE/Links de edição.

```
afx_msg void OnEditLinks();
```

### <a name="remarks"></a>Comentários

`OnEditLinks` cria e inicia um `COleLinksDialog` caixa de diálogo de Links que permite ao usuário alterar os objetos vinculados.

##  <a name="onfilesendmail"></a>  COleDocument::OnFileSendMail

Envia uma mensagem por meio do host de correio residentes (se houver) com o documento como um anexo.

```
afx_msg void OnFileSendMail();
```

### <a name="remarks"></a>Comentários

`OnFileSendMail` chamadas `OnSaveDocument` para serializar (os documentos sem título e modificados em um arquivo temporário, que é enviada por meio de emails Salvar). Se o documento não tiver sido modificado, um arquivo temporário não é necessária; original é enviada. `OnFileSendMail` carrega MAPI32. DLL se ele ainda não tenha sido carregado.

Ao contrário da implementação de `OnFileSendMail` para `CDocument`, essa função manipula arquivos compostos corretamente.

Para obter mais informações, consulte o [tópicos MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md) artigos...

##  <a name="onshowviews"></a>  COleDocument::OnShowViews

O framework chama essa função após a visibilidade do documento, as alterações de estado.

```
virtual void OnShowViews(BOOL bVisible);
```

### <a name="parameters"></a>Parâmetros

*bVisible*<br/>
Indica se o documento tornou-se visível ou invisível.

### <a name="remarks"></a>Comentários

A versão padrão dessa função não faz nada. Substituí-lo se seu aplicativo deve executar qualquer processamento especial quando a visibilidade do documento é alterado.

##  <a name="onupdateeditchangeicon"></a>  COleDocument::OnUpdateEditChangeIcon

Chamado pelo framework para atualizar o comando Alterar ícone no menu Editar.

```
afx_msg void OnUpdateEditChangeIcon(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização a `Enable` função de membro do `CCmdUI` estrutura por meio *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

`OnUpdateEditChangeIcon` Atualiza a interface do usuário do comando, dependendo de se existe ou não um ícone válido no documento. Substitua essa função para alterar o comportamento.

##  <a name="onupdateeditlinksmenu"></a>  COleDocument::OnUpdateEditLinksMenu

Chamado pelo framework para atualizar o comando de Links no menu Editar.

```
afx_msg void OnUpdateEditLinksMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização a `Enable` função de membro do `CCmdUI` estrutura por meio *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

Começando com o primeiro item OLE no documento, `OnUpdateEditLinksMenu` acessa cada item, testa se o item é um link e, se ele é um link, permite que o comando de Links. Substitua essa função para alterar o comportamento.

##  <a name="onupdateobjectverbmenu"></a>  COleDocument::OnUpdateObjectVerbMenu

Chamado pelo framework para atualizar o *ObjectName* comando no menu de edição e o submenu do verbo acessado a partir de *ObjectName* comando, onde *ObjectName* é o nome do o objeto OLE inseridos no documento.

```
afx_msg void OnUpdateObjectVerbMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização a `Enable` função de membro do `CCmdUI` estrutura por meio *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

`OnUpdateObjectVerbMenu` atualizações do *ObjectName* interface do usuário do comando, dependendo de se existe ou não um objeto válido no documento. Se um objeto existe, o *ObjectName* comando no menu Editar está habilitado. Quando esse comando de menu é selecionado, o submenu do verbo é exibido. O submenu do verbo contém todos os comandos de verbo disponíveis para o objeto, como editar, propriedades e assim por diante. Substitua essa função para alterar o comportamento.

##  <a name="onupdatepastelinkmenu"></a>  COleDocument::OnUpdatePasteLinkMenu

Chamado pelo framework para determinar se um item OLE vinculado pode ser colado da área de transferência.

```
afx_msg void OnUpdatePasteLinkMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização a `Enable` função de membro do `CCmdUI` estrutura por meio *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

O comando Colar especial do menu está habilitado ou desabilitado dependendo se o item pode ser colado no documento ou não.

##  <a name="onupdatepastemenu"></a>  COleDocument::OnUpdatePasteMenu

Chamado pelo framework para determinar se um item OLE inserido pode ser colado da área de transferência.

```
afx_msg void OnUpdatePasteMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização a `Enable` função de membro do `CCmdUI` estrutura por meio *pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

O comando de menu de colar e o botão estiverem habilitados ou desabilitados dependendo se o item pode ser colado no documento ou não.

##  <a name="removeitem"></a>  COleDocument::RemoveItem

Chame essa função para remover um item do documento.

```
virtual void RemoveItem(CDocItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Ponteiro para o item do documento a ser removido.

### <a name="remarks"></a>Comentários

Você normalmente não precisa chamar essa função explicitamente. ele é chamado pelos destruidores de `COleClientItem` e `COleServerItem`.

##  <a name="updatemodifiedflag"></a>  COleDocument::UpdateModifiedFlag

Chame essa função para marcar o documento como modificado se qualquer um dos itens contidos OLE foram modificadas.

```
virtual void UpdateModifiedFlag();
```

### <a name="remarks"></a>Comentários

Isso permite que o framework solicitar ao usuário para salvar o documento antes de fechá-lo, mesmo se os dados nativos no documento não foi modificados.

## <a name="see-also"></a>Consulte também

[CONTÊINER de amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC MFCBIND](../../overview/visual-cpp-samples.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
