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
ms.openlocfilehash: 9e22184a4081762a3d505645752e514315146981
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318447"
---
# <a name="csettingsstoresp-class"></a>Classe CSettingsStoreSP

A `CSettingsStoreSP` classe é uma classe auxiliar que você pode usar para criar instâncias da [Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

## <a name="syntax"></a>Sintaxe

```
class CSettingsStoreSP
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStoreSP::CSettingsStoreSP](#csettingsstoresp)|Constrói um objeto `CSettingsStoreSP`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSettingsStoreSP::Criar](#create)|Cria uma instância de uma classe `CSettingsStore`derivada de .|
|[CSettingsStoreSP::SetRuntimeClass](#setruntimeclass)|Define a aula de tempo de execução. O `Create` método usa a classe de tempo de execução para determinar qual classe de objetos criar.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|`m_dwUserData`|Dados personalizados do usuário `CSettingsStoreSP` armazenados no objeto. Você fornece esses dados no `CSettingsStoreSP` construtor do objeto.|
|`m_pRegistry`|O `CSettingsStore`objeto derivado que `Create` o método cria.|

## <a name="remarks"></a>Comentários

Você pode `CSettingsStoreSP` usar a classe para redirecionar todas as operações de registro de MFC para outros locais, como um arquivo XML ou um banco de dados. Para fazer isso, siga estas etapas:

1. Crie uma classe `CMyStore`(como) e `CSettingsStore`a obtenha de .

1. Use [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate) e [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate) macros com sua classe personalizada `CSettingsStore` para permitir a criação dinâmica.

1. Anular as funções virtuais `Read` e `Write` implementar as funções e funções em sua classe personalizada. Implemente qualquer outra funcionalidade para ler e gravar dados no local desejado.

1. Em sua aplicação, ligue `CSettingsStoreSP::SetRuntimeClass` e passe um ponteiro para a Estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) obtida da sua classe.

Sempre que a estrutura normalmente acessar o registro, ele agora instanciará sua classe personalizada e a usará para ler ou gravar dados.

`CSettingsStoreSP::SetRuntimeClass`usa uma variável estática global. Portanto, apenas uma loja personalizada está disponível por vez.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsettingsstore.h

## <a name="csettingsstorespcreate"></a><a name="create"></a>CSettingsStoreSP::Criar

Cria uma nova instância de um objeto derivado da [Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

```
CSettingsStore& CSettingsStoreSP Create(
    BOOL bAdmin,
    BOOL bReadOnly);
```

### <a name="parameters"></a>Parâmetros

*Badmin*<br/>
[em] Um parâmetro booleano que `CSettingsStore` determina se um objeto é criado no modo administrador.

*bReadOnly*<br/>
[em] Um parâmetro booleano que `CSettingsStore` determina se um objeto é criado para acesso somente à leitura.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto `CSettingsStore` recém-criado.

### <a name="remarks"></a>Comentários

Você pode usar o método [CSettingsStoreSP::SetRuntimeClass](#setruntimeclass) `CSettingsStoreSP::Create` para determinar que tipo de objeto criará. Por padrão, este `CSettingsStore` método cria um objeto.

Se você `CSettingsStore` criar um objeto no modo administrador, o local padrão para todo acesso ao registro será HKEY_LOCAL_MACHINE. Caso contrário, o local padrão para todo acesso ao registro é HKEY_CURRENT_USER.

Se *bAdmin* for TRUE, o aplicativo deve ter direitos de administração. Caso contrário, falhará quando tentar acessar o registro.

### <a name="example"></a>Exemplo

O exemplo a seguir `Create` demonstra como `CSettingsStoreSP` usar o método da classe.

[!code-cpp[NVC_MFC_RibbonApp#33](../../mfc/reference/codesnippet/cpp/csettingsstoresp-class_1.cpp)]

## <a name="csettingsstorespcsettingsstoresp"></a><a name="csettingsstoresp"></a>CSettingsStoreSP::CSettingsStoreSP

Constrói um objeto [CSettingsStoreSP Class.](../../mfc/reference/csettingsstoresp-class.md)

```
CSettingsStoreSP::CSettingsStoreSP(DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*dwUserData*<br/>
[em] Dados definidos pelo `CSettingsStoreSP` usuário que o objeto armazena.

### <a name="remarks"></a>Comentários

O `CSettingsStoreSP` objeto armazena os dados do *dwUserData* na variável `m_dwUserData`membro protegido .

## <a name="csettingsstorespsetruntimeclass"></a><a name="setruntimeclass"></a>CSettingsStoreSP::SetRuntimeClass

Define a aula de tempo de execução. O método [CSettingsStoreSP::Create](#create) usa a classe de tempo de execução para determinar que tipo de objeto criar.

```
static BOOL __stdcall CSettingsStoreSP::SetRuntimeClass(CRuntimeClass* pRTI);
```

### <a name="parameters"></a>Parâmetros

*pRTI*<br/>
[em] Um ponteiro para as informações da classe de tempo de execução para uma classe derivada da [Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md).

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; FALSO se a classe identificada pelo *pRTI* não for derivada de `CSettingsStore`.

### <a name="remarks"></a>Comentários

Você pode usar a [classe CSettingsStoreSP](../../mfc/reference/csettingsstoresp-class.md) para obter classes de `CSettingsStore`. Use o `SetRuntimeClass` método se quiser criar objetos de uma `CSettingsStore`classe personalizada derivadas de .

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md)
