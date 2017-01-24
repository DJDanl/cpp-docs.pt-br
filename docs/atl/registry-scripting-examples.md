---
title: "Exemplos de script do Registro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "scripts de escrivão [ATL]"
  - "registro, Escrivão"
  - "script, exemplos"
  - "scripts, Scripts de escrivão"
ms.assetid: b6df80e1-e08b-40ee-9243-9b381b172460
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplos de script do Registro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Exemplos de script em este tópico demonstram como adicionar uma chave do Registro do sistema, para registrar o servidor COM de escrivão, e para especificar várias analisar árvores.  
  
## Adicione uma a chave HKEY\_CURRENT\_USER  
 Os seguintes analisam a árvore ilustram um script simples que adiciona uma única chave do Registro do sistema.  Em particular, o script adiciona a chave, `MyVeryOwnKey`, a `HKEY_CURRENT_USER`.  Também atribui o valor da cadeia de caracteres padrão de `HowGoesIt?` para a nova chave:  
  
```  
HKEY_CURRENT_USER  
{  
   'MyVeryOwnKey' = s 'HowGoesIt?'  
}  
```  
  
 Este script pode facilmente ser estendido para definir múltiplas subchaves como segue:  
  
```  
HKCU  
{  
   'MyVeryOwnKey' = s 'HowGoesIt?'  
   {  
      'HasASubkey'  
      {  
         'PrettyCool?' = d '55'  
         val 'ANameValue' = s 'WithANamedValue'  
      }  
   }  
}  
```  
  
 Agora, o script adiciona uma subchave, `HasASubkey`, a `MyVeryOwnKey`.  Esta a subchave, adicione a subchave de `PrettyCool?` \(com um valor padrão de `DWORD` de 55\) e o `ANameValue` chamado valor \(com um valor de cadeia de caracteres de `WithANamedValue`\).  
  
##  <a name="_atl_register_the_registrar_com_server"></a> Registrar o servidor COM de escrivão  
 O script a seguir registra o servidor de escrivão COM o próprio.  
  
```  
HKCR  
{  
   ATL.Registrar = s 'ATL Registrar Class'  
   {  
      CLSID = s '{44EC053A-400F-11D0-9DCD-00A0C90391D3}'  
   }  
   NoRemove CLSID  
   {  
      ForceRemove {44EC053A-400F-11D0-9DCD-00A0C90391D3} =  
                   s 'ATL Registrar Class'  
      {  
         ProgID = s 'ATL.Registrar'  
         InprocServer32 = s '%MODULE%'  
         {  
            val ThreadingModel = s 'Apartment'  
         }  
      }  
   }  
}  
```  
  
 Em tempo de execução, esse analisar a árvore adiciona a chave de `ATL.Registrar` a `HKEY_CLASSES_ROOT`.  A essa nova chave, ele em:  
  
-   Especifica `ATL Registrar Class` como o valor da cadeia de caracteres padrão de chave.  
  
-   Adiciona `CLSID` como uma subchave.  
  
-   Especifica `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` para `CLSID`.  \(Esse valor é o CLSID de escrivão para uso com `CoCreateInstance`.\)  
  
 Desde que `CLSID` é compartilhado, não deve ser removido no modo de Unregister.  A instrução, `NoRemove CLSID`fazer isso, indicando que `CLSID` deve ser aberto no modo do registro e ser ignorado no modo de Unregister.  
  
 A declaração de `ForceRemove` fornece uma função de tarefas domésticas remover uma chave e todas as suas subchaves antes de recriar a chave.  Isso pode ser útil se os nomes das subchaves forem alterados.  Em esse exemplo de script, `ForceRemove` verifica se `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` já existe.  Se fizer isso, `ForceRemove`:  
  
-   Exclui recursivamente `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` e todas as suas subchaves.  
  
-   Recria `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`.  
  
-   Adiciona `ATL Registrar Class` como o valor da cadeia de caracteres padrão para `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`.  
  
 A árvore de análise agora adiciona duas novas subchaves a `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`.  A primeira chave, `ProgID`, obtém um valor de cadeia de caracteres padrão que é ProgID.  A segunda chave, `InprocServer32`, obtém um valor de cadeia de caracteres padrão, `%MODULE%`de, que é um valor pré\-processamento explicado na seção, [Usando parâmetros substituível \(escrivão do pré\-processador\)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md), este artigo.  `InprocServer32` também obtém um valor chamado, `ThreadingModel`, com um valor de cadeia de caracteres de `Apartment`.  
  
## Especificar várias árvores analisam  
 Para especificar mais de um analisa a árvore em um script, simplesmente colocar uma árvore no final da outra.  Por exemplo, o seguinte script adiciona a chave, `MyVeryOwnKey`, as árvores de análise para `HKEY_CLASSES_ROOT` e `HKEY_CURRENT_USER`:  
  
```  
HKCR  
{  
   'MyVeryOwnKey' = s 'HowGoesIt?'  
}  
HKEY_CURRENT_USER  
{  
   'MyVeryOwnKey' = s 'HowGoesIt?'  
}  
```  
  
> [!NOTE]
>  Em um script de escrivão, 4K é o tamanho máximo simbólico.  \(O símbolo de é qualquer elemento reconhecível na sintaxe.\) Em o exemplo anterior de script, `HKCR`, `HKEY_CURRENT_USER`, `'MyVeryOwnKey'`, e `'HowGoesIt?'` são todos os tokens.  
  
## Consulte também  
 [Criando scripts de escrivão](../Topic/Creating%20Registrar%20Scripts.md)