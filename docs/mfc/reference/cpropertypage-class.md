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
ms.openlocfilehash: 6a6223708c83f7a5b3e6532a2016660d558f8270
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865425"
---
# <a name="cpropertypage-class"></a>Classe CPropertyPage

Representa páginas individuais de uma folha de propriedades, também conhecido como caixa de diálogo de tabulação.

## <a name="syntax"></a>Sintaxe

```
class CPropertyPage : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CPropertyPage::CPropertyPage](#cpropertypage)|Constrói um objeto `CPropertyPage`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CPropertyPage::CancelToClose](#canceltoclose)|Altera o botão OK para ler fechar e desabilita o botão Cancelar, após uma alteração irrecuperável na página de uma folha de propriedades modal.|
|[CPropertyPage:: Construct](#construct)|Constrói um objeto `CPropertyPage`. Use `Construct` se você quiser especificar seus parâmetros em tempo de execução ou se estiver usando matrizes.|
|[CPropertyPage::GetPSP](#getpsp)|Recupera a estrutura [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) do Windows associada ao objeto `CPropertyPage`.|
|[CPropertyPage:: OnApply](#onapply)|Chamado pelo Framework quando o botão Aplicar agora é clicado.|
|[CPropertyPage:: OnCancel](#oncancel)|Chamado pelo Framework quando o botão de cancelamento é clicado.|
|[CPropertyPage::OnKillActive](#onkillactive)|Chamado pelo Framework quando a página atual não é mais a página ativa. Execute a validação de dados aqui.|
|[CPropertyPage::OnOK](#onok)|Chamado pelo Framework quando o botão OK, aplicar agora ou fechar é clicado.|
|[CPropertyPage:: OnQueryCancel](#onquerycancel)|Chamado pelo Framework quando o botão de cancelamento é clicado e antes do cancelamento.|
|[CPropertyPage:: OnReset](#onreset)|Chamado pelo Framework quando o botão de cancelamento é clicado.|
|[CPropertyPage::OnSetActive](#onsetactive)|Chamado pelo Framework quando a página se torna a página ativa.|
|[CPropertyPage::OnWizardBack](#onwizardback)|Chamado pelo Framework quando o botão voltar é clicado durante o uso de uma folha de propriedades do tipo assistente.|
|[CPropertyPage::OnWizardFinish](#onwizardfinish)|Chamado pelo Framework quando o botão Concluir é clicado durante o uso de uma folha de propriedades do tipo assistente.|
|[CPropertyPage::OnWizardNext](#onwizardnext)|Chamado pelo Framework quando o botão Avançar é clicado durante o uso de uma folha de propriedades do tipo assistente.|
|[CPropertyPage::QuerySiblings](#querysiblings)|Encaminha a mensagem para cada página da folha de propriedades.|
|[CPropertyPage:: SetModified](#setmodified)|Chame para ativar ou desativar o botão Aplicar agora.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CPropertyPage:: m_psp](#m_psp)|A estrutura [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) do Windows. Fornece acesso aos parâmetros básicos da página de propriedades.|

## <a name="remarks"></a>Comentários

Assim como ocorre com as caixas de diálogo padrão, você deriva uma classe de `CPropertyPage` para cada página em sua folha de propriedades. Para usar objetos derivados de `CPropertyPage`, primeiro crie um objeto [CPropertySheet](../../mfc/reference/cpropertysheet-class.md) e, em seguida, crie um objeto para cada página que vai na folha de propriedades. Chame [CPropertySheet:: AddPage](../../mfc/reference/cpropertysheet-class.md#addpage) para cada página na planilha e, em seguida, exiba a folha de propriedades chamando [CPropertySheet::D omodal](../../mfc/reference/cpropertysheet-class.md#domodal) para uma folha de propriedades modal ou [CPropertySheet:: Create](../../mfc/reference/cpropertysheet-class.md#create) para uma folha de propriedades sem janela restrita.

Você pode criar um tipo de caixa de diálogo de guia chamada assistente, que consiste em uma folha de propriedades com uma sequência de páginas de propriedades que orientam o usuário pelas etapas de uma operação, como a configuração de um dispositivo ou a criação de um boletim informativo. Em uma caixa de diálogo guia do tipo de assistente, as páginas de propriedades não têm guias e apenas uma página de propriedades é visível por vez. Além disso, em vez de ter botões OK e aplicar agora, uma caixa de diálogo guia do tipo de assistente tem um botão voltar, um botão Avançar ou concluir e um botão Cancelar.

Para obter mais informações sobre como estabelecer uma folha de propriedades como um assistente, consulte [CPropertySheet:: SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode). Para obter mais informações sobre como usar objetos `CPropertyPage`, consulte as folhas de propriedades do artigo [e as páginas de propriedades](../../mfc/property-sheets-and-property-pages-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

`CPropertyPage`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="canceltoclose"></a>CPropertyPage::CancelToClose

Chamar essa função depois que uma alteração irrecuperável tiver sido feita nos dados em uma página de uma folha de propriedades modal.

```
void CancelToClose();
```

### <a name="remarks"></a>Comentários

Essa função irá alterar o botão OK para fechar e desabilitar o botão Cancelar. Essa alteração alerta o usuário de que uma alteração é permanente e as modificações não podem ser canceladas.

A função membro `CancelToClose` não faz nada em uma folha de propriedades sem janela restrita, porque uma folha de propriedades sem janela restrita não tem um botão cancelar por padrão.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CPropertyPage:: QuerySiblings](#querysiblings).

##  <a name="construct"></a>CPropertyPage:: Construct

Chame essa função de membro para construir um objeto de `CPropertyPage`.

```
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

