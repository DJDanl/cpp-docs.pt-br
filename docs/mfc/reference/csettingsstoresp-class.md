---
title: Classe CSettingsStoreSP
ms.date: 11/04/2016
f1_keywords:
- CSettingsStoreSP
- AFXSETTINGSSTORE/CSettingsStoreSP
- AFXSETTINGSSTORE/CSettingsStoreSP::CSettingsStoreSP
- AFXSETTINGSSTORE/CSettingsStoreSP::Create
- AFXSETTINGSSTORE/CSettingsStoreSP::SetRuntimeClass
helpviewer_keywords:
- CSettingsStoreSP [MFC], CSettingsStoreSP
- CSettingsStoreSP [MFC], Create
- CSettingsStoreSP [MFC], SetRuntimeClass
ms.assetid: bcd37f40-cfd4-4d17-a5ce-3bfabe995dcc
ms.openlocfilehash: f6bcbce291aec1941359504518e26ca936edb9e7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604471"
---
# <a name="csettingsstoresp-class"></a>Classe CSettingsStoreSP

O `CSettingsStoreSP` é uma classe auxiliar que você pode usar para criar instâncias do [classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

## <a name="syntax"></a>Sintaxe

```
class CSettingsStoreSP
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStoreSP::CSettingsStoreSP](#csettingsstoresp)|Constrói um objeto `CSettingsStoreSP`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStoreSP::Create](#create)|Cria uma instância de uma classe que é derivada de `CSettingsStore`.|
|[CSettingsStoreSP::SetRuntimeClass](#setruntimeclass)|Define a classe de tempo de execução. O `Create` método usa a classe de tempo de execução para determinar qual classe de objetos para criar.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|`m_dwUserData`|Dados de usuário personalizada que são armazenados no `CSettingsStoreSP` objeto. Você fornecer esses dados no construtor do `CSettingsStoreSP` objeto.|
|`m_pRegistry`|O `CSettingsStore`-derivados do objeto que o `Create` método cria.|

## <a name="remarks"></a>Comentários

Você pode usar o `CSettingsStoreSP` classe para redirecionar todas as operações de registro do MFC para outros locais, como um arquivo XML ou um banco de dados. Para fazer isso, execute estas etapas:

1. Criar uma classe (como `CMyStore`) e derive-a da `CSettingsStore`.

1. Use [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate) e [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate) macros com seu personalizado `CSettingsStore` classe para permitir a criação dinâmica.

1. Substituir funções virtuais e implementar o `Read` e `Write` funções na sua classe personalizada. Implemente qualquer outra funcionalidade para ler e gravar dados em seu local desejado.

1. Em seu aplicativo, chame `CSettingsStoreSP::SetRuntimeClass` e passe um ponteiro para o [estrutura CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) obtidas da sua classe.

Sempre que a estrutura acessaria normalmente o registro, ele agora dinamicamente instanciar sua classe personalizada e usá-lo para ler ou gravar dados.

`CSettingsStoreSP::SetRuntimeClass` usa uma variável estática global. Portanto, apenas um repositório personalizado está disponível por vez.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsettingsstore.h

##  <a name="create"></a>  CSettingsStoreSP::Create

Cria uma nova instância de um objeto que deriva de [classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

```
CSettingsStore& CSettingsStoreSP Create(
    BOOL bAdmin,
    BOOL bReadOnly);
```

### <a name="parameters"></a>Parâmetros

*bCaminho Admin*<br/>
[in] Um parâmetro booliano que determina se um `CSettingsStore` objeto é criado no modo de administrador.

*bReadOnly*<br/>
[in] Um parâmetro booliano que determina se um `CSettingsStore` objeto é criado para acesso somente leitura.

### <a name="return-value"></a>Valor de retorno

Uma referência ao recém-criado `CSettingsStore` objeto.

### <a name="remarks"></a>Comentários

Você pode usar o método [CSettingsStoreSP::SetRuntimeClass](#setruntimeclass) para determinar que tipo de objeto `CSettingsStoreSP::Create` criará. Por padrão, esse método cria um `CSettingsStore` objeto.

Se você criar um `CSettingsStore` objeto no modo de administrador, o local padrão para todos os acessos do Registro HKEY_LOCAL_MACHINE. Caso contrário, o local padrão para todos os acessos do registro é HKEY_CURRENT_USER.

Se *bCaminho Admin* for TRUE, o aplicativo deve ter direitos de administração. Caso contrário, ele falhará ao tentar acessar o registro.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `Create` método da `CSettingsStoreSP` classe.

[!code-cpp[NVC_MFC_RibbonApp#33](../../mfc/reference/codesnippet/cpp/csettingsstoresp-class_1.cpp)]

##  <a name="csettingsstoresp"></a>  CSettingsStoreSP::CSettingsStoreSP

Constrói uma [classe CSettingsStoreSP](../../mfc/reference/csettingsstoresp-class.md) objeto.

```
CSettingsStoreSP::CSettingsStoreSP(DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*dwUserData*<br/>
[in] Dados definidos pelo usuário que o `CSettingsStoreSP` armazenamentos do objeto.

### <a name="remarks"></a>Comentários

O `CSettingsStoreSP` objeto armazena os dados do *dwUserData* na variável de membro protegida `m_dwUserData`.

##  <a name="setruntimeclass"></a>  CSettingsStoreSP::SetRuntimeClass

Define a classe de tempo de execução. O método [CSettingsStoreSP::Create](#create) usa a classe de tempo de execução para determinar que tipo de objeto a ser criado.

```
static BOOL __stdcall CSettingsStoreSP::SetRuntimeClass(CRuntimeClass* pRTI);
```

### <a name="parameters"></a>Parâmetros

*pRTI*<br/>
[in] Um ponteiro para as informações de classe de tempo de execução para uma classe derivada do [classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; FALSE se a classe identificada por *pRTI* não é derivado de `CSettingsStore`.

### <a name="remarks"></a>Comentários

Você pode usar o [classe CSettingsStoreSP](../../mfc/reference/csettingsstoresp-class.md) derivar classes de `CSettingsStore`. Use o método `SetRuntimeClass` se você deseja criar objetos de uma classe personalizada derivada de `CSettingsStore`.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md)
