---
title: Classe CPropertyPage
ms.date: 11/04/2016
f1_keywords:
- CPropertyPage
- AFXDLGS/CPropertyPage
- AFXDLGS/CPropertyPage::CPropertyPage
- AFXDLGS/CPropertyPage::CancelToClose
- AFXDLGS/CPropertyPage::Construct
- AFXDLGS/CPropertyPage::GetPSP
- AFXDLGS/CPropertyPage::OnApply
- AFXDLGS/CPropertyPage::OnCancel
- AFXDLGS/CPropertyPage::OnKillActive
- AFXDLGS/CPropertyPage::OnOK
- AFXDLGS/CPropertyPage::OnQueryCancel
- AFXDLGS/CPropertyPage::OnReset
- AFXDLGS/CPropertyPage::OnSetActive
- AFXDLGS/CPropertyPage::OnWizardBack
- AFXDLGS/CPropertyPage::OnWizardFinish
- AFXDLGS/CPropertyPage::OnWizardNext
- AFXDLGS/CPropertyPage::QuerySiblings
- AFXDLGS/CPropertyPage::SetModified
- AFXDLGS/CPropertyPage::m_psp
helpviewer_keywords:
- CPropertyPage [MFC], CPropertyPage
- CPropertyPage [MFC], CancelToClose
- CPropertyPage [MFC], Construct
- CPropertyPage [MFC], GetPSP
- CPropertyPage [MFC], OnApply
- CPropertyPage [MFC], OnCancel
- CPropertyPage [MFC], OnKillActive
- CPropertyPage [MFC], OnOK
- CPropertyPage [MFC], OnQueryCancel
- CPropertyPage [MFC], OnReset
- CPropertyPage [MFC], OnSetActive
- CPropertyPage [MFC], OnWizardBack
- CPropertyPage [MFC], OnWizardFinish
- CPropertyPage [MFC], OnWizardNext
- CPropertyPage [MFC], QuerySiblings
- CPropertyPage [MFC], SetModified
- CPropertyPage [MFC], m_psp
ms.assetid: d9000a21-aa81-4530-85d9-f43432afb4dc
ms.openlocfilehash: f46566eb562f1515e98aedf938ca68b225ee1b67
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751109"
---
# <a name="cpropertypage-class"></a>Classe CPropertyPage

Representa páginas individuais de uma folha de propriedades, também conhecida como caixa de diálogo de guia.

## <a name="syntax"></a>Sintaxe

