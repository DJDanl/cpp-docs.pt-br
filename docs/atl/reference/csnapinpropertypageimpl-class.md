---
title: Classe CSnapInPropertyPageImpl
ms.date: 11/04/2016
f1_keywords:
- CSnapInPropertyPageImpl
- ATLSNAP/ATL::CSnapInPropertyPageImpl
- ATLSNAP/ATL::CSnapInPropertyPageImpl::CSnapInPropertyPageImpl
- ATLSNAP/ATL::CSnapInPropertyPageImpl::CancelToClose
- ATLSNAP/ATL::CSnapInPropertyPageImpl::Create
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnApply
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnHelp
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnKillActive
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnQueryCancel
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnReset
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnSetActive
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnWizardBack
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnWizardFinish
- ATLSNAP/ATL::CSnapInPropertyPageImpl::OnWizardNext
- ATLSNAP/ATL::CSnapInPropertyPageImpl::QuerySiblings
- ATLSNAP/ATL::CSnapInPropertyPageImpl::SetModified
- ATLSNAP/ATL::CSnapInPropertyPageImpl::m_psp
helpviewer_keywords:
- snap-ins, property pages
- snap-ins
- property pages, ATL
- CSnapInPropertyPageImpl class
ms.assetid: 75bdce5a-985e-4166-bd44-493132e023c4
ms.openlocfilehash: abf4cf5804f6ef7335192feb298f1a4a06f841e4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496394"
---
# <a name="csnapinpropertypageimpl-class"></a>Classe CSnapInPropertyPageImpl

