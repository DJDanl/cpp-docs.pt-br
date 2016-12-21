---
title: "Tratamento de erro em arquivos JScript do assistente | Microsoft Docs"
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
  - "tratamento de erros, JScript"
  - "JScript, tratando erros"
  - "Tratamento de erros JScript do assistente"
ms.assetid: 6df3ba46-7ab6-484c-ac45-b08f4b6a5900
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tratamento de erro em arquivos JScript do assistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria um assistente, o seu projeto inclui os arquivos Default. js e Common.js.  Use esses arquivos para personalizar o seu projeto.  Consulte  [O arquivo JScript](../ide/jscript-file.md) para obter mais informações.  
  
 Seu projeto deve incluir o tratamento de erros.  O código a seguir fornece um exemplo de tal código.  
  
### Para manipular erros em JScript  
  
1.  Para capturar erros quando o usuário clica  **Concluir**, digite o seguinte código:  
  
    ```  
    function OnFinish(selProj, Class)  
    {  
       try  
       {  
          .....  
       }  
       catch(e)  
       {  
          if (e.description.length != 0)  
             SetErrorInfo(e.description, e.number);  
          return e.number  
       }  
    }  
    ```  
  
2.  Lançar `e` de quaisquer funções de script auxiliares chamadas no script:  
  
    ```  
    function ExtenderFromType(strVariableType)  
    {  
       try  
       {  
          ....  
       }  
       catch(e)  
       {  
          throw e;  
       }  
    }  
    ```  
  
3.  Se o parâmetro  **PREPROCESS\_FUNCTION** está em  [o arquivo vsz](../ide/dot-vsz-file-project-control.md), as chamadas do assistente  [CanAddATLClass](../ide/jscript-functions-for-cpp-wizards.md).  Use [SetErrorInfo](../ide/seterrorinfo.md) em caso de falha e o retorno de  **false**:  
  
    ```  
    function CanAddATLClass(oProj, oObject)  
    {  
       try  
       {  
          if (!IsATLProject(oProj))  
          {  
             if (!IsMFCProject(oProj, true))  
             {     
                var L_CanAddATLClass_Text = "ATL classes can only be added  
     to ATL, MFC EXE and MFC regular DLL projects.";  
                wizard.ReportError(L_CanAddATLClass_Text);  
                return false;  
             }  
             else  
             {  
                .....  
                var bRet = AddATLSupportToProject(oProj);  
                .....  
                return bRet;  
             }  
          }  
          return true;  
       }  
       catch(e)  
       {  
          throw e;  
       }  
    }  
    ```  
  
4.  Se você deve voltar para o  **Novo projeto** ou  **Add New Item** caixa de diálogo, o retorno  **VS\_E\_WIZBACKBUTTONPRESS**:  
  
    ```  
    function OnFinish(selProj, Class)  
    {  
       ....  
       if (!CheckAddtoProject(selProj))  
       {  
          return VS_E_WIZARDBACKBUTTONPRESS;  
       }  
    }  
    ```  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Personalizando o assistente](../ide/customizing-your-wizard.md)