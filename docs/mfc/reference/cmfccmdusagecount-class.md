---
title: CMFCCmdUsageCount Class
ms.date: 11/04/2016
f1_keywords:
- CMFCCmdUsageCount
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::AddCmd
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::GetCount
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::HasEnoughInformation
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::IsFreqeuntlyUsedCmd
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::Reset
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::Serialize
- AFXCMDUSAGECOUNT/CMFCCmdUsageCount::SetOptions
helpviewer_keywords:
- CMFCCmdUsageCount [MFC], AddCmd
- CMFCCmdUsageCount [MFC], GetCount
- CMFCCmdUsageCount [MFC], HasEnoughInformation
- CMFCCmdUsageCount [MFC], IsFreqeuntlyUsedCmd
- CMFCCmdUsageCount [MFC], Reset
- CMFCCmdUsageCount [MFC], Serialize
- CMFCCmdUsageCount [MFC], SetOptions
ms.assetid: 9c33b783-37c0-43ea-9f31-3c75e246c841
ms.openlocfilehash: 02b302ec38922128190a6f20ce2f156b52383b55
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752587"
---
# <a name="cmfccmdusagecount-class"></a>CMFCCmdUsageCount Class

Rastreia a contagem de uso de mensagens do Windows, como quando o usuário seleciona um item de um menu.

## <a name="syntax"></a>Sintaxe