Essa classe fornece métodos para implementar um objeto de página de propriedades de snap-in.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
CSnapInPropertyPageImpl : public CDialogImplBase
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInPropertyPageImpl::CSnapInPropertyPageImpl](#csnapinpropertypageimpl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInPropertyPageImpl::CancelToClose](#canceltoclose)|Altera o status dos botões **OK** e **Cancelar** .|
|[CSnapInPropertyPageImpl::Create](#create)|Inicializa um `CSnapInPropertyPageImpl` objeto recém-criado.|
|[CSnapInPropertyPageImpl::OnApply](#onapply)|Chamado pelo Framework quando o usuário clica no botão **aplicar agora** ao usar uma folha de propriedades do tipo assistente.|
|[CSnapInPropertyPageImpl::OnHelp](#onhelp)|Chamado pelo Framework quando o usuário clica no botão **ajuda** ao usar uma folha de propriedades do tipo assistente.|
|[CSnapInPropertyPageImpl::OnKillActive](#onkillactive)|Chamado pelo Framework quando a página atual não está mais ativa.|
|[CSnapInPropertyPageImpl::OnQueryCancel](#onquerycancel)|Chamado pelo Framework quando o usuário clica no botão **Cancelar** e antes que o cancelamento seja colocado.|
|[CSnapInPropertyPageImpl::OnReset](#onreset)|Chamado pelo Framework quando o usuário clica no botão **Redefinir** ao usar uma folha de propriedades do tipo assistente.|
|[CSnapInPropertyPageImpl::OnSetActive](#onsetactive)|Chamado pelo Framework quando a página atual se torna ativa.|
|[CSnapInPropertyPageImpl::OnWizardBack](#onwizardback)|Chamado pelo Framework quando o usuário clica no botão **voltar** ao usar uma folha de propriedades do tipo assistente.|
|[CSnapInPropertyPageImpl::OnWizardFinish](#onwizardfinish)|Chamado pelo Framework quando o usuário clica no botão **concluir** ao usar uma folha de propriedades do tipo assistente.|
|[CSnapInPropertyPageImpl::OnWizardNext](#onwizardnext)|Chamado pelo Framework quando o usuário clica no botão **Avançar** enquanto usa uma folha de propriedades do tipo assistente.|
|[CSnapInPropertyPageImpl::QuerySiblings](#querysiblings)|Encaminha a mensagem atual para todas as páginas da folha de propriedades.|
|[CSnapInPropertyPageImpl::SetModified](#setmodified)|Chame para ativar ou desativar o botão **aplicar agora** .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInPropertyPageImpl::m_psp](#m_psp)|A estrutura `PROPSHEETPAGE` do Windows usada `CSnapInPropertyPageImpl` pelo objeto.|

## <a name="remarks"></a>Comentários

`CSnapInPropertyPageImpl`fornece uma implementação básica para um objeto de página de propriedades de snap-in. Os recursos básicos de uma página de propriedades do snap-in são implementados usando várias interfaces diferentes e tipos de mapa.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDialogImplBase`

`CSnapInPropertyPageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap. h

##  <a name="canceltoclose"></a>  CSnapInPropertyPageImpl::CancelToClose

Chamar essa função depois que uma alteração irrecuperável tiver sido feita nos dados em uma página de uma folha de propriedades modal.

```
void CancelToClose();
```

### <a name="remarks"></a>Comentários

Essa função irá alterar o botão **OK** para **fechar** e desabilitar o botão **Cancelar** . Essa alteração alerta o usuário de que uma alteração é permanente e as modificações não podem ser canceladas.

A `CancelToClose` função membro não faz nada em uma folha de propriedades sem janela restrita, porque uma folha de propriedades sem janela restrita não tem um botão **Cancelar** por padrão.

##  <a name="csnapinpropertypageimpl"></a>CSnapInPropertyPageImpl::CSnapInPropertyPageImpl

Constrói um objeto `CSnapInPropertyPageImpl`.

```
CSnapInPropertyPageImpl(LPCTSTR lpszTitle = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
no O título da página de propriedades.

### <a name="remarks"></a>Comentários

Para inicializar a estrutura subjacente, chame [CSnapInPropertyPageImpl:: Create](#create).

##  <a name="create"></a>CSnapInPropertyPageImpl:: criar

Chame essa função para inicializar a estrutura subjacente da página de propriedades.

```
HPROPSHEETPAGE Create();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para uma `PROPSHEETPAGE` estrutura que contém os atributos da folha de propriedades recém-criada.

### <a name="remarks"></a>Comentários

Primeiro, você deve chamar [CSnapInPropertyPageImpl:: CSnapInPropertyPageImpl](#csnapinpropertypageimpl) antes de chamar essa função.

##  <a name="m_psp"></a>  CSnapInPropertyPageImpl::m_psp

`m_psp`é uma estrutura cujos membros armazenam as características `PROPSHEETPAGE`de.

```
PROPSHEETPAGE m_psp;
```

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência de uma página de propriedades após sua construção.

Para obter mais informações sobre essa estrutura, incluindo uma listagem de seus membros, consulte [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v3) no SDK do Windows.

##  <a name="onapply"></a>  CSnapInPropertyPageImpl::OnApply

Essa função de membro é chamada quando o usuário clica no botão **OK** ou **aplicar agora** .

```
BOOL OnApply();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as alterações forem aceitas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Antes `OnApply` de poder ser chamado pela estrutura, você deve ter chamado `SetModified` e definir seu parâmetro como true. Isso ativará o botão **aplicar agora** assim que o usuário fizer uma alteração na página de propriedades.

Substitua essa função de membro para especificar a ação que seu programa usa quando o usuário clica no botão **aplicar agora** . Ao substituir, a função deve retornar TRUE para aceitar alterações e FALSE para evitar que as alterações entrem em vigor.

A implementação padrão de `OnApply` retorna true.

##  <a name="onhelp"></a>  CSnapInPropertyPageImpl::OnHelp

Essa função de membro é chamada quando o usuário clica no botão **ajuda** para a página de propriedades.

```
void OnHelp();
```

### <a name="remarks"></a>Comentários

Substitua essa função de membro para exibir a ajuda da página de propriedades.

##  <a name="onkillactive"></a>  CSnapInPropertyPageImpl::OnKillActive

Essa função de membro é chamada quando a página não é mais a página ativa.

```
BOOL OnKillActive();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os dados foram atualizados com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas de validação de dados especiais.

##  <a name="onquerycancel"></a>  CSnapInPropertyPageImpl::OnQueryCancel

Essa função de membro é chamada quando o usuário clica no botão **Cancelar** e antes que a ação de cancelamento ocorra.

```
BOOL OnQueryCancel();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero para permitir a operação de cancelamento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar uma ação que o programa usa quando o usuário clica no botão **Cancelar** .

A implementação padrão de `OnQueryCancel` retorna true.

##  <a name="onreset"></a>  CSnapInPropertyPageImpl::OnReset

Essa função de membro é chamada quando o usuário clica no botão **Cancelar** .

```
void OnReset();
```

### <a name="remarks"></a>Comentários

Quando essa função é chamada, as alterações em todas as páginas de propriedades feitas pelo usuário clicando anteriormente no botão **aplicar agora** são descartadas e a folha de Propriedades retém o foco.

Substitua essa função de membro para especificar a ação que o programa usa quando o usuário clica no botão **Cancelar** .

##  <a name="onsetactive"></a>  CSnapInPropertyPageImpl::OnSetActive

Essa função de membro é chamada quando a página é escolhida pelo usuário e torna-se a página ativa.

```
BOOL OnSetActive();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a página tiver sido configurada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas quando uma página for ativada. A substituição dessa função de membro deve chamar a versão padrão antes que qualquer outro processamento seja feito.

A implementação padrão retorna TRUE.

##  <a name="onwizardback"></a>  CSnapInPropertyPageImpl::OnWizardBack

Essa função de membro é chamada quando o usuário clica no botão **voltar** em um assistente.

```
BOOL OnWizardBack();
```

### <a name="return-value"></a>Valor de retorno

- 0 para avançar automaticamente para a página anterior.

- -1 para impedir que a página seja alterada.

Para saltar para uma página que não seja a próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar alguma ação que o usuário deve executar quando o botão **voltar** for clicado.

##  <a name="onwizardfinish"></a>  CSnapInPropertyPageImpl::OnWizardFinish

Essa função de membro é chamada quando o usuário clica no botão **concluir** em um assistente.

```
BOOL OnWizardFinish();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de Propriedades for destruída quando o assistente for concluído; caso contrário, zero.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar alguma ação que o usuário deve executar quando o botão **concluir** é clicado.

##  <a name="onwizardnext"></a>CSnapInPropertyPageImpl::OnWizardNext

Essa função de membro é chamada quando o usuário clica no botão **Avançar** em um assistente.

```
BOOL OnWizardNext();
```

### <a name="return-value"></a>Valor de retorno

- 0 para avançar automaticamente para a próxima página.

- -1 para impedir que a página seja alterada.

Para saltar para uma página que não seja a próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para especificar alguma ação que o usuário deve executar quando o botão **Avançar** for clicado.

##  <a name="querysiblings"></a>  CSnapInPropertyPageImpl::QuerySiblings

Chame essa função de membro para encaminhar uma mensagem para cada página na folha de propriedades.

```
LRESULT QuerySiblings(WPARAM wParam, LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
no Especifica informações adicionais dependentes da mensagem.

*lParam*<br/>
no Especifica informações adicionais dependentes da mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem não deve ser encaminhada para a próxima página de propriedades; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se uma página retornar um valor diferente de zero, a folha de propriedades não enviará a mensagem para as páginas subsequentes.

##  <a name="setmodified"></a>  CSnapInPropertyPageImpl::SetModified

Chame essa função de membro para habilitar ou desabilitar o botão **aplicar agora** , com base em se as configurações na página de propriedades devem ser aplicadas ao objeto externo apropriado.

```
void SetModified(BOOL bChanged = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bChanged*<br/>
no TRUE para indicar que as configurações da página de propriedades foram modificadas desde a última vez em que foram aplicadas; FALSE para indicar que as configurações da página de propriedades foram aplicadas ou devem ser ignoradas.

### <a name="remarks"></a>Comentários

A folha de Propriedades controla quais páginas são "sujas", ou seja, páginas de propriedades para as quais você `SetModified( TRUE )`chamou. O botão **aplicar agora** sempre será habilitado se você chamar `SetModified( TRUE )` uma das páginas. O botão **aplicar agora** será desabilitado quando você chamar `SetModified( FALSE )` uma das páginas, mas somente se nenhuma das outras páginas for "suja".

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
