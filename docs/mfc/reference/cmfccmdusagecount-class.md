---
title: Classe CMFCCmdUsageCount | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CMFCCmdUsageCount [MFC], AddCmd
- CMFCCmdUsageCount [MFC], GetCount
- CMFCCmdUsageCount [MFC], HasEnoughInformation
- CMFCCmdUsageCount [MFC], IsFreqeuntlyUsedCmd
- CMFCCmdUsageCount [MFC], Reset
- CMFCCmdUsageCount [MFC], Serialize
- CMFCCmdUsageCount [MFC], SetOptions
ms.assetid: 9c33b783-37c0-43ea-9f31-3c75e246c841
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a5b4824632d7ce38e50859172a24a47bdeb49f1d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfccmdusagecount-class"></a>Classe CMFCCmdUsageCount
Rastreia a contagem de uso de mensagens do Windows, como quando o usuário seleciona um item em um menu.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCCmdUsageCount : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCmdUsageCount::CMFCCmdUsageCount`|Construtor padrão.|  
|`CMFCCmdUsageCount::~CMFCCmdUsageCount`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCCmdUsageCount::AddCmd](#addcmd)|Aumenta em incrementos de um, o contador que está associado com o comando fornecido.|  
|[CMFCCmdUsageCount::GetCount](#getcount)|Recupera a contagem de uso que está associada com a ID de comando especificada.|  
|[CMFCCmdUsageCount::HasEnoughInformation](#hasenoughinformation)|Determina se este objeto coletou a quantidade mínima de dados de rastreamento.|  
|[CMFCCmdUsageCount::IsFreqeuntlyUsedCmd](#isfreqeuntlyusedcmd)|Determina se o comando fornecido é usado com frequência.|  
|[CMFCCmdUsageCount::Reset](#reset)|Limpa a contagem de uso de todos os comandos.|  
|[CMFCCmdUsageCount::Serialize](#serialize)|Lê esse objeto de um arquivo ou grava em um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|  
|[CMFCCmdUsageCount::SetOptions](#setoptions)|Define os valores de compartilhado `CMFCCmdUsageCount` classe membros de dados.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|`m_CmdUsage`|Um `CMap` objeto que mapeia os comandos para suas contagens de uso.|  
|`m_nMinUsagePercentage`|A porcentagem de uso mínimo de um comando a ser usado com frequência.|  
|`m_nStartCount`|O contador de início é usado para determinar se este objeto coletou a quantidade mínima de dados de rastreamento.|  
|`m_nTotalUsage`|A contagem de comandos todos rastreados.|  
  
### <a name="remarks"></a>Comentários  
 O `CMFCCmdUsageCount` classe mapeia cada identificador numérico de mensagem do Windows para um contador de inteiro não assinado de 32 bits. `CMFCToolBar` usa essa classe para exibir os itens da barra de ferramentas usados com frequência. Para obter mais informações sobre `CMFCToolBar`, consulte [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md).  
  
 Você pode persistir `CMFCCmdUsageCount` classe dados entre as execuções do programa. Use o [CMFCCmdUsageCount::Serialize](#serialize) método para serializar os dados de membro de classe e o [CMFCCmdUsageCount::SetOptions](#setoptions) método para definir os dados de membro compartilhado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCCmdUsageCount](../../mfc/reference/cmfccmdusagecount-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmdusagecount.h  
  
##  <a name="addcmd"></a>  CMFCCmdUsageCount::AddCmd  
 Aumenta em incrementos de um, o contador que está associado com o comando fornecido.  
  
```  
void AddCmd(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `uiCmd`|Especifica o contador de comando para incrementar.|  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona uma nova entrada para a estrutura do mapa de contagens de comando, `m_CmdUsage`, se a entrada ainda não existir.  
  
 Esse método não fará nada nos seguintes casos:  
  
-   A estrutura da barra de ferramentas está no modo de personalização (o [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode) método retorna um valor diferente de zero).  
  
-   O comando se refere a um separador de menu ou submenu ( `uiCmd` igual a 0 ou -1).  
  
- `uiCmd` refere-se a um comando padrão (global `IsStandardCommand` função retorna um valor diferente de zero).  
  
##  <a name="getcount"></a>  CMFCCmdUsageCount::GetCount  
 Recupera a contagem de uso que está associada com a ID de comando especificada.  
  
```  
UINT GetCount(UINT uiCmd) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `uiCmd`|A ID do contador de comando para recuperar.|  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de uso que está associada com a ID de comando especificada.  
  
##  <a name="hasenoughinformation"></a>  CMFCCmdUsageCount::HasEnoughInformation  
 Determina se este objeto recebeu a quantidade mínima de dados de rastreamento.  
  
```  
BOOL HasEnoughInformation() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se esse objeto tiver recebido a quantidade mínima de rastreamento de dados. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna um valor diferente de zero se a contagem total, `m_nTotalUsage`, controladas todos os comandos é igual ou maior do que a contagem inicial, `m_nStartCount`. Por padrão, a estrutura define a contagem inicial de 0. Você pode substituir esse valor usando o [CMFCCmdUsageCount::SetOptions](#setoptions) método.  
  
 Esse método é usado por [CMFCMenuBar::IsShowAllCommands](../../mfc/reference/cmfcmenubar-class.md#isshowallcommands) para determinar se deve mostrar todos os comandos de menu disponíveis.  
  
##  <a name="isfreqeuntlyusedcmd"></a>  CMFCCmdUsageCount::IsFreqeuntlyUsedCmd  
 Determina se o comando fornecido é usado com frequência.  
  
```  
BOOL IsFreqeuntlyUsedCmd(UINT uiCmd) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `uiCmd`|Especifica o comando para verificar.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando é usado com frequência; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retornará 0 se o uso do comando total, `m_nTotalUsage`, é 0. Caso contrário, esse método retornará zero se a porcentagem que é usado o comando especificado é maior do que a porcentagem mínima, `m_nMinUsagePercentage`. Por padrão, a estrutura define a porcentagem mínima para 5. Você pode substituir esse valor usando o [CMFCCmdUsageCount::SetOptions](#setoptions) método. Se o percentual mínimo é 0, esse método retornará nulo se a contagem de comando especificado é maior que 0.  
  
 [CMFCToolBar::IsCommandRarelyUsed](../../mfc/reference/cmfctoolbar-class.md#iscommandrarelyused) usa esse método para determinar se um comando raramente é utilizado.  
  
##  <a name="reset"></a>  CMFCCmdUsageCount::Reset  
 Limpa a contagem de uso de todos os comandos.  
  
```  
void Reset();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para limpar todas as entradas da estrutura de mapa de contagens de comando, `m_CmdUsage`e redefinir o uso do comando total, `m_nTotalUsage`, contador como 0.  
  
##  <a name="serialize"></a>  CMFCCmdUsageCount::Serialize  
 Lê esse objeto de um arquivo morto ou grava em um arquivo morto.  
  
```  
virtual void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `ar`|Um `CArchive` objeto a ser serializado de ou para.|  
  
### <a name="remarks"></a>Comentários  
 Esse método serializa a estrutura do mapa de contagens de comando, `m_CmdUsage`e o uso do comando total, `m_nTotalUsage`, contador de ou para o arquivo especificado.  
  
 Para obter exemplos de serialização, consulte [serialização: serializando um objeto](../../mfc/serialization-serializing-an-object.md).  
  
##  <a name="setoptions"></a>  CMFCCmdUsageCount::SetOptions  
 Define os valores de compartilhado `CMFCCmdUsageCount` classe membros de dados.  
  
```  
static BOOL __stdcall SetOptions(
    UINT nStartCount,  
    UINT nMinUsagePercentage);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `nStartCount`|A nova contagem inicial de controladas todos os comandos.|  
|[in] `nMinUsagePercentage`|A porcentagem de uso mínimo de novo.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método for bem-sucedido, `FALSE` se o `nMinUsagePercentage` parâmetro seja maior ou igual a 100.  
  
### <a name="remarks"></a>Comentários  
 Esse método define compartilhado `CMFCCmdUsageCount` membros de dados de classe `m_nStartCount` e `m_nMinUsagePercentage` para `nStartCount` e `nMinUsagePercentage`, respectivamente. `m_nStartCount` é usado pelo [CMFCCmdUsageCount::HasEnoughInformation](#hasenoughinformation) método para determinar se este objeto coletou a quantidade mínima de dados de rastreamento. `m_nMinUsagePercentage` é usado pelo [CMFCCmdUsageCount::IsFreqeuntlyUsedCmd](#isfreqeuntlyusedcmd) método para determinar se um determinado comando é usado com frequência.  
  
 Em compilações de depuração este método gera uma falha de asserção se o `nMinUsagePercentage` parâmetro seja maior ou igual a 100.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
