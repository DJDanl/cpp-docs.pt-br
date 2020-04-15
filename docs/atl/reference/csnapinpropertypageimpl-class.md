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
ms.openlocfilehash: ae64c212520510a443fbb2b8adc99243e8f8843a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330693"
---
# <a name="csnapinpropertypageimpl-class"></a>Classe CSnapInPropertyPageImpl

Esta classe fornece métodos para implementar um objeto de página de propriedade snap-in.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CSnapInPropertyPageImpl::CancelToClose](#canceltoclose)|Altera o status dos botões **OK** e **Cancel.**|
|[CSnapInPropertyPageImpl::Criar](#create)|Inicializa um objeto `CSnapInPropertyPageImpl` recém-criado.|
|[CSnapInPropertyPageImpl::OnApply](#onapply)|Chamado pela estrutura quando o usuário clica no botão **Aplicar agora** ao usar uma folha de propriedade do tipo assistente.|
|[CSnapInPropertyPageImpl::OnHelp](#onhelp)|Chamado pela estrutura quando o usuário clica no botão **Ajuda** ao usar uma folha de propriedade do tipo assistente.|
|[CSnapInPropertyPageImpl::OnKillActive](#onkillactive)|Chamado pelo framework quando a página atual não estiver mais ativa.|
|[CSnapInPropertyPageImpl::OnQueryCancel](#onquerycancel)|Chamado pela estrutura quando o usuário clica no botão **Cancelar** e antes que o cancelamento tenha ocorrido.|
|[CSnapInPropertyPageImpl::OnReset](#onreset)|Chamado pela estrutura quando o usuário clica no botão **Redefinir** enquanto usa uma folha de propriedade do tipo assistente.|
|[CSnapInPropertyPageImpl::OnSetActive](#onsetactive)|Chamado pelo framework quando a página atual se torna ativa.|
|[CSnapInPropertyPageImpl::OnWizardBack](#onwizardback)|Chamado pela estrutura quando o usuário clica no botão **Voltar** enquanto usa uma folha de propriedade do tipo assistente.|
|[CSnapInPropertyPageImpl::OnWizardFinish](#onwizardfinish)|Chamado pela estrutura quando o usuário clica no botão **Concluir** enquanto usa uma folha de propriedade do tipo assistente.|
|[CSnapInPropertyPageImpl::OnWizardNext](#onwizardnext)|Chamado pela estrutura quando o usuário clica no botão **Next** enquanto usa uma folha de propriedade do tipo assistente.|
|[CSnapInPropertyPageImpl::QuerySiblings](#querysiblings)|Encaminha a mensagem atual para todas as páginas da folha de propriedades.|
|[CSnapInPropertyPageImpl::SetModified](#setmodified)|Ligue para ativar ou desativar o botão **Aplicar agora.**|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInPropertyPageImpl::m_psp](#m_psp)|A `PROPSHEETPAGE` estrutura do `CSnapInPropertyPageImpl` Windows usada pelo objeto.|

## <a name="remarks"></a>Comentários

`CSnapInPropertyPageImpl`fornece uma implementação básica para um objeto de página de propriedade snap-in. Os recursos básicos de uma página de propriedade snap-in são implementados usando várias interfaces diferentes e tipos de mapa.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDialogImplBase`

`CSnapInPropertyPageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap.h

## <a name="csnapinpropertypageimplcanceltoclose"></a><a name="canceltoclose"></a>CSnapInPropertyPageImpl::CancelToClose

Chame essa função depois que uma alteração irrecuperável foi feita para os dados em uma página de uma folha de propriedade modal.

```
void CancelToClose();
```

### <a name="remarks"></a>Comentários

Esta função mudará o botão **OK** para **Fechar** e desativará o botão **Cancelar.** Essa alteração alerta o usuário de que uma alteração é permanente e as modificações não podem ser canceladas.

A `CancelToClose` função de membro não faz nada em uma folha de propriedade modeless, porque uma folha de propriedade modeless não tem um botão **Cancelar** por padrão.

## <a name="csnapinpropertypageimplcsnapinpropertypageimpl"></a><a name="csnapinpropertypageimpl"></a>CSnapInPropertyPageImpl::CSnapInPropertyPageImpl

Constrói um objeto `CSnapInPropertyPageImpl`.

```
CSnapInPropertyPageImpl(LPCTSTR lpszTitle = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
[em] O título da página da propriedade.

### <a name="remarks"></a>Comentários

Para inicializar a estrutura subjacente, chame [CSnapInPropertyPageImpl::Create](#create).

## <a name="csnapinpropertypageimplcreate"></a><a name="create"></a>CSnapInPropertyPageImpl::Criar

Chame esta função para inicializar a estrutura subjacente da página de propriedade.

```
HPROPSHEETPAGE Create();
```

### <a name="return-value"></a>Valor retornado

Uma alça `PROPSHEETPAGE` para uma estrutura contendo os atributos da folha de propriedade recém-criada.

### <a name="remarks"></a>Comentários

Primeiro deve ligar para [CSnapInPropertyPageImpl::CSnapInPropertyPageImpl](#csnapinpropertypageimpl) antes de chamar essa função.

## <a name="csnapinpropertypageimplm_psp"></a><a name="m_psp"></a>CSnapInPropertyPageImpl::m_psp

`m_psp`é uma estrutura cujos membros `PROPSHEETPAGE`armazenam as características de .

```
PROPSHEETPAGE m_psp;
```

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência de uma página de propriedade depois de construída.

Para obter mais informações sobre esta estrutura, incluindo uma listagem de seus membros, consulte [PROPSHEETPAGE](/windows/win32/api/prsht/ns-prsht-propsheetpagea_v3) no Windows SDK.

## <a name="csnapinpropertypageimplonapply"></a><a name="onapply"></a>CSnapInPropertyPageImpl::OnApply

Esta função de membro é chamada quando o usuário clica no **botão OK** ou **"Aplicar agora".**

```
BOOL OnApply();
```

### <a name="return-value"></a>Valor retornado

Não zero se as alterações forem aceitas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Antes `OnApply` de ser chamado pela estrutura, `SetModified` você deve ter chamado e definido seu parâmetro como TRUE. Isso ativará o botão **Aplicar agora** assim que o usuário fizer uma alteração na página da propriedade.

Substituir esta função de membro para especificar que ação seu programa toma quando o usuário clica no botão **Aplicar agora.** Ao ser sobreposta, a função deve retornar TRUE para aceitar alterações e FALSE para evitar que as alterações surtam efeito.

A implementação `OnApply` padrão de devoluções TRUE.

## <a name="csnapinpropertypageimplonhelp"></a><a name="onhelp"></a>CSnapInPropertyPageImpl::OnHelp

Essa função de membro é chamada quando o usuário clica no botão **Ajuda** para a página da propriedade.

```
void OnHelp();
```

### <a name="remarks"></a>Comentários

Substituir esta função de membro para exibir ajuda para a página de propriedade.

## <a name="csnapinpropertypageimplonkillactive"></a><a name="onkillactive"></a>CSnapInPropertyPageImpl::OnKillActive

Essa função de membro é chamada quando a página não é mais a página ativa.

```
BOOL OnKillActive();
```

### <a name="return-value"></a>Valor retornado

Não zero se os dados foram atualizados com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para executar tarefas especiais de validação de dados.

## <a name="csnapinpropertypageimplonquerycancel"></a><a name="onquerycancel"></a>CSnapInPropertyPageImpl::OnQueryCancel

Essa função de membro é chamada quando o usuário **clica** no botão Cancelar e antes que a ação de cancelamento tenha ocorrido.

```
BOOL OnQueryCancel();
```

### <a name="return-value"></a>Valor retornado

Não zero para permitir a operação de cancelamento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar uma ação que o programa toma quando o usuário clica no botão **Cancelar.**

A implementação `OnQueryCancel` padrão de devoluções TRUE.

## <a name="csnapinpropertypageimplonreset"></a><a name="onreset"></a>CSnapInPropertyPageImpl::OnReset

Esta função de membro é chamada quando o usuário clica no botão **Cancelar.**

```
void OnReset();
```

### <a name="remarks"></a>Comentários

Quando essa função é chamada, as alterações em todas as páginas de propriedade que foram feitas pelo usuário anteriormente clicando no botão **Aplicar agora** são descartadas, e a folha de propriedades mantém o foco.

Substituir esta função de membro para especificar que ação o programa toma quando o usuário clica no botão **Cancelar.**

## <a name="csnapinpropertypageimplonsetactive"></a><a name="onsetactive"></a>CSnapInPropertyPageImpl::OnSetActive

Essa função de membro é chamada quando a página é escolhida pelo usuário e se torna a página ativa.

```
BOOL OnSetActive();
```

### <a name="return-value"></a>Valor retornado

Não zero se a página foi definida com sucesso ativa; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para executar tarefas quando uma página é ativada. Sua substituição desta função de membro deve chamar a versão padrão antes que qualquer outro processamento seja feito.

A implementação padrão retorna TRUE.

## <a name="csnapinpropertypageimplonwizardback"></a><a name="onwizardback"></a>CSnapInPropertyPageImpl::OnWizardBack

Esta função de membro é chamada quando o usuário clica no botão **Voltar** em um assistente.

```
BOOL OnWizardBack();
```

### <a name="return-value"></a>Valor retornado

- 0 para avançar automaticamente para a página anterior.

- -1 para evitar que a página mude.

Para saltar para uma página diferente da próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar alguma ação que o usuário deve tomar quando o botão **Voltar** é clicado.

## <a name="csnapinpropertypageimplonwizardfinish"></a><a name="onwizardfinish"></a>CSnapInPropertyPageImpl::OnWizardFinish

Esta função de membro é chamada quando o usuário **clica** no botão Concluir em um assistente.

```
BOOL OnWizardFinish();
```

### <a name="return-value"></a>Valor retornado

Não zero se a folha de propriedade for destruída quando o assistente terminar; caso contrário, zero.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar alguma ação que o usuário deve tomar quando o botão **Concluir** é clicado.

## <a name="csnapinpropertypageimplonwizardnext"></a><a name="onwizardnext"></a>CSnapInPropertyPageImpl::OnWizardNext

Esta função de membro é chamada quando o usuário clica no botão **Next** em um assistente.

```
BOOL OnWizardNext();
```

### <a name="return-value"></a>Valor retornado

- 0 para avançar automaticamente para a próxima página.

- -1 para evitar que a página mude.

Para saltar para uma página diferente da próxima, retorne o identificador da caixa de diálogo a ser exibida.

### <a name="remarks"></a>Comentários

Substituir esta função de membro para especificar alguma ação que o usuário deve tomar quando o botão **Next** é clicado.

## <a name="csnapinpropertypageimplquerysiblings"></a><a name="querysiblings"></a>CSnapInPropertyPageImpl::QuerySiblings

Ligue para esta função de membro para encaminhar uma mensagem para cada página na folha de propriedades.

```
LRESULT QuerySiblings(WPARAM wParam, LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
[em] Especifica informações adicionais dependentes de mensagens.

*lParam*<br/>
[em] Especifica informações adicionais dependentes de mensagens.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem não for encaminhada para a próxima página de propriedade; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se uma página retornar um valor não zero, a folha de propriedade não enviará a mensagem para as páginas subseqüentes.

## <a name="csnapinpropertypageimplsetmodified"></a><a name="setmodified"></a>CSnapInPropertyPageImpl::SetModified

Chame esta função de membro para ativar ou desativar o botão **Aplicar agora,** com base em se as configurações na página de propriedade devem ser aplicadas ao objeto externo apropriado.

```
void SetModified(BOOL bChanged = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bChanged*<br/>
[em] VERDADEIRO indicar que as configurações da página de propriedade foram modificadas desde a última vez que foram aplicadas; FALSO para indicar que as configurações da página de propriedade foram aplicadas ou devem ser ignoradas.

### <a name="remarks"></a>Comentários

A folha de propriedades mantém o controle de quais páginas são `SetModified( TRUE )`"sujas", ou seja, páginas de propriedade para as quais você chamou . O botão **Aplicar agora** estará sempre `SetModified( TRUE )` ativado se você chamar uma das páginas. O botão **Aplicar agora** será `SetModified( FALSE )` desativado quando você chamar uma das páginas, mas somente se nenhuma das outras páginas estiver "suja".

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