```
class CPropertyPage : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertyPage::CPropertyPage](#cpropertypage)|Constrói um objeto `CPropertyPage`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertyPage::CancelToClose](#canceltoclose)|Altera o botão OK para ler Fechar e desativa o botão Cancelar, após uma alteração irrecuperável na página de uma folha de propriedade modal.|
|[CPropertyPage::Construir](#construct)|Constrói um objeto `CPropertyPage`. Use `Construct` se quiser especificar seus parâmetros no tempo de execução ou se estiver usando arrays.|
|[CPropertyPage::GetPSP](#getpsp)|Recupera a estrutura do Windows [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) associada ao `CPropertyPage` objeto.|
|[CPropertyPage::OnApply](#onapply)|Chamado pelo framework quando o botão Aplicar agora é clicado.|
|[CPropertyPage::OnCancel](#oncancel)|Chamado pelo framework quando o botão Cancelar é clicado.|
|[CPropertyPage::OnKillActive](#onkillactive)|Chamada pelo framework quando a página atual não é mais a página ativa. Realize a validação de dados aqui.|
|[CPropertyPage::OnOK](#onok)|Chamado pelo framework quando o botão OK, Apply Now ou Close é clicado.|
|[CPropertyPage::OnQueryCancel](#onquerycancel)|Chamado pelo framework quando o botão Cancelar é clicado e antes que o cancelamento tenha ocorrido.|
|[CPropertyPage::OnReset](#onreset)|Chamado pelo framework quando o botão Cancelar é clicado.|
|[CPropertyPage::OnSetActive](#onsetactive)|Chamado pela estrutura quando a página é feita a página ativa.|
|[CPropertyPage::OnWizardBack](#onwizardback)|Chamado pela estrutura quando o botão Voltar é clicado ao usar uma folha de propriedade do tipo assistente.|
|[CPropertyPage::OnWizardFinish](#onwizardfinish)|Chamado pela estrutura quando o botão Concluir é clicado ao usar uma folha de propriedade do tipo assistente.|
|[cPropertyPage::OnWizardNext](#onwizardnext)|Chamado pela estrutura quando o botão Next é clicado ao usar uma folha de propriedade do tipo assistente.|
|[CPropertyPage::QuerySiblings](#querysiblings)|Encaminha a mensagem para cada página da folha de propriedades.|
|[CPropertyPage::SetModified](#setmodified)|Ligue para ativar ou desativar o botão Aplicar agora.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertyPage::m_psp](#m_psp)|A estrutura [do Windows PROPSHEETPAGE.](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) Fornece acesso aos parâmetros básicos da página de propriedade.|

## <a name="remarks"></a>Comentários

Como acontece com as caixas de `CPropertyPage` diálogo padrão, você obtém uma classe de cada página em sua folha de propriedade. Para `CPropertyPage`usar objetos derivados, primeiro crie um objeto [CPropertySheet](../../mfc/reference/cpropertysheet-class.md) e crie um objeto para cada página que vá para a folha de propriedades. Ligue para [cpropertysheet::AddPage](../../mfc/reference/cpropertysheet-class.md#addpage) para cada página na planilha e, em seguida, exiba a folha de propriedades chamando [CPropertySheet::DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) para uma folha de propriedade modal ou [CPropertySheet::Criar](../../mfc/reference/cpropertysheet-class.md#create) para uma folha de propriedade modeless.

Você pode criar um tipo de caixa de diálogo de guia chamada assistente, que consiste em uma folha de propriedade com uma seqüência de páginas de propriedade que guiam o usuário através das etapas de uma operação, como configurar um dispositivo ou criar um boletim informativo. Em uma caixa de diálogo tipo assistente, as páginas de propriedade não têm guias e apenas uma página de propriedade é visível por vez. Além disso, em vez de ter botões OK e Apply Now, uma caixa de diálogo tipo assistente tem um botão Voltar, um botão Next ou Finish e um botão Cancelar.

Para obter mais informações sobre como estabelecer uma planilha de propriedades como assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode). Para obter mais `CPropertyPage` informações sobre o uso de objetos, consulte o artigo [Folhas de Propriedade e Páginas de Propriedade](../../mfc/property-sheets-and-property-pages-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

`CPropertyPage`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cpropertypagecanceltoclose"></a><a name="canceltoclose"></a>CPropertyPage::CancelToClose

Chame essa função depois que uma alteração irrecuperável foi feita para os dados em uma página de uma folha de propriedade modal.

```cpp
void CancelToClose();
```

### <a name="remarks"></a>Comentários

Esta função mudará o botão OK para Fechar e desativará o botão Cancelar. Essa alteração alerta o usuário de que uma alteração é permanente e as modificações não podem ser canceladas.

A `CancelToClose` função de membro não faz nada em uma folha de propriedade modeless, porque uma folha de propriedade modeless não tem um botão Cancelar por padrão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertyPage::QuerySiblings](#querysiblings).

## <a name="cpropertypageconstruct"></a><a name="construct"></a>CPropertyPage::Construir

Chame esta função de `CPropertyPage` membro para construir um objeto.

```cpp
void Construct(
    UINT nIDTemplate,
    UINT nIDCaption = 0);

void Construct(
    LPCTSTR lpszTemplateName,
    UINT nIDCaption = 0);

void Construct(
    UINT nIDTemplate,
    UINT nIDCaption,
    UINT nIDHeaderTitle,
    UINT nIDHeaderSubTitle = 0);

void Construct(
    LPCTSTR lpszTemplateName,
    UINT nIDCaption,
    UINT nIDHeaderTitle,
    UINT nIDHeaderSubTitle = 0);
