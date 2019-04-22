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
ms.openlocfilehash: 9d4100037c5a6cd2eeef1a50fb2d5a46b2cb6505
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58772717"
---
# <a name="cpropertypage-class"></a>Classe CPropertyPage

Representa páginas individuais de uma folha de propriedades, também conhecido como uma caixa de diálogo de guia.

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
|[CPropertyPage::CancelToClose](#canceltoclose)|Altera o botão Okey para ler fechar e desabilita o botão Cancelar, após uma alteração irrecuperável na página de uma folha de propriedades modal.|
|[CPropertyPage::Construct](#construct)|Constrói um objeto `CPropertyPage`. Use `Construct` se você deseja especificar os parâmetros de tempo de execução, ou se você estiver usando matrizes.|
|[CPropertyPage::GetPSP](#getpsp)|Recupera o Windows [PROPSHEETPAGE](/windows/desktop/api/prsht/ns-prsht-_propsheetpagea_v2) estrutura associada a `CPropertyPage` objeto.|
|[CPropertyPage::OnApply](#onapply)|Chamado pelo framework quando o botão Aplicar agora é clicado.|
|[CPropertyPage::OnCancel](#oncancel)|Chamado pelo framework quando o botão Cancelar é clicado.|
|[CPropertyPage::OnKillActive](#onkillactive)|Chamado pelo framework quando a página atual não é mais a página ativa. Execute a validação de dados aqui.|
|[CPropertyPage::OnOK](#onok)|Chamado pelo framework quando o Okey, aplicar agora ou botão Fechar é clicado.|
|[CPropertyPage::OnQueryCancel](#onquerycancel)|Chamado pelo framework quando o botão Cancelar é clicado e antes que o cancelamento aconteça.|
|[CPropertyPage::OnReset](#onreset)|Chamado pelo framework quando o botão Cancelar é clicado.|
|[CPropertyPage::OnSetActive](#onsetactive)|Chamado pelo framework quando a página é feita a página ativa.|
|[CPropertyPage::OnWizardBack](#onwizardback)|Chamado pelo framework quando o botão Voltar é clicado durante o uso de uma folha de propriedades de tipo de assistente.|
|[CPropertyPage::OnWizardFinish](#onwizardfinish)|Chamado pelo framework quando o botão Concluir é clicado durante o uso de uma folha de propriedades de tipo de assistente.|
|[CPropertyPage::OnWizardNext](#onwizardnext)|Chamado pelo framework quando o botão Avançar é clicado durante o uso de uma folha de propriedades de tipo de assistente.|
|[CPropertyPage::QuerySiblings](#querysiblings)|Encaminha a mensagem para cada página da folha de propriedades.|
|[CPropertyPage::SetModified](#setmodified)|Chamada para ativar ou desativar o botão Aplicar agora.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertyPage::m_psp](#m_psp)|O Windows [PROPSHEETPAGE](/windows/desktop/api/prsht/ns-prsht-_propsheetpagea_v2) estrutura. Fornece acesso aos parâmetros de página de propriedade básico.|

## <a name="remarks"></a>Comentários

Como com caixas de diálogo padrão, você deriva uma classe de `CPropertyPage` para cada página na sua folha de propriedades. Para usar `CPropertyPage`-objetos derivados, primeiro crie um [CPropertySheet](../../mfc/reference/cpropertysheet-class.md) de objeto e, em seguida, crie um objeto para cada página que vai para a folha de propriedades. Chame [CPropertySheet::AddPage](../../mfc/reference/cpropertysheet-class.md#addpage) para cada página na planilha e, em seguida, exibir a folha de propriedades chamando [CPropertySheet::DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) para uma folha de propriedades modal, ou [CPropertySheet:: Criar](../../mfc/reference/cpropertysheet-class.md#create) para uma folha de propriedades sem janela restrita.

Você pode criar um tipo de caixa de diálogo de guia chamado um assistente, que consiste em uma folha de propriedades com uma sequência de páginas de propriedade que guiam o usuário pelas etapas de uma operação, como configuração de um dispositivo ou criando um boletim informativo. Na caixa de diálogo guia de tipo de assistente, as páginas de propriedade não tem as guias e página de apenas uma propriedade é visível por vez. Além disso, em vez de ter botões Okey e aplicar agora, uma caixa de diálogo de tipo de assistente guia tem um botão Voltar, um botão Avançar ou em Concluir e um botão Cancelar.

Para obter mais informações sobre como estabelecer uma folha de propriedades como um assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode). Para obter mais informações sobre como usar `CPropertyPage` objetos, consulte o artigo [folhas de propriedades e páginas de propriedade](../../mfc/property-sheets-and-property-pages-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

`CPropertyPage`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="canceltoclose"></a>  CPropertyPage::CancelToClose

Chame essa função após uma alteração irrecuperável foi feita para os dados em uma página de uma folha de propriedades modais.

```
void CancelToClose();
```

### <a name="remarks"></a>Comentários

Essa função será alterar o botão Okey para fechado e desabilitar o botão Cancelar. Essa alteração não é possível cancelar o usuário que uma alteração é permanente e as modificações de alertas.

O `CancelToClose` função de membro não faz nada em uma folha de propriedades sem janela restrita, porque uma folha de propriedades sem janela restrita não tem um botão Cancelar por padrão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertyPage::QuerySiblings](#querysiblings).

##  <a name="construct"></a>  CPropertyPage::Construct

Chame essa função de membro para construir um `CPropertyPage` objeto.

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

### <a name="parameters"></a>Parâmetros

*nIDTemplate*<br/>
ID do modelo usado para esta página.

*nIDCaption*<br/>
ID de nome a ser colocado na guia para esta página. Se for 0, o nome será obtido do modelo de caixa de diálogo para essa página.

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo.

*nIDHeaderTitle*<br/>
ID de nome a ser colocado no local de título do cabeçalho da página de propriedade. Por padrão, 0.

*nIDHeaderSubTitle*<br/>
ID de nome a ser colocado no local de subtítulo do cabeçalho da página de propriedade. Por padrão, 0.

### <a name="remarks"></a>Comentários

O objeto é exibido depois que todas as seguintes condições forem atendidas:

- A página foi adicionada a uma folha de propriedade usando [CPropertySheet::AddPage](../../mfc/reference/cpropertysheet-class.md#addpage).

- A folha de propriedades [DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) ou [criar](../../mfc/reference/cpropertysheet-class.md#create) a função foi chamada.

- O usuário tiver selecionado (com guias para) nesta página.

Chamar `Construct` se um dos outros construtores de classe não tiver sido chamado. O `Construct` função de membro é flexível porque você pode deixar a declaração de parâmetro em branco e, em seguida, especificar vários parâmetros e construção em qualquer ponto em seu código.

Você deve usar `Construct` quando você trabalhar com matrizes, e você deve chamar `Construct` para cada membro da matriz para que os membros de dados são atribuídos valores adequados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#112](../../mfc/codesnippet/cpp/cpropertypage-class_1.cpp)]

##  <a name="cpropertypage"></a>  CPropertyPage::CPropertyPage

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

*nIDTemplate*<br/>
ID do modelo usado para esta página.

*nIDCaption*<br/>
ID de nome a ser colocado na guia para esta página. Se for 0, o nome será obtido do modelo de caixa de diálogo para essa página.

*dwSize*<br/>
*lpszTemplateName* aponta para uma cadeia de caracteres que contém o nome do modelo para essa página. Não pode ser NULL.

*nIDHeaderTitle*<br/>
ID de nome a ser colocado no local de título do cabeçalho da página de propriedade.

*nIDHeaderSubTitle*<br/>
ID de nome a ser colocado no local de subtítulo do cabeçalho da página de propriedade.

### <a name="remarks"></a>Comentários

O objeto é exibido depois que todas as seguintes condições forem atendidas:

- A página foi adicionada a uma folha de propriedade usando [CPropertySheet::AddPage](../../mfc/reference/cpropertysheet-class.md#addpage).

- A folha de propriedades [DoModal](../../mfc/reference/cpropertysheet-class.md#domodal) ou [criar](../../mfc/reference/cpropertysheet-class.md#create) a função foi chamada.

- O usuário tiver selecionado (com guias para) nesta página.

Se você tiver vários parâmetros (por exemplo, se você estiver usando uma matriz), use [CPropertySheet::Construct](../../mfc/reference/cpropertysheet-class.md#construct) em vez de `CPropertyPage`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#113](../../mfc/codesnippet/cpp/cpropertypage-class_2.cpp)]

##  <a name="getpsp"></a>  CPropertyPage::GetPSP

Recupera o Windows [PROPSHEETPAGE](/windows/desktop/api/prsht/ns-prsht-_propsheetpagea_v2) estrutura associada a `CPropertyPage` objeto.

```
const PROPSHEETPAGE& GetPSP() const;

PROPSHEETPAGE& GetPSP();
```

### <a name="return-value"></a>Valor de retorno

Uma referência para o `PROPSHEETPAGE` estrutura.

##  <a name="m_psp"></a>  CPropertyPage::m_psp

`m_psp` é uma estrutura cujos membros armazenam as características dos [PROPSHEETPAGE](/windows/desktop/api/prsht/ns-prsht-_propsheetpagea_v2).

```
PROPSHEETPAGE m_psp;
```

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência de uma página de propriedades, depois que ele é construído.

Para obter mais informações sobre essa estrutura, incluindo uma lista de seus membros, consulte `PROPSHEETPAGE` no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#128](../../mfc/codesnippet/cpp/cpropertypage-class_3.cpp)]

##  <a name="onapply"></a>  CPropertyPage::OnApply

Essa função membro é chamada pelo framework quando o usuário escolhe o Okey ou no botão Aplicar agora.

```
virtual BOOL OnApply();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as alterações sejam aceitas; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando o framework chama esta função, as alterações feitas em todas as páginas de propriedade na folha de propriedades são aceitos, a folha de propriedades mantém o foco, e `OnApply` retorna TRUE (o valor 1). Antes de `OnApply` pode ser chamado pelo framework, você deve ter chamado [SetModified](#setmodified) e defina seu parâmetro como TRUE. Isso ativará o botão Aplicar Agora, assim que o usuário faz uma alteração na página de propriedades.

Substitua essa função de membro para especificar a ação que seu programa usa quando o usuário clica no botão Aplicar agora. Durante a substituição, a função deve retornar TRUE para aceitar as alterações e FALSE para impedir que as alterações entrarem em vigor.

A implementação padrão de `OnApply` chamadas `OnOK`.

Para obter mais informações sobre mensagens de notificação enviado quando o usuário pressiona a aplicar agora ou botão Okey em uma folha de propriedades, consulte [PSN_APPLY](/windows/desktop/Controls/psn-apply) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertyPage::OnOK](#onok).

##  <a name="oncancel"></a>  CPropertyPage::OnCancel

Essa função membro é chamada pelo framework quando o botão Cancelar é selecionado.

```
virtual void OnCancel();
```

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar ações de botão de cancelamento. O padrão nega as alterações que foram feitas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#114](../../mfc/codesnippet/cpp/cpropertypage-class_4.cpp)]

##  <a name="onkillactive"></a>  CPropertyPage::OnKillActive

Essa função membro é chamada pelo framework quando a página não é mais a página ativa.

```
virtual BOOL OnKillActive();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se dados foram atualizados com êxito, caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas de validação de dados especiais.

A implementação padrão dessa função membro copia as configurações dos controles na página de propriedades para as variáveis de membro da página de propriedades. Se os dados não foi atualizados com êxito devido a um erro de validação (DDV) de dados de caixa de diálogo, a página mantém o foco.

Depois que essa função membro retorna com êxito, a estrutura chamará a página [OnOK](#onok) função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#115](../../mfc/codesnippet/cpp/cpropertypage-class_5.cpp)]

##  <a name="onok"></a>  CPropertyPage::OnOK

Essa função membro é chamada pelo framework quando o usuário escolhe o Okey ou o botão Aplicar Agora, imediatamente após a estrutura chama [OnKillActive](#onkillactive).

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o Okey ou o botão Aplicar Agora, o framework recebe o [PSN_APPLY](/windows/desktop/Controls/psn-apply) notificação da página de propriedade. A chamada para `OnOK` não será feita se você chamar [CPropertySheet::PressButton](../../mfc/reference/cpropertysheet-class.md#pressbutton) porque a página de propriedades não envia a notificação nesse caso.

Substitua essa função de membro para implementar o comportamento adicional específico para a página ativa no momento quando o usuário fechar a folha de propriedades de inteiro.

A implementação padrão dessa função de membro marca a página como "Limpar" para refletir que os dados foram atualizados no `OnKillActive` função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#116](../../mfc/codesnippet/cpp/cpropertypage-class_6.cpp)]

##  <a name="onquerycancel"></a>  CPropertyPage::OnQueryCancel

Essa função membro é chamada pelo framework quando o usuário clica no botão Cancelar e antes de cancelar a ação tiver sido feita.

```
virtual BOOL OnQueryCancel();
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE para permitir que ele ou FALSE para impedir que a operação de cancelamento.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar uma ação que o programa usa quando o usuário clica no botão Cancelar.

A implementação padrão de `OnQueryCancel` retorna TRUE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#117](../../mfc/codesnippet/cpp/cpropertypage-class_7.cpp)]

##  <a name="onreset"></a>  CPropertyPage::OnReset

Essa função membro é chamada pelo framework quando o usuário escolhe o botão Cancelar.

```
virtual void OnReset();
```

### <a name="remarks"></a>Comentários

Quando o framework chama esta função, as alterações a todas as páginas de propriedade que foram feitas pelo usuário anteriormente escolhendo o botão Aplicar agora são descartadas e a folha de propriedades retém o foco.

Substitua essa função de membro para especificar qual ação o programa usa quando o usuário clica no botão Cancelar.

A implementação padrão de `OnReset` não faz nada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertyPage::OnCancel](#oncancel).

##  <a name="onsetactive"></a>  CPropertyPage::OnSetActive

Essa função membro é chamada pelo framework quando a página é escolhida pelo usuário e torna-se a página ativa.

```
virtual BOOL OnSetActive();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a página foi definida com êxito ativa; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas quando uma página é ativada. Sua substituição dessa função de membro normalmente chamaria a versão padrão depois de atualizar os membros de dados, para permitir que ele atualize os controles de página com os novos dados.

A implementação padrão cria a janela para a página, se não for criado anteriormente e torna a página ativa.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::SetFinishText](../../mfc/reference/cpropertysheet-class.md#setfinishtext).

##  <a name="onwizardback"></a>  CPropertyPage::OnWizardBack

Essa função membro é chamada pelo framework quando o usuário clica no botão Voltar em um assistente.

```
virtual LRESULT OnWizardBack();
```

### <a name="return-value"></a>Valor de retorno

0 para automaticamente ir para a próxima página. -1 para impedir que a página de alteração. Para ir diretamente para uma página que não seja o próximo, retorne o identificador da caixa de diálogo a ser exibido.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar uma ação que o usuário deve executar quando o botão Voltar é pressionado.

Para obter mais informações sobre como tornar uma folha de propriedades de tipo de assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#118](../../mfc/codesnippet/cpp/cpropertypage-class_8.cpp)]

##  <a name="onwizardfinish"></a>  CPropertyPage::OnWizardFinish

Essa função membro é chamada pelo framework quando o usuário clica no botão Concluir em um assistente.

```
virtual BOOL OnWizardFinish();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de propriedades é destruída quando o assistente for concluído; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Quando um usuário clica o **terminar** botão em um assistente, o framework chama esta função; quando `OnWizardFinish` retorna TRUE (um valor diferente de zero), a folha de propriedades é capaz de ser destruída (mas, na verdade, não será destruído). Chamar `DestroyWindow` destruir a folha de propriedades. Não chame `DestroyWindow` de `OnWizardFinish`; isso causaria a corrupção do heap ou outros erros.

Você pode substituir essa função de membro para especificar uma ação que o usuário deve executar quando o botão Concluir é pressionado. Ao substituir essa função, retorne FALSE para impedir que a folha de propriedades sendo destruído.

Para obter mais informações sobre mensagens de notificação enviado quando o usuário pressiona o botão Concluir em uma folha de propriedades do assistente, consulte [PSN_WIZFINISH](/windows/desktop/Controls/psn-wizfinish) no SDK do Windows.

Para obter mais informações sobre como tornar uma folha de propriedades de tipo de assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#119](../../mfc/codesnippet/cpp/cpropertypage-class_9.cpp)]

[!code-cpp[NVC_MFCDocView#120](../../mfc/codesnippet/cpp/cpropertypage-class_10.cpp)]

[!code-cpp[NVC_MFCDocView#121](../../mfc/codesnippet/cpp/cpropertypage-class_11.cpp)]

[!code-cpp[NVC_MFCDocView#122](../../mfc/codesnippet/cpp/cpropertypage-class_12.cpp)]

##  <a name="onwizardnext"></a>  CPropertyPage::OnWizardNext

Essa função membro é chamada pelo framework quando o usuário clica no botão Avançar em um assistente.

```
virtual LRESULT OnWizardNext();
```

### <a name="return-value"></a>Valor de retorno

0 para automaticamente ir para a próxima página. -1 para impedir que a página de alteração. Para ir diretamente para uma página que não seja o próximo, retorne o identificador da caixa de diálogo a ser exibido.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar uma ação que o usuário deve executar quando o botão Avançar é pressionado.

Para obter mais informações sobre como tornar uma folha de propriedades de tipo de assistente, consulte [CPropertySheet::SetWizardMode](../../mfc/reference/cpropertysheet-class.md#setwizardmode).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#123](../../mfc/codesnippet/cpp/cpropertypage-class_13.cpp)]

##  <a name="querysiblings"></a>  CPropertyPage::QuerySiblings

Chame essa função de membro para encaminhar uma mensagem para cada página na folha de propriedades.

```
LRESULT QuerySiblings(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
Especifica informações adicionais de dependente de mensagem.

*lParam*<br/>
Especifica informações adicionais de dependente de mensagem

### <a name="return-value"></a>Valor de retorno

O valor diferente de zero de uma página da folha de propriedades, ou 0 se todas as páginas de retornam um valor de 0.

### <a name="remarks"></a>Comentários

Se uma página retorna um valor diferente de zero, a folha de propriedades não envia a mensagem para as páginas subsequentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#124](../../mfc/codesnippet/cpp/cpropertypage-class_14.cpp)]

[!code-cpp[NVC_MFCDocView#125](../../mfc/codesnippet/cpp/cpropertypage-class_15.cpp)]

[!code-cpp[NVC_MFCDocView#126](../../mfc/codesnippet/cpp/cpropertypage-class_16.cpp)]

##  <a name="setmodified"></a>  CPropertyPage::SetModified

Chame essa função de membro para habilitar ou desabilitar o botão Aplicar Agora, com base em se as configurações na página de propriedades devem ser aplicadas ao objeto apropriado externo.

```
void SetModified(BOOL bChanged = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bChanged*<br/>
TRUE para indicar que as configurações de página de propriedade foram modificadas desde a última vez em que eles foram aplicados; FALSE para indicar que as configurações de página de propriedade foram aplicadas, ou devem ser ignoradas.

### <a name="remarks"></a>Comentários

O framework mantém controle de quais páginas estão "sujas", ou seja, as páginas de propriedades para o qual você chamou `SetModified( TRUE )`. O botão Aplicar agora sempre será habilitado se você chamar `SetModified( TRUE )` para uma das páginas. O botão Aplicar agora será desabilitado quando você chama `SetModified( FALSE )` para uma das páginas, mas apenas se nenhuma das outras páginas é "suja".

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#127](../../mfc/codesnippet/cpp/cpropertypage-class_17.cpp)]

## <a name="see-also"></a>Consulte também

[CMNCTRL1 de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[CMNCTRL2 de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC PROPDLG](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
