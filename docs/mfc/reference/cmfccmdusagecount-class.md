---
title: Classe CMFCCmdUsageCount
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
ms.openlocfilehash: 15026746f2af55b9cc153cce19cf00475e5c5d77
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561096"
---
# <a name="cmfccmdusagecount-class"></a>Classe CMFCCmdUsageCount

Controla a contagem de uso de mensagens do Windows, como quando o usuário seleciona um item em um menu.

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
|[CMFCCmdUsageCount::AddCmd](#addcmd)|Incrementa por um contador que está associado ao comando fornecido.|
|[CMFCCmdUsageCount:: GetCount](#getcount)|Recupera a contagem de uso associada à ID de comando fornecida.|
|[CMFCCmdUsageCount::HasEnoughInformation](#hasenoughinformation)|Determina se este objeto coletou a quantidade mínima de dados de controle.|
|[CMFCCmdUsageCount::IsFreqeuntlyUsedCmd](#isfreqeuntlyusedcmd)|Determina se o comando fornecido é usado com frequência.|
|[CMFCCmdUsageCount:: Reset](#reset)|Limpa a contagem de uso de todos os comandos.|
|[CMFCCmdUsageCount:: Serialize](#serialize)|Lê este objeto de um arquivo ou grava-o em um arquivo morto. (Substitui [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CMFCCmdUsageCount:: SetOptions](#setoptions)|Define os valores dos `CMFCCmdUsageCount` membros de dados da classe compartilhada.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|`m_CmdUsage`|Um `CMap` objeto que mapeia os comandos para suas contagens de uso.|
|`m_nMinUsagePercentage`|A porcentagem mínima de uso de um comando a ser usado com frequência.|
|`m_nStartCount`|O contador de início que é usado para determinar se esse objeto coletou a quantidade mínima de dados de controle.|
|`m_nTotalUsage`|A contagem de todos os comandos rastreados.|

### <a name="remarks"></a>Comentários

A `CMFCCmdUsageCount` classe mapeia cada identificador numérico de mensagem do Windows para um contador de inteiros sem sinal de 32 bits. `CMFCToolBar` usa essa classe para exibir itens de barra de ferramentas usados com frequência. Para obter mais informações sobre `CMFCToolBar` , consulte [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).

Você pode manter `CMFCCmdUsageCount` os dados de classe entre as execuções do seu programa. Use o método [CMFCCmdUsageCount:: Serialize](#serialize) para serializar dados de membros de classe e o método [CMFCCmdUsageCount:: SetOptions](#setoptions) para definir dados de membro compartilhado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCCmdUsageCount](../../mfc/reference/cmfccmdusagecount-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmdusagecount. h

## <a name="cmfccmdusagecountaddcmd"></a><a name="addcmd"></a> CMFCCmdUsageCount::AddCmd

Incrementa por um contador que está associado ao comando fornecido.

```cpp
void AddCmd(UINT uiCmd);
```

### <a name="parameters"></a>parâmetros

*uiCmd*\
no Especifica o contador de comando a ser incrementado.

### <a name="remarks"></a>Comentários

Esse método adiciona uma nova entrada à estrutura de mapa de contagens de comando, `m_CmdUsage` , se a entrada ainda não existir.

Esse método não faz nada nos seguintes casos:

- A estrutura da barra de ferramentas está no modo de personalização (o método [CMFCToolBar:: Iscustommode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode) retorna um valor diferente de zero).

- O comando refere-se a um submenu ou separador de menus ( *uiCmd* é igual a 0 ou-1).

- *uiCmd* refere-se a um comando padrão (a `IsStandardCommand` função global retorna um valor diferente de zero).

## <a name="cmfccmdusagecountgetcount"></a><a name="getcount"></a> CMFCCmdUsageCount:: GetCount

Recupera a contagem de uso associada à ID de comando fornecida.

```
UINT GetCount(UINT uiCmd) const;
```

### <a name="parameters"></a>parâmetros

*uiCmd*\
no A ID do contador de comando a ser recuperado.

### <a name="return-value"></a>Valor retornado

A contagem de uso associada à ID de comando fornecida.

## <a name="cmfccmdusagecounthasenoughinformation"></a><a name="hasenoughinformation"></a> CMFCCmdUsageCount::HasEnoughInformation

Determina se este objeto recebeu a quantidade mínima de dados de controle.

```
BOOL HasEnoughInformation() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se esse objeto tiver recebido a quantidade mínima de dados de controle; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método retornará um valor diferente de zero se a contagem total, `m_nTotalUsage` , de todos os comandos acompanhados for igual ou maior que a contagem inicial, `m_nStartCount` . Por padrão, a estrutura define a contagem inicial 0. Você pode substituir esse valor usando o método [CMFCCmdUsageCount:: SetOptions](#setoptions) .

Esse método é usado por [CMFCMenuBar:: IsShowAllCommands](../../mfc/reference/cmfcmenubar-class.md#isshowallcommands) para determinar se todos os comandos de menu disponíveis devem ser mostrados.

## <a name="cmfccmdusagecountisfreqeuntlyusedcmd"></a><a name="isfreqeuntlyusedcmd"></a> CMFCCmdUsageCount::IsFreqeuntlyUsedCmd

Determina se o comando fornecido é usado com frequência.

```
BOOL IsFreqeuntlyUsedCmd(UINT uiCmd) const;
```

### <a name="parameters"></a>parâmetros

*uiCmd*\
no Especifica o comando a ser verificado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o comando for usado com frequência; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método retornará 0 se o uso total do comando `m_nTotalUsage` for 0. Caso contrário, esse método retornará zero se a porcentagem da qual o comando especificado for usado for maior que a porcentagem mínima, `m_nMinUsagePercentage` . Por padrão, a estrutura define o percentual mínimo como 5. Você pode substituir esse valor usando o método [CMFCCmdUsageCount:: SetOptions](#setoptions) . Se o percentual mínimo for 0, esse método retornará zero se a contagem de comandos especificada for maior que 0.

[CMFCToolBar:: IsCommandRarelyUsed](../../mfc/reference/cmfctoolbar-class.md#iscommandrarelyused) usa esse método para determinar se um comando raramente é usado.

## <a name="cmfccmdusagecountreset"></a><a name="reset"></a> CMFCCmdUsageCount:: Reset

Limpa a contagem de uso de todos os comandos.

```cpp
void Reset();
```

### <a name="remarks"></a>Comentários

Chame esse método para limpar todas as entradas da estrutura de mapa de contagens de comando, `m_CmdUsage` e para redefinir o uso do comando total, `m_nTotalUsage` , Counter para 0.

## <a name="cmfccmdusagecountserialize"></a><a name="serialize"></a> CMFCCmdUsageCount:: Serialize

Lê este objeto de um arquivo ou grava-o em um arquivo morto.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>parâmetros

*multi-hop*\
no Um `CArchive` objeto para serializar de ou para.

### <a name="remarks"></a>Comentários

Esse método serializa a estrutura de mapa de contagens de comando, `m_CmdUsage` e o uso de comando total, `m_nTotalUsage` , contador de ou para o arquivo especificado.

Para obter exemplos de serialização, consulte [serialização: Serializando um objeto](../../mfc/serialization-serializing-an-object.md).

## <a name="cmfccmdusagecountsetoptions"></a><a name="setoptions"></a> CMFCCmdUsageCount:: SetOptions

Define os valores dos `CMFCCmdUsageCount` membros de dados da classe compartilhada.

```
static BOOL __stdcall SetOptions(
    UINT nStartCount,
    UINT nMinUsagePercentage);
```

### <a name="parameters"></a>parâmetros

*nStartCount*\
no A nova contagem inicial de todos os comandos acompanhados.

*nMinUsagePercentage*\
no A nova porcentagem mínima de uso.

### <a name="return-value"></a>Valor retornado

TRUE se o método tiver sucesso, FALSE se o parâmetro *nMinUsagePercentage* for maior ou igual a 100.

### <a name="remarks"></a>Comentários

Esse método define os `CMFCCmdUsageCount` membros de dados da classe compartilhada `m_nStartCount` e `m_nMinUsagePercentage` como *nStartCount* e *nMinUsagePercentage*, respectivamente. `m_nStartCount` é usado pelo método [CMFCCmdUsageCount:: HasEnoughInformation](#hasenoughinformation) para determinar se esse objeto coletou a quantidade mínima de dados de controle. `m_nMinUsagePercentage` é usado pelo método [CMFCCmdUsageCount:: IsFreqeuntlyUsedCmd](#isfreqeuntlyusedcmd) para determinar se um determinado comando é usado com frequência.

Em Depurar compilações esse método gerará uma falha de asserção se o parâmetro *nMinUsagePercentage* for maior ou igual a 100.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