```

### <a name="parameters"></a>Parâmetros

*Nidtemplate*<br/>
ID do modelo usado para esta página.

*nIDCaption*<br/>
ID do nome a ser colocado na guia para esta página. Se 0, o nome será retirado do modelo de diálogo para esta página.

*lpszTemplateName*<br/>
Contém uma seqüência de seqüência de terminadas nula que é o nome de um recurso de modelo.

*nIDHeaderTitle*<br/>
ID do nome a ser colocado no local de título do cabeçalho da página de propriedade. Por padrão, 0.

*nIDHeaderSubTitle*<br/>
ID do nome a ser colocado no local da legenda do cabeçalho da página de propriedade. Por padrão, 0.

### <a name="remarks"></a>Comentários

O objeto é exibido depois que todas as seguintes condições são atendidas:

- A página foi adicionada a uma folha de propriedades usando [CPropertySheet::AddPage](../../mfc/reference/cpropertysheet-class.md#addpage).

- A função [DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) ou [Create](../../mfc/reference/cpropertysheet-class.md#create) da folha de propriedades foi chamada.

- O usuário selecionou (guiado para) esta página.

Ligue `Construct` se um dos outros construtores de classe não foi chamado. A `Construct` função membro é flexível porque você pode deixar a declaração de parâmetro em branco e, em seguida, especificar vários parâmetros e construção a qualquer momento do seu código.

Você deve `Construct` usar quando trabalhar com arrays, e deve chamar `Construct` cada membro da matriz para que os membros de dados sejam atribuídos valores adequados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#112](../../mfc/codesnippet/cpp/cpropertypage-class_1.cpp)]

## <a name="cpropertypagecpropertypage"></a><a name="cpropertypage"></a>CPropertyPage::CPropertyPage

Constrói um objeto `CPropertyPage`.

```
CPropertyPage();

explicit CPropertyPage(
    UINT nIDTemplate,
    UINT nIDCaption = 0,
    DWORD dwSize = sizeof(PROPSHEETPAGE));

explicit CPropertyPage(
    LPCTSTR lpszTemplateName,
    UINT nIDCaption = 0,
    DWORD dwSize = sizeof(PROPSHEETPAGE));

CPropertyPage(
    UINT nIDTemplate,
    UINT nIDCaption,
    UINT nIDHeaderTitle,
    UINT nIDHeaderSubTitle = 0,
    DWORD dwSize = sizeof(PROPSHEETPAGE));

CPropertyPage(
    LPCTSTR lpszTemplateName,
    UINT nIDCaption,
    UINT nIDHeaderTitle,
    UINT nIDHeaderSubTitle = 0,
    DWORD dwSize = sizeof(PROPSHEETPAGE));
```

### <a name="parameters"></a>Parâmetros

*Nidtemplate*<br/>
ID do modelo usado para esta página.

*nIDCaption*<br/>
ID do nome a ser colocado na guia para esta página. Se 0, o nome será retirado do modelo de diálogo para esta página.

*Dwsize*<br/>
*lpszTemplateName* Aponta para uma seqüência contendo o nome do modelo para esta página. Não pode ser NULL.

*nIDHeaderTitle*<br/>
ID do nome a ser colocado no local de título do cabeçalho da página de propriedade.

*nIDHeaderSubTitle*<br/>
ID do nome a ser colocado no local da legenda do cabeçalho da página de propriedade.

### <a name="remarks"></a>Comentários

O objeto é exibido depois que todas as seguintes condições são atendidas:

- A página foi adicionada a uma folha de propriedades usando [CPropertySheet::AddPage](../../mfc/reference/cpropertysheet-class.md#addpage).

- A função [DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) ou [Create](../../mfc/reference/cpropertysheet-class.md#create) da folha de propriedades foi chamada.

- O usuário selecionou (guiado para) esta página.

Se você tiver vários parâmetros (por exemplo, se estiver usando uma `CPropertyPage`matriz), use [CPropertySheet::Construa](../../mfc/reference/cpropertysheet-class.md#construct) em vez de .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#113](../../mfc/codesnippet/cpp/cpropertypage-class_2.cpp)]

## <a name="cpropertypagegetpsp"></a><a name="getpsp"></a>CPropertyPage::GetPSP

Recupera a estrutura do Windows [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) associada ao `CPropertyPage` objeto.

```
const PROPSHEETPAGE& GetPSP() const;

