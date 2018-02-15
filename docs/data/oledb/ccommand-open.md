---
title: 'Ccommand:: Open | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CCommand.Open
- ATL::CCommand::Open
- CCommand.Open
- CCommand::Open
dev_langs:
- C++
helpviewer_keywords:
- Open method
ms.assetid: 4c9b8f31-faf3-452d-9a29-3d3e5f54d6f8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1a58dc67735a4f236c79ff6c777a4510dfdfcd12
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ccommandopen"></a>CCommand::Open
Executa e, opcionalmente, associa o comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(const CSession& session,  
   LPCWSTR wszCommand,  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   REFGUID guidCommand = DBGUID_DEFAULT,  
   bool bBind = true,  
   ULONG ulPropSets = 0) throw();  


HRESULT Open(const CSession& session,  
   LPCSTR szCommand,  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   REFGUID guidCommand = DBGUID_DEFAULT,  
   bool bBind = true,  
   ULONG ulPropSets = 0) throw();  


HRESULT Open(const CSession& session,  
   INT szCommand = NULL,  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   REFGUID guidCommand = DBGUID_DEFAULT,  
   bool bBind = true,  
   ULONG ulPropSets = 0) throw();  


HRESULT Open(DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   bool bBind = true,  
   ULONG ulPropSets = 0) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `session`  
 [in] A sessão na qual executar o comando.  
  
 `wszCommand`  
 [in] O comando a ser executado, passado como uma cadeia de caracteres Unicode. Pode ser **nulo** ao usar `CAccessor`, caso em que o comando será recuperado do valor passado para o [DEFINE_COMMAND](../../data/oledb/define-command.md) macro. Consulte [ICommand:: execute](https://msdn.microsoft.com/en-us/library/ms718095.aspx) no *referência do programador de DB OLE* para obter detalhes.  
  
 `szCommand`  
 [in] Mesmo que `wszCommand` exceto que esse parâmetro usa uma cadeia de caracteres de comando ANSI. O quarto formulário desse método pode levar um valor nulo. Consulte "Comentários" posteriormente neste tópico para obter detalhes.  
  
 *pPropSet*  
 [in] Um ponteiro para uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas contendo propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx) no *referência do programador de OLE DB* no SDK do Windows.  
  
 `pRowsAffected`  
 [entrada/saída] Um ponteiro de memória em que a contagem de linhas afetadas por um comando é retornada. Se  *\*pRowsAffected* é **nulo**, sem contagem de linha é retornada. Caso contrário, **abrir** define *`pRowsAffected` acordo com as seguintes condições:  
  
|If|Then|  
|--------|----------|  
|O **cParamSets** elemento de `pParams` é maior que 1|*`pRowsAffected` representa o número total de linhas afetadas por todos os conjuntos de parâmetros especificados na execução.|  
|O número de linhas afetadas não está disponível|*`pRowsAffected` é definido como -1.|  
|O comando não atualizar, excluir ou inserir linhas|*`pRowsAffected` é indefinido.|  
  
 `guidCommand`  
 [in] Um GUID que especifica a sintaxe e regras gerais para o provedor a ser usado na análise do texto de comando. Consulte [ICommandText::GetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx) e [ICommandText:: SetCommandText](https://msdn.microsoft.com/en-us/library/ms709757.aspx) no *referência do programador de DB OLE* para obter detalhes.  
  
 `bBind`  
 [in] Especifica se deve associar o comando automaticamente depois que está sendo executada. O padrão é **true**, que faz com que o comando a ser associado automaticamente. Configuração `bBind` para **false** impede que a associação automática do comando de modo que você pode vincular manualmente. (Associação manual é de especial interesse para os usuários OLAP).  
  
 `ulPropSets`  
 [in] O número de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas passado a *pPropSet* argumento.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Os primeiros três formulários de **abrir** levar a uma sessão, crie um comando e execute o comando, todos os parâmetros de associação conforme necessário.  
  
 O primeiro formulário da **abrir** utiliza uma cadeia de caracteres de comando Unicode e não tem nenhum valor padrão.  
  
 A segunda forma de **abrir** usa uma cadeia de caracteres de comando ANSI e nenhum valor padrão (fornecido para compatibilidade com aplicativos existentes de ANSI).  
  
 O terceiro formulário de **abrir** permite que a cadeia de caracteres de comando como NULL, devido ao tipo `int` com um valor padrão de NULL. Ele é fornecido para chamar `Open(session, NULL);` ou `Open(session);` porque nulo é do tipo `int`. Esta versão requer e declara que o `int` parâmetro ser NULL.  
  
 Use o formulário quarto de **abrir** quando você já tiver criado um comando e você deseja executar um único [preparar](../../data/oledb/ccommand-prepare.md) e várias execuções.  
  
> [!NOTE]
>  **Abra** chamadas **Execute**, que por sua vez chama `GetNextResult`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)