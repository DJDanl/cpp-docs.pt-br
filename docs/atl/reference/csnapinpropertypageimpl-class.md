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
ms.openlocfilehash: dd60afc34b1a2de8f86037eb180aab86a9b8afde
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503081"
---
# <a name="csnapinpropertypageimpl-class"></a>Classe CSnapInPropertyPageImpl

Essa classe fornece métodos para a implementação de um objeto de página de propriedade do snap-in.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CSnapInPropertyPageImpl::CancelToClose](#canceltoclose)|Altera o status dos **Okey** e **Cancelar** botões.|
|[CSnapInPropertyPageImpl::Create](#create)|Inicializa um recém-criado `CSnapInPropertyPageImpl` objeto.|
|[CSnapInPropertyPageImpl::OnApply](#onapply)|Chamado pelo framework quando o usuário clica o **aplicar agora** botão durante o uso de uma folha de propriedades de tipo de assistente.|
|[CSnapInPropertyPageImpl::OnHelp](#onhelp)|Chamado pelo framework quando o usuário clica o **ajudar** botão durante o uso de uma folha de propriedades de tipo de assistente.|
|[CSnapInPropertyPageImpl::OnKillActive](#onkillactive)|Chamado pelo framework quando a página atual não está mais ativa.|
|[CSnapInPropertyPageImpl::OnQueryCancel](#onquerycancel)|Chamado pelo framework quando o usuário clica o **Cancelar** botão e antes que o cancelamento aconteça.|
|[CSnapInPropertyPageImpl::OnReset](#onreset)|Chamado pelo framework quando o usuário clica o **redefinir** botão durante o uso de uma folha de propriedades de tipo de assistente.|
|[CSnapInPropertyPageImpl::OnSetActive](#onsetactive)|Chamado pelo framework quando a página atual se torna ativa.|
|[CSnapInPropertyPageImpl::OnWizardBack](#onwizardback)|Chamado pelo framework quando o usuário clica o **volta** botão durante o uso de uma folha de propriedades de tipo de assistente.|
|[CSnapInPropertyPageImpl::OnWizardFinish](#onwizardfinish)|Chamado pelo framework quando o usuário clica o **concluir** botão durante o uso de uma folha de propriedades de tipo de assistente.|
|[CSnapInPropertyPageImpl::OnWizardNext](#onwizardnext)|Chamado pelo framework quando o usuário clica o **próxima** botão durante o uso de uma folha de propriedades de tipo de assistente.|
|[CSnapInPropertyPageImpl::QuerySiblings](#querysiblings)|Encaminha a mensagem atual para todas as páginas de folha de propriedades.|
|[CSnapInPropertyPageImpl::SetModified](#setmodified)|Chamada para ativar ou desativar o **aplicar agora** botão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInPropertyPageImpl::m_psp](#m_psp)|O Windows `PROPSHEETPAGE` estrutura usada pelo `CSnapInPropertyPageImpl` objeto.|

## <a name="remarks"></a>Comentários

`CSnapInPropertyPageImpl` Fornece uma implementação básica para um objeto de página de propriedade do snap-in. Os recursos básicos de uma página de propriedades do snap-in são implementados usando várias interfaces diferentes e mapeiam tipos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDialogImplBase`

`CSnapInPropertyPageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap.h

##  <a name="canceltoclose"></a>  CSnapInPropertyPageImpl::CancelToClose

Chame essa função após uma alteração irrecuperável foi feita para os dados em uma página de uma folha de propriedades modais.

```
void CancelToClose();
```

### <a name="remarks"></a>Comentários

Essa função será alterado de **Okey** botão **fechar** e desabilitar o **Cancelar** botão. Essa alteração não é possível cancelar o usuário que uma alteração é permanente e as modificações de alertas.

O `CancelToClose` função de membro não faz nada em uma folha de propriedades sem janela restrita, porque uma folha de propriedades sem janela restrita não tem um **Cancelar** botão por padrão.

##  <a name="csnapinpropertypageimpl"></a>  CSnapInPropertyPageImpl::CSnapInPropertyPageImpl

Constrói um objeto `CSnapInPropertyPageImpl`.

```
CSnapInPropertyPageImpl(LPCTSTR lpszTitle = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
[in] O título da página de propriedades.

### <a name="remarks"></a>Comentários

Para inicializar a estrutura subjacente, chame [CSnapInPropertyPageImpl::Create](#create).

##  <a name="create"></a>  CSnapInPropertyPageImpl::Create

Chame essa função para inicializar a estrutura subjacente da página de propriedades.

```
HPROPSHEETPAGE Create();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para um `PROPSHEETPAGE` estrutura que contém os atributos de folha de propriedade recém-criada.

### <a name="remarks"></a>Comentários

Você deve primeiro chamar [CSnapInPropertyPageImpl::CSnapInPropertyPageImpl](#csnapinpropertypageimpl) antes de chamar essa função.

##  <a name="m_psp"></a>  CSnapInPropertyPageImpl::m_psp

`m_psp` é uma estrutura cujos membros armazenam as características de `PROPSHEETPAGE`.

```
PROPSHEETPAGE m_psp;
```

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência de uma página de propriedades, depois que ele é construído.

Para obter mais informações sobre essa estrutura, incluindo uma lista de seus membros, consulte [PROPSHEETPAGE](/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v3) no SDK do Windows.

##  <a name="onapply"></a>  CSnapInPropertyPageImpl::OnApply

Essa função de membro é chamada quando o usuário clica o **Okey** ou o **aplicar agora** botão.

```
BOOL OnApply();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as alterações sejam aceitas; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Antes de `OnApply` pode ser chamado pelo framework, você deve ter chamado `SetModified` e defina seu parâmetro como TRUE. Isso ativará o **aplicar agora** botão assim que o usuário faz uma alteração na página de propriedades.

Substituir essa função de membro para especificar a ação que seu programa usa quando o usuário clica o **aplicar agora** botão. Durante a substituição, a função deve retornar TRUE para aceitar as alterações e FALSE para impedir que as alterações entrarem em vigor.

A implementação padrão de `OnApply` retorna TRUE.

##  <a name="onhelp"></a>  CSnapInPropertyPageImpl::OnHelp

Essa função de membro é chamada quando o usuário clica o **ajudar** botão da página de propriedades.

```
void OnHelp();
```

### <a name="remarks"></a>Comentários

Substitua essa função de membro para exibir a Ajuda para a página de propriedades.

##  <a name="onkillactive"></a>  CSnapInPropertyPageImpl::OnKillActive

Essa função membro é chamada quando a página não é mais a página ativa.

```
BOOL OnKillActive();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se dados foram atualizados com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas de validação de dados especiais.

##  <a name="onquerycancel"></a>  CSnapInPropertyPageImpl::OnQueryCancel

Essa função de membro é chamada quando o usuário clica o **Cancelar** botão e antes de cancelar a ação tiver sido feita.

```
BOOL OnQueryCancel();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero para permitir que a operação de cancelamento; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para especificar uma ação que o programa usa quando o usuário clica o **Cancelar** botão.

A implementação padrão de `OnQueryCancel` retorna TRUE.

##  <a name="onreset"></a>  CSnapInPropertyPageImpl::OnReset

Essa função de membro é chamada quando o usuário clica o **Cancelar** botão.

```
void OnReset();
```

### <a name="remarks"></a>Comentários

Quando essa função é chamada, alterações para todas as páginas de propriedades que foram feitas quando o usuário clica anteriormente a **aplicar agora** botão são descartados e a folha de propriedades retém o foco.

Substituir essa função de membro para especificar qual ação o programa usa quando o usuário clica o **Cancelar** botão.

##  <a name="onsetactive"></a>  CSnapInPropertyPageImpl::OnSetActive

Essa função membro é chamada quando a página é escolhida pelo usuário e torna-se a página ativa.

```
BOOL OnSetActive();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a página foi definida com êxito ativa; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função de membro para executar tarefas quando uma página é ativada. Sua substituição dessa função de membro deve chamar a versão padrão antes de qualquer outro processamento é feito.

A implementação padrão retorna TRUE.

##  <a name="onwizardback"></a>  CSnapInPropertyPageImpl::OnWizardBack

Essa função de membro é chamada quando o usuário clica o **volta** botão em um assistente.

```
BOOL OnWizardBack();
```

### <a name="return-value"></a>Valor de retorno

- 0 para automaticamente ir para a página anterior.

- -1 para impedir que a página de alteração.

Para ir diretamente para uma página que não seja o próximo, retorne o identificador da caixa de diálogo a ser exibido.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para especificar uma ação que o usuário deve ser executada quando o **volta** botão é clicado.

##  <a name="onwizardfinish"></a>  CSnapInPropertyPageImpl::OnWizardFinish

Essa função de membro é chamada quando o usuário clica o **concluir** botão em um assistente.

```
BOOL OnWizardFinish();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de propriedades é destruída quando o assistente for concluído; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para especificar uma ação que o usuário deve ser executada quando o **concluir** botão é clicado.

##  <a name="onwizardnext"></a>  CSnapInPropertyPageImpl::OnWizardNext

Essa função de membro é chamada quando o usuário clica o **próxima** botão em um assistente.

```
BOOL OnWizardNext();
```

### <a name="return-value"></a>Valor de retorno

- 0 para automaticamente ir para a próxima página.

- -1 para impedir que a página de alteração.

Para ir diretamente para uma página que não seja o próximo, retorne o identificador da caixa de diálogo a ser exibido.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para especificar uma ação que o usuário deve ser executada quando o **próxima** botão é clicado.

##  <a name="querysiblings"></a>  CSnapInPropertyPageImpl::QuerySiblings

Chame essa função de membro para encaminhar uma mensagem para cada página na folha de propriedades.

```
LRESULT QuerySiblings(WPARAM wParam, LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
[in] Especifica informações adicionais de dependente de mensagem.

*lParam*<br/>
[in] Especifica informações adicionais de dependente de mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem não deve ser encaminhada para a próxima página de propriedade; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Se uma página retorna um valor diferente de zero, a folha de propriedades não envia a mensagem para as páginas subsequentes.

##  <a name="setmodified"></a>  CSnapInPropertyPageImpl::SetModified

Chame essa função de membro para habilitar ou desabilitar a **aplicar agora** botão, com base em se as configurações na página de propriedades devem ser aplicadas ao objeto apropriado externo.

```
void SetModified(BOOL bChanged = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bChanged*<br/>
[in] TRUE para indicar que as configurações de página de propriedade foram modificadas desde a última vez em que eles foram aplicados; FALSE para indicar que as configurações de página de propriedade foram aplicadas, ou devem ser ignoradas.

### <a name="remarks"></a>Comentários

A folha de propriedades mantém o controle de quais páginas estão "sujas", ou seja, as páginas de propriedades para o qual você chamou `SetModified( TRUE )`. O **aplicar agora** botão sempre será habilitado se você chamar `SetModified( TRUE )` para uma das páginas. O **aplicar agora** botão será desabilitado quando você chama `SetModified( FALSE )` para uma das páginas, mas apenas se nenhuma das outras páginas é "suja".

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