### <a name="parameters"></a>parâmetros

*nIDTemplate*<br/>
ID do modelo usado para esta página.

*nIDCaption*<br/>
ID do nome a ser colocado na guia desta página. Se for 0, o nome será obtido do modelo de caixa de diálogo para esta página.

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo.

*nIDHeaderTitle*<br/>
ID do nome a ser colocado no local do título do cabeçalho da página de propriedades. Por padrão, 0.

*nIDHeaderSubTitle*<br/>
ID do nome a ser colocado no local do subtítulo do cabeçalho da página de propriedades. Por padrão, 0.

### <a name="remarks"></a>Comentários

O objeto é exibido depois que todas as condições a seguir são atendidas:

- A página foi adicionada a uma folha de propriedades usando [CPropertySheet:: AddPage](../../mfc/reference/cpropertysheet-class.md#addpage).

- A função [DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) ou [Create](../../mfc/reference/cpropertysheet-class.md#create) da folha de propriedades foi chamada.

- O usuário selecionou (tabulado para) esta página.

Chame `Construct` se um dos outros construtores de classe não tiver sido chamado. A função membro `Construct` é flexível porque você pode deixar a instrução de parâmetro em branco e, em seguida, especificar vários parâmetros e a construção a qualquer momento em seu código.

Você deve usar `Construct` ao trabalhar com matrizes, e deve chamar `Construct` para cada membro da matriz para que os membros de dados recebam valores adequados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#112](../../mfc/codesnippet/cpp/cpropertypage-class_1.cpp)]

##  <a name="cpropertypage"></a>CPropertyPage::CPropertyPage

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

### <a name="parameters"></a>parâmetros

*nIDTemplate*<br/>
ID do modelo usado para esta página.

*nIDCaption*<br/>
ID do nome a ser colocado na guia desta página. Se for 0, o nome será obtido do modelo de caixa de diálogo para esta página.

*dwSize*<br/>
*lpszTemplateName* Aponta para uma cadeia de caracteres que contém o nome do modelo para esta página. Não pode ser NULL.

*nIDHeaderTitle*<br/>
ID do nome a ser colocado no local do título do cabeçalho da página de propriedades.

*nIDHeaderSubTitle*<br/>
ID do nome a ser colocado no local do subtítulo do cabeçalho da página de propriedades.

### <a name="remarks"></a>Comentários

O objeto é exibido depois que todas as condições a seguir são atendidas:

- A página foi adicionada a uma folha de propriedades usando [CPropertySheet:: AddPage](../../mfc/reference/cpropertysheet-class.md#addpage).

- A função [DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) ou [Create](../../mfc/reference/cpropertysheet-class.md#create) da folha de propriedades foi chamada.

- O usuário selecionou (tabulado para) esta página.

Se você tiver vários parâmetros (por exemplo, se estiver usando uma matriz), use [CPropertySheet:: Construct](../../mfc/reference/cpropertysheet-class.md#construct) em vez de `CPropertyPage`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#113](../../mfc/codesnippet/cpp/cpropertypage-class_2.cpp)]

##  <a name="getpsp"></a>CPropertyPage::GetPSP

Recupera a estrutura [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) do Windows associada ao objeto `CPropertyPage`.

```
const PROPSHEETPAGE& GetPSP() const;

PROPSHEETPAGE& GetPSP();
```

### <a name="return-value"></a>Valor retornado

Uma referência à estrutura de `PROPSHEETPAGE`.

##  <a name="m_psp"></a>CPropertyPage:: m_psp

`m_psp` é uma estrutura cujos membros armazenam as características de [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2).

```
PROPSHEETPAGE m_psp;
```

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência de uma página de propriedades após sua construção.

Para obter mais informações sobre essa estrutura, incluindo uma listagem de seus membros, consulte `PROPSHEETPAGE` no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#128](../../mfc/codesnippet/cpp/cpropertypage-class_3.cpp)]

##  <a name="onapply"></a>CPropertyPage:: OnApply

Essa função de membro é chamada pela estrutura quando o usuário escolhe o botão OK ou aplicar agora.

```
virtual BOOL OnApply();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se as alterações forem aceitas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando a estrutura chama essa função, as alterações feitas em todas as páginas de propriedades na folha de propriedades são aceitas, a folha de Propriedades retém o foco e `OnApply` retorna TRUE (o valor 1). Antes que `OnApply` possa ser chamado pela estrutura, você deve ter chamado [SetModified](#setmodified) e definir seu parâmetro como true. Isso ativará o botão Aplicar agora assim que o usuário fizer uma alteração na página de propriedades.

Substitua essa função de membro para especificar a ação que seu programa usa quando o usuário clica no botão Aplicar agora. Ao substituir, a função deve retornar TRUE para aceitar alterações e FALSE para evitar que as alterações entrem em vigor.

A implementação padrão de chamadas de `OnApply` `OnOK`.

Para obter mais informações sobre mensagens de notificação enviadas quando o usuário pressiona o botão Aplicar agora ou OK em uma folha de propriedades, consulte [PSN_APPLY](/windows/win32/Controls/psn-apply) na SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CPropertyPage:: OnOK](#onok).

##  <a name="oncancel"></a>CPropertyPage:: OnCancel

Essa função de membro é chamada pela estrutura quando o botão Cancelar é selecionado.

```
virtual void OnCancel();
```

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar ações de botão Cancelar. O padrão nega todas as alterações que foram feitas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#114](../../mfc/codesnippet/cpp/cpropertypage-class_4.cpp)]

##  <a name="onkillactive"></a>CPropertyPage::OnKillActive

Essa função de membro é chamada pela estrutura quando a página não é mais a página ativa.

```
virtual BOOL OnKillActive();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se os dados foram atualizados com êxito, caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas de validação de dados especiais.

A implementação padrão dessa função de membro copia as configurações dos controles na página de propriedades para as variáveis de membro da página de propriedades. Se os dados não foram atualizados com êxito devido a um erro de validação de dados de caixa de diálogo (DDV), a página retém o foco.

Depois que essa função de membro retornar com êxito, a estrutura chamará a função [OnOK](#onok) da página.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#115](../../mfc/codesnippet/cpp/cpropertypage-class_5.cpp)]

##  <a name="onok"></a>CPropertyPage::OnOK

Essa função de membro é chamada pela estrutura quando o usuário escolhe o botão OK ou aplicar agora, imediatamente após a estrutura chamar [OnKillActive](#onkillactive).

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o botão OK ou aplicar agora, a estrutura recebe a notificação de [PSN_APPLY](/windows/win32/Controls/psn-apply) da página de propriedades. A chamada para `OnOK` não será feita se você chamar [CPropertySheet::P ressbutton](../../mfc/reference/cpropertysheet-class.md#pressbutton) porque a página de propriedades não envia a notificação nesse caso.

Substitua essa função de membro para implementar o comportamento adicional específico da página ativa no momento quando o usuário ignorar a folha de propriedades inteira.

A implementação padrão dessa função de membro marca a página como "limpar" para refletir que os dados foram atualizados na função `OnKillActive`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#116](../../mfc/codesnippet/cpp/cpropertypage-class_6.cpp)]

##  <a name="onquerycancel"></a>CPropertyPage:: OnQueryCancel

Essa função de membro é chamada pela estrutura quando o usuário clica no botão Cancelar e antes que a ação de cancelamento ocorra.

```
virtual BOOL OnQueryCancel();
```

### <a name="return-value"></a>Valor retornado

Retorna FALSE para impedir a operação de cancelamento ou TRUE para permitir.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar uma ação que o programa usa quando o usuário clica no botão Cancelar.

A implementação padrão de `OnQueryCancel` retorna TRUE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#117](../../mfc/codesnippet/cpp/cpropertypage-class_7.cpp)]

##  <a name="onreset"></a>CPropertyPage:: OnReset

Essa função de membro é chamada pela estrutura quando o usuário escolhe o botão Cancelar.

```
virtual void OnReset();
```

### <a name="remarks"></a>Comentários

Quando a estrutura chama essa função, as alterações em todas as páginas de propriedades feitas pelo usuário que escolheram anteriormente o botão Aplicar agora são descartadas e a folha de propriedades mantém o foco.

Substitua essa função de membro para especificar a ação que o programa usa quando o usuário clica no botão Cancelar.

A implementação padrão do `OnReset` não faz nada.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CPropertyPage:: OnCancel](#oncancel).

##  <a name="onsetactive"></a>CPropertyPage::OnSetActive

Essa função de membro é chamada pelo Framework quando a página é escolhida pelo usuário e se torna a página ativa.

```
virtual BOOL OnSetActive();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a página tiver sido configurada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas quando uma página for ativada. A substituição dessa função de membro normalmente chamaria a versão padrão depois de atualizar os membros de dados, para permitir que ele atualize os controles de página com os novos dados.

A implementação padrão cria a janela da página, se não tiver sido criada anteriormente, e a torna a página ativa.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CPropertySheet:: SetFinishText](../../mfc/reference/cpropertysheet-class.md#setfinishtext).

##  <a name="onwizardback"></a>CPropertyPage::OnWizardBack

Essa função de membro é chamada pela estrutura quando o usuário clica no botão voltar em um assistente.

```
virtual LRESULT OnWizardBack();
```

### <a name="return-value"></a>Valor retornado

0 avançar automaticamente para a próxima página; -1 para impedir que a página seja alterada. Para saltar para uma página que não seja a próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar alguma ação que o usuário deve executar quando o botão voltar é pressionado.

Para obter mais informações sobre como criar uma folha de propriedades do tipo assistente, consulte [CPropertySheet:: SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#118](../../mfc/codesnippet/cpp/cpropertypage-class_8.cpp)]

##  <a name="onwizardfinish"></a>CPropertyPage::OnWizardFinish

Essa função de membro é chamada pela estrutura quando o usuário clica no botão concluir em um assistente.

```
virtual BOOL OnWizardFinish();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a folha de Propriedades for destruída quando o assistente for concluído; caso contrário, zero.

### <a name="remarks"></a>Comentários

Quando um usuário clica no botão **concluir** em um assistente, a estrutura chama essa função; Quando `OnWizardFinish` retorna TRUE (um valor diferente de zero), a folha de propriedades pode ser destruída (mas não é realmente destruída). Chame `DestroyWindow` para destruir a folha de propriedades. Não chame `DestroyWindow` de `OnWizardFinish`; Isso causará corrupção de heap ou outros erros.

Você pode substituir essa função de membro para especificar alguma ação que o usuário deve executar quando o botão Concluir é pressionado. Ao substituir essa função, retorne FALSE para impedir que a folha de propriedades seja destruída.

Para obter mais informações sobre mensagens de notificação enviadas quando o usuário pressiona o botão concluir em uma folha de propriedades do assistente, consulte [PSN_WIZFINISH](/windows/win32/Controls/psn-wizfinish) na SDK do Windows.

Para obter mais informações sobre como criar uma folha de propriedades do tipo assistente, consulte [CPropertySheet:: SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#119](../../mfc/codesnippet/cpp/cpropertypage-class_9.cpp)]

[!code-cpp[NVC_MFCDocView#120](../../mfc/codesnippet/cpp/cpropertypage-class_10.cpp)]

[!code-cpp[NVC_MFCDocView#121](../../mfc/codesnippet/cpp/cpropertypage-class_11.cpp)]

[!code-cpp[NVC_MFCDocView#122](../../mfc/codesnippet/cpp/cpropertypage-class_12.cpp)]

##  <a name="onwizardnext"></a>CPropertyPage::OnWizardNext

Essa função de membro é chamada pela estrutura quando o usuário clica no botão Avançar em um assistente.

```
virtual LRESULT OnWizardNext();
```

### <a name="return-value"></a>Valor retornado

0 avançar automaticamente para a próxima página; -1 para impedir que a página seja alterada. Para saltar para uma página que não seja a próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar alguma ação que o usuário deve executar quando o botão Avançar for pressionado.

Para obter mais informações sobre como criar uma folha de propriedades do tipo assistente, consulte [CPropertySheet:: SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#123](../../mfc/codesnippet/cpp/cpropertypage-class_13.cpp)]

##  <a name="querysiblings"></a>CPropertyPage::QuerySiblings

Chame essa função de membro para encaminhar uma mensagem para cada página na folha de propriedades.

```
LRESULT QuerySiblings(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>parâmetros

*wParam*<br/>
Especifica informações adicionais dependentes da mensagem.

*lParam*<br/>
Especifica informações adicionais dependentes da mensagem

### <a name="return-value"></a>Valor retornado

O valor diferente de uma página na folha de propriedades ou 0 se todas as páginas retornarem um valor de 0.

### <a name="remarks"></a>Comentários

Se uma página retornar um valor diferente de zero, a folha de propriedades não enviará a mensagem para as páginas subsequentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#124](../../mfc/codesnippet/cpp/cpropertypage-class_14.cpp)]

[!code-cpp[NVC_MFCDocView#125](../../mfc/codesnippet/cpp/cpropertypage-class_15.cpp)]

[!code-cpp[NVC_MFCDocView#126](../../mfc/codesnippet/cpp/cpropertypage-class_16.cpp)]

##  <a name="setmodified"></a>CPropertyPage:: SetModified

Chame essa função de membro para habilitar ou desabilitar o botão Aplicar agora, com base em se as configurações na página de propriedades devem ser aplicadas ao objeto externo apropriado.

```
void SetModified(BOOL bChanged = TRUE);
```

### <a name="parameters"></a>parâmetros

*bChanged*<br/>
TRUE para indicar que as configurações da página de propriedades foram modificadas desde a última vez em que foram aplicadas; FALSE para indicar que as configurações da página de propriedades foram aplicadas ou devem ser ignoradas.

### <a name="remarks"></a>Comentários

A estrutura controla quais páginas são "sujas", ou seja, páginas de propriedades para as quais você chamou `SetModified( TRUE )`. O botão Aplicar agora sempre será habilitado se você chamar `SetModified( TRUE )` para uma das páginas. O botão Aplicar agora será desabilitado quando você chamar `SetModified( FALSE )` para uma das páginas, mas somente se nenhuma das outras páginas for "suja".

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#127](../../mfc/codesnippet/cpp/cpropertypage-class_17.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de CMNCTRL1 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de CMNCTRL2 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de PROPDLG do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de SNAPVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