PROPSHEETPAGE& GetPSP();
```

### <a name="return-value"></a>Valor retornado

Uma referência `PROPSHEETPAGE` à estrutura.

## <a name="cpropertypagem_psp"></a><a name="m_psp"></a>CPropertyPage::m_psp

`m_psp`é uma estrutura cujos membros armazenam as características do [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2).

```
PROPSHEETPAGE m_psp;
```

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência de uma página de propriedade depois de construída.

Para obter mais informações sobre esta estrutura, `PROPSHEETPAGE` incluindo uma listagem de seus membros, consulte no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#128](../../mfc/codesnippet/cpp/cpropertypage-class_3.cpp)]

## <a name="cpropertypageonapply"></a><a name="onapply"></a>CPropertyPage::OnApply

Esta função de membro é chamada pela estrutura quando o usuário escolhe o botão OK ou O Botão Aplicar Agora.

```
virtual BOOL OnApply();
```

### <a name="return-value"></a>Valor retornado

Não zero se as alterações forem aceitas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando o framework chama essa função, as alterações feitas em todas as páginas `OnApply` de propriedade na folha de propriedades são aceitas, a folha de propriedade mantém o foco e retorna TRUE (o valor 1). Antes `OnApply` de ser chamado pela estrutura, você deve ter chamado [SetModified](#setmodified) e definir seu parâmetro como TRUE. Isso ativará o botão Aplicar agora assim que o usuário fizer uma alteração na página da propriedade.

Substituir esta função de membro para especificar que ação seu programa toma quando o usuário clica no botão Aplicar agora. Ao ser sobreposta, a função deve retornar TRUE para aceitar alterações e FALSE para evitar que as alterações surtam efeito.

A implementação `OnApply` `OnOK`padrão de chamadas .

Para obter mais informações sobre mensagens de notificação enviadas quando o usuário pressionar o botão Aplicar agora ou OK em uma folha de propriedade, consulte [PSN_APPLY](/windows/win32/Controls/psn-apply) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertyPage::OnOK](#onok).

## <a name="cpropertypageoncancel"></a><a name="oncancel"></a>CPropertyPage::OnCancel

Esta função de membro é chamada pela estrutura quando o botão Cancelar é selecionado.

```
virtual void OnCancel();
```

### <a name="remarks"></a>Comentários

Anular essa função de membro para executar ações de botão Cancelar. O padrão nega quaisquer alterações que tenham sido feitas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#114](../../mfc/codesnippet/cpp/cpropertypage-class_4.cpp)]

## <a name="cpropertypageonkillactive"></a><a name="onkillactive"></a>CPropertyPage::OnKillActive

Essa função de membro é chamada pelo framework quando a página não é mais a página ativa.

```
virtual BOOL OnKillActive();
```

### <a name="return-value"></a>Valor retornado

Não zero se os dados foram atualizados com sucesso, caso contrário 0.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para executar tarefas especiais de validação de dados.

A implementação padrão desta função membro copia as configurações dos controles na página de propriedade para as variáveis de membro da página de propriedade. Se os dados não foram atualizados com sucesso devido a um erro de validação de dados de diálogo (DDV), a página manterá o foco.

Depois que essa função de membro retornar com sucesso, a estrutura chamará a função [OnOK](#onok) da página.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#115](../../mfc/codesnippet/cpp/cpropertypage-class_5.cpp)]

## <a name="cpropertypageonok"></a><a name="onok"></a>CPropertyPage::OnOK

Essa função de membro é chamada pela framework quando o usuário escolhe o botão OK ou O Aplicar Agora, imediatamente após a framework chamar [OnKillActive](#onkillactive).

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o botão OK ou O Aplicativo Agora, o framework recebe a notificação [PSN_APPLY](/windows/win32/Controls/psn-apply) da página de propriedade. A chamada `OnOK` para não será feita se você chamar [CPropertySheet::PressButton](../../mfc/reference/cpropertysheet-class.md#pressbutton) porque a página de propriedade não envia a notificação nesse caso.

Substituir essa função de membro para implementar um comportamento adicional específico da página ativa atualmente quando o usuário descarta toda a planilha de propriedades.

A implementação padrão desta função de membro marca a página como `OnKillActive` "limpa" para refletir que os dados foram atualizados na função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#116](../../mfc/codesnippet/cpp/cpropertypage-class_6.cpp)]

## <a name="cpropertypageonquerycancel"></a><a name="onquerycancel"></a>CPropertyPage::OnQueryCancel

Essa função de membro é chamada pela estrutura quando o usuário clica no botão Cancelar e antes que a ação de cancelamento tenha ocorrido.

```
virtual BOOL OnQueryCancel();
```

### <a name="return-value"></a>Valor retornado

Retorna FALSO para evitar a operação de cancelamento ou TRUE para permitir.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar uma ação que o programa toma quando o usuário clica no botão Cancelar.

A implementação `OnQueryCancel` padrão de devoluções TRUE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#117](../../mfc/codesnippet/cpp/cpropertypage-class_7.cpp)]

## <a name="cpropertypageonreset"></a><a name="onreset"></a>CPropertyPage::OnReset

Essa função de membro é chamada pela estrutura quando o usuário escolhe o botão Cancelar.

```
virtual void OnReset();
```

### <a name="remarks"></a>Comentários

Quando o framework chama essa função, as alterações em todas as páginas de propriedade que foram feitas pelo usuário anteriormente escolhendo o botão Aplicar agora são descartadas e a folha de propriedades mantém o foco.

Substituir esta função de membro para especificar que ação o programa toma quando o usuário clica no botão Cancelar.

A implementação `OnReset` padrão de não faz nada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertyPage::OnCancel](#oncancel).

## <a name="cpropertypageonsetactive"></a><a name="onsetactive"></a>CPropertyPage::OnSetActive

Essa função de membro é chamada pela framework quando a página é escolhida pelo usuário e se torna a página ativa.

```
virtual BOOL OnSetActive();
```

### <a name="return-value"></a>Valor retornado

Não zero se a página foi definida com sucesso ativa; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para executar tarefas quando uma página é ativada. Sua substituição desta função de membro normalmente chamaria a versão padrão após a atualização dos membros dos dados, para permitir que ele atualize os controles da página com os novos dados.

A implementação padrão cria a janela para a página, se não for criada anteriormente, e a torna a página ativa.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::SetFinishText](../../mfc/reference/cpropertysheet-class.md#setfinishtext).

## <a name="cpropertypageonwizardback"></a><a name="onwizardback"></a>CPropertyPage::OnWizardBack

Essa função de membro é chamada pela estrutura quando o usuário clica no botão Voltar em um assistente.

```
virtual LRESULT OnWizardBack();
```

### <a name="return-value"></a>Valor retornado

0 para avançar automaticamente para a próxima página; -1 para evitar que a página mude. Para saltar para uma página diferente da próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar alguma ação que o usuário deve tomar quando o botão Voltar é pressionado.

Para obter mais informações sobre como fazer uma folha de propriedades do tipo assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#118](../../mfc/codesnippet/cpp/cpropertypage-class_8.cpp)]

## <a name="cpropertypageonwizardfinish"></a><a name="onwizardfinish"></a>CPropertyPage::OnWizardFinish

Esta função de membro é chamada pela estrutura quando o usuário clica no botão Concluir em um assistente.

```
virtual BOOL OnWizardFinish();
```

### <a name="return-value"></a>Valor retornado

Não zero se a folha de propriedade for destruída quando o assistente terminar; caso contrário, zero.

### <a name="remarks"></a>Comentários

Quando um usuário clica no botão **Concluir** em um assistente, a estrutura chama essa função; quando `OnWizardFinish` retorna TRUE (um valor não zero), a folha de propriedade é capaz de ser destruída (mas não é realmente destruída). Chamada `DestroyWindow` para destruir a folha de propriedades. Não ligue `DestroyWindow` `OnWizardFinish`de; fazê-lo causará corrupção de pilha ou outros erros.

Você pode substituir esta função de membro para especificar alguma ação que o usuário deve tomar quando o botão Concluir é pressionado. Ao sobrepor esta função, retorne FALSE para evitar que a folha de propriedade seja destruída.

Para obter mais informações sobre mensagens de notificação enviadas quando o usuário pressionar o botão Concluir em uma folha de propriedade do assistente, consulte [PSN_WIZFINISH](/windows/win32/Controls/psn-wizfinish) no SDK do Windows.

Para obter mais informações sobre como fazer uma folha de propriedades do tipo assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#119](../../mfc/codesnippet/cpp/cpropertypage-class_9.cpp)]

[!code-cpp[NVC_MFCDocView#120](../../mfc/codesnippet/cpp/cpropertypage-class_10.cpp)]

[!code-cpp[NVC_MFCDocView#121](../../mfc/codesnippet/cpp/cpropertypage-class_11.cpp)]

[!code-cpp[NVC_MFCDocView#122](../../mfc/codesnippet/cpp/cpropertypage-class_12.cpp)]

## <a name="cpropertypageonwizardnext"></a><a name="onwizardnext"></a>cPropertyPage::OnWizardNext

Essa função de membro é chamada pela framework quando o usuário clica no botão Next em um assistente.

```
virtual LRESULT OnWizardNext();
```

### <a name="return-value"></a>Valor retornado

0 para avançar automaticamente para a próxima página; -1 para evitar que a página mude. Para saltar para uma página diferente da próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar alguma ação que o usuário deve tomar quando o botão Next é pressionado.

Para obter mais informações sobre como fazer uma folha de propriedades do tipo assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#123](../../mfc/codesnippet/cpp/cpropertypage-class_13.cpp)]

## <a name="cpropertypagequerysiblings"></a><a name="querysiblings"></a>CPropertyPage::QuerySiblings

Ligue para esta função de membro para encaminhar uma mensagem para cada página na folha de propriedades.

```
LRESULT QuerySiblings(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
Especifica informações adicionais dependentes de mensagens.

*lParam*<br/>
Especifica informações adicionais dependentes de mensagens

### <a name="return-value"></a>Valor retornado

O valor não zero de uma página na folha de propriedades, ou 0 se todas as páginas retornarem um valor de 0.

### <a name="remarks"></a>Comentários

Se uma página retornar um valor não zero, a folha de propriedade não enviará a mensagem para as páginas subseqüentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#124](../../mfc/codesnippet/cpp/cpropertypage-class_14.cpp)]

[!code-cpp[NVC_MFCDocView#125](../../mfc/codesnippet/cpp/cpropertypage-class_15.cpp)]

[!code-cpp[NVC_MFCDocView#126](../../mfc/codesnippet/cpp/cpropertypage-class_16.cpp)]

## <a name="cpropertypagesetmodified"></a><a name="setmodified"></a>CPropertyPage::SetModified

Chame esta função de membro para ativar ou desativar o botão Aplicar agora, com base em se as configurações na página de propriedade devem ser aplicadas ao objeto externo apropriado.

```cpp
void SetModified(BOOL bChanged = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bChanged*<br/>
VERDADEIRO indicar que as configurações da página de propriedade foram modificadas desde a última vez que foram aplicadas; FALSO para indicar que as configurações da página de propriedade foram aplicadas ou devem ser ignoradas.

### <a name="remarks"></a>Comentários

A estrutura mantém o controle de quais páginas são "sujas", ou seja, páginas de propriedade para as quais você chamou `SetModified( TRUE )`. O botão Aplicar agora estará sempre `SetModified( TRUE )` ativado se você chamar uma das páginas. O botão Aplicar agora será `SetModified( FALSE )` desativado quando você chamar uma das páginas, mas somente se nenhuma das outras páginas estiver "suja".

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#127](../../mfc/codesnippet/cpp/cpropertypage-class_17.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL1](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC CMNCTRL2](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC PROPDLG](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