```
class CMFCCmdUsageCount : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCCmdUsageCount::CMFCCmdUsageCount`|Construtor padrão.|
|`CMFCCmdUsageCount::~CMFCCmdUsageCount`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CONTAGEM de uso do CMFCCmd::AddCmd](#addcmd)|Incrementos por um o contador que está associado com o comando dado.|
|[CONTAGEM DE USO DO CMFCCmD::GetCount](#getcount)|Recupera a contagem de uso associada ao ID de comando dado.|
|[CMFCCmdUsecount::HasEnoughInformation](#hasenoughinformation)|Determina se esse objeto coletou a quantidade mínima de dados de rastreamento.|
|[CMFCCmdUsecount::IsFreqeuntlyUsedCmd](#isfreqeuntlyusedcmd)|Determina se o comando dado é usado com freqüência.|
|[CONTAGEM de uso do CMFCCmd::Redefinir](#reset)|Limpa a contagem de uso de todos os comandos.|
|[CMFCCmdUsecount::Serialize](#serialize)|Lê este objeto de um arquivo ou grava-o em um arquivo. (Substitui [cobject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CMFCCmdUseCount::SetOptions](#setoptions)|Define os valores `CMFCCmdUsageCount` dos membros de dados de classe compartilhada.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|`m_CmdUsage`|Um `CMap` objeto que mapeia comandos para suas contagens de uso.|
|`m_nMinUsagePercentage`|A porcentagem mínima de uso para um comando a ser usado com freqüência.|
|`m_nStartCount`|O contador de partida saqueado é usado para determinar se esse objeto coletou a quantidade mínima de dados de rastreamento.|
|`m_nTotalUsage`|A contagem de todos os comandos rastreados.|

### <a name="remarks"></a>Comentários

A `CMFCCmdUsageCount` classe mapeia cada identificador de mensagens numéricas do Windows para um contador inteiro não assinado de 32 bits. `CMFCToolBar`usa essa classe para exibir itens de barra de ferramentas usados com freqüência. Para obter `CMFCToolBar`mais informações sobre , consulte [CMFCToolBar Class](../../mfc/reference/cmfctoolbar-class.md).

Você pode `CMFCCmdUsageCount` persistir dados de classe entre as corridas do seu programa. Use o [método CMFCCmdUsageCount::Serialize](#serialize) para serializar dados de membros da classe e o [método CMFCCmdUsageCount::SetOptions](#setoptions) para definir dados de membros compartilhados.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfccmdusagecount](../../mfc/reference/cmfccmdusagecount-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmdusagecount.h

## <a name="cmfccmdusagecountaddcmd"></a><a name="addcmd"></a>CONTAGEM de uso do CMFCCmd::AddCmd

Incrementos por um o contador que está associado com o comando dado.

```cpp
void AddCmd(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Uicmd*|[em] Especifica o contador de comando satisume.|

### <a name="remarks"></a>Comentários

Este método adiciona uma nova entrada à `m_CmdUsage`estrutura do mapa de contagens de comando, se a entrada ainda não existir.

Este método não faz nada nos seguintes casos:

- A estrutura da barra de ferramentas está no modo de personalização (o método [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode) retorna um valor não zero).

- O comando refere-se a um submenu ou separador de menu *(uiCmd* é igual a 0 ou -1).

- *uiCmd* refere-se a um `IsStandardCommand` comando padrão (a função global retorna um valor não zero).

## <a name="cmfccmdusagecountgetcount"></a><a name="getcount"></a>CONTAGEM DE USO DO CMFCCmD::GetCount

Recupera a contagem de uso associada ao ID de comando dado.

```
UINT GetCount(UINT uiCmd) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Uicmd*|[em] A id do contador de comando para recuperar.|

### <a name="return-value"></a>Valor retornado

A contagem de uso que está associada com o iD de comando dado.

## <a name="cmfccmdusagecounthasenoughinformation"></a><a name="hasenoughinformation"></a>CMFCCmdUsecount::HasEnoughInformation

Determina se esse objeto recebeu a quantidade mínima de dados de rastreamento.

```
BOOL HasEnoughInformation() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se este objeto tiver recebido a quantidade mínima de dados de rastreamento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método retorna um valor não `m_nTotalUsage`zero se a contagem total, de todos os `m_nStartCount`comandos rastreados é igual ou maior do que a contagem inicial, . Por padrão, o quadro define a contagem inicial 0. Você pode substituir esse valor usando o método [CMFCCmdUsageCount::SetOptions.](#setoptions)

Este método é usado por [CMFCMenuBar::IsShowAllCommands](../../mfc/reference/cmfcmenubar-class.md#isshowallcommands) para determinar se deve mostrar todos os comandos de menu disponíveis.

## <a name="cmfccmdusagecountisfreqeuntlyusedcmd"></a><a name="isfreqeuntlyusedcmd"></a>CMFCCmdUsecount::IsFreqeuntlyUsedCmd

Determina se o comando dado é usado com freqüência.

```
BOOL IsFreqeuntlyUsedCmd(UINT uiCmd) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Uicmd*|[em] Especifica o comando a ser verificado.|

### <a name="return-value"></a>Valor retornado

Não zero se o comando for usado com freqüência; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método retorna 0 se `m_nTotalUsage`o uso total do comando, é 0. Caso contrário, este método retorna não zero se a porcentagem do qual o `m_nMinUsagePercentage`comando especificado é usado for maior que a porcentagem mínima, . Por padrão, o quadro define o percentual mínimo para 5. Você pode substituir esse valor usando o método [CMFCCmdUsageCount::SetOptions.](#setoptions) Se a porcentagem mínima for 0, este método retorna não zero se a contagem de comandoespecificada for maior que 0.

[CMFCToolBar::IsCommandRarelyUsed](../../mfc/reference/cmfctoolbar-class.md#iscommandrarelyused) usa este método para determinar se um comando raramente é usado.

## <a name="cmfccmdusagecountreset"></a><a name="reset"></a>CONTAGEM de uso do CMFCCmd::Redefinir

Limpa a contagem de uso de todos os comandos.

```cpp
void Reset();
```

### <a name="remarks"></a>Comentários

Chame este método para limpar todas as entradas `m_CmdUsage`da estrutura do mapa da `m_nTotalUsage`contagem de comandos, e para redefinir o uso total do comando, contra-atacar a 0.

## <a name="cmfccmdusagecountserialize"></a><a name="serialize"></a>CMFCCmdUsecount::Serialize

Lê este objeto de um arquivo ou grava-o em um arquivo.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*ar*|[em] Um `CArchive` objeto para serializar de ou para.|

### <a name="remarks"></a>Comentários

Este método serializa a estrutura do `m_CmdUsage`mapa das contagens de comando, e o uso total do comando, `m_nTotalUsage`contador de ou para o arquivo especificado.

Para exemplos de serialização, consulte [Serialização: Serializando um objeto](../../mfc/serialization-serializing-an-object.md).

## <a name="cmfccmdusagecountsetoptions"></a><a name="setoptions"></a>CMFCCmdUseCount::SetOptions

Define os valores `CMFCCmdUsageCount` dos membros de dados de classe compartilhada.

```
static BOOL __stdcall SetOptions(
    UINT nStartCount,
    UINT nMinUsagePercentage);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*nStartCount*|[em] A nova contagem inicial de todos os comandos rastreados.|
|*nMinUsagePercentage*|[em] A nova porcentagem mínima de uso.|

### <a name="return-value"></a>Valor retornado

TRUE se o método for bem sucedido, FALSE se o parâmetro *nMinUsagePercentage* for maior ou igual a 100.

### <a name="remarks"></a>Comentários

Este método define `CMFCCmdUsageCount` os membros `m_nStartCount` `m_nMinUsagePercentage` de dados de classe compartilhada e *o nStartCount* e *nMinUsagePercentage*, respectivamente. `m_nStartCount`é usado pelo [CMFCCmdUsageCount::HasEnoughInformation](#hasenoughinformation) method para determinar se esse objeto coletou a quantidade mínima de dados de rastreamento. `m_nMinUsagePercentage`é usado pelo [CMFCCmdUsageCount::IsFreqeuntlyUsedCmd](#isfreqeuntlyusedcmd) method para determinar se um determinado comando é usado com freqüência.

Em Compilações de depuração, este método gera uma falha de afirmação se o parâmetro *nMinUsagePercentage* for maior ou igual a 100.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
