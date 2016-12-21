---
title: "/kernel (criar bin&#225;rio do modo kernel) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/kernel"
  - "/kernel-"
dev_langs: 
  - "C++"
ms.assetid: 6d7fdff0-c3d1-4b78-9367-4da588ce8b05
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /kernel (criar bin&#225;rio do modo kernel)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um binário que pode ser executado no kernel do windows.  
  
## Sintaxe  
  
```  
/kernel[-]  
```  
  
## Arguments  
 **\/kernel**  
 O código no projeto atual é compilado e vinculado usando um conjunto de regras de linguagem C\+\+ que são específicas do código que será executada em modo de kernel.  
  
 **\/kernel\-**  
 O código no projeto atual é compilado e vinculado sem usar as regras de linguagem C\+\+ que são específicas do código que será executada em modo de kernel.  
  
## Comentários  
 Não há equivalente de `#pragma` para controlar esta opção.  
  
 Especificar a opção de **\/kernel** informa o compilador e o vinculador para arbitrar quais recursos de idioma são permitidos no modo kernel e certificar\-se de que você tem a capacidade suficiente eloquente evitar a instabilidade de tempo de execução que é exclusivo para o modo de kernel C\+\+.  Isso é feito proibindo o uso dos recursos de linguagem C\+\+ que são disruptivos no modo kernel e fornecendo avisos para os recursos de linguagem C\+\+ que são potencialmente disruptivos mas não pode ser desabilitado.  
  
 A opção de **\/kernel** se aplica às fases do compilador e do vinculador de uma construção e é definida no nível de projeto.  Passar a opção de **\/kernel** para indicar ao compilador que o binário resultante, depois de ser vinculado, deve ser carregado no kernel do windows.  O compilador refinará o espectro de recursos de linguagem C\+\+ a um subconjunto que seja compatível com o kernel.  
  
 A tabela a seguir lista as alterações no comportamento do compilador **\/kernel** quando é especificado.  
  
|Tipo de comportamento|comportamento de**\/kernel**|  
|---------------------------|----------------------------------|  
|Manipulação de exceção C\+\+|Desabilitado.  Todas as instâncias de palavras\-chave `throw` e de `try` se o gerará um erro do compilador \(exceto para a especificação `throw()`de exceção\).  Nenhuma opção de **\/EH** é compatível com **\/kernel**, com exceção de **\/EH\-**.|  
|RTTI|Desabilitado.  Todas as instâncias de palavras\-chave `dynamic_cast` e de `typeid` se o gerará um erro do compilador, a menos que seja usado `dynamic_cast` estaticamente.|  
|`new` e `delete`|Você deve definir explicitamente o operador de `new()` ou de `delete()` ; nem o compilador ou o tempo de execução fornecerão uma definição padrão.|  
  
 As convenções personalizados de chamada, opção de compilação de [\/GS](../Topic/-GS%20\(Buffer%20Security%20Check\).md) , e todas as otimizações são permitidas quando você usa a opção de **\/kernel** .  Inlining não é afetado pela maior parte por **\/kernel**, com a mesma semântica atendida pelo compilador.  Se você quiser garantir que `__forceinline` que inlining o qualificador é cumprido, você deve ter certeza de que [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) de aviso está habilitado para que você saiba como quando uma função de `__forceinline` de detalhes não será embutida.  
  
 Quando o compilador é passado a opção de **\/kernel** , predefine uma macro de pré\-processador chamado `_KERNEL_MODE` e possui o valor **1**.  Você pode usar isso para compilar o código condicional com base no ambiente de execução está no modo de usuário ou o modo de kernel.  Por exemplo, o código a seguir especifica que a classe deve estar em um segmento não paginável da memória quando é criada para a execução do modo kernel.  
  
```cpp  
#ifdef _KERNEL_MODE  
#define NONPAGESECTION __declspec(code_seg("$kerneltext$"))  
#else  
#define NONPAGESECTION  
#endif  
  
class NONPAGESECTION MyNonPagedClass  
{  
  
};  
  
```  
  
 Alguns as seguintes combinações de arquitetura de destino e a opção de **\/arch** gerencia um erro quando usadas com **\/kernel**:  
  
-   **\/arch:{SSE&#124;SSE2&#124;AVX}** não tem suporte em x86.  Somente **\/arch:IA32** tem suporte com **\/kernel** em x86.  
  
-   **\/arch:AVX** não tem suporte com **\/kernel** em x64.  
  
 Compile com **\/kernel** também passa **\/kernel** ao vinculador.  Her como isso afeta o comportamento do vinculador:  
  
-   Vincular incremental é desabilitado.  Se você adicionar **\/incremental** à linha de comando, emite o vinculador esse erro fatal:  
  
     **LINK : fatal error LNK1295: '\/INCREMENTAL' not compatible with '\/KERNEL' specification; link without '\/INCREMENTAL'**  
  
-   O vinculador inspecione cada arquivo de objeto \(ou qualquer membro incluído de arquivo morto das bibliotecas estáticas\) para ver se pode ter sido criado com a opção de **\/kernel** mas não fosse.  Se alguma instância atende esse critério, do vinculador links com êxito mas ainda podem emitir um aviso, conforme mostrado na seguinte tabela.  
  
    ||obj de**\/kernel**|obj de**\/kernel\-** , obj de MASM, ou cvtresed|Mistura de **\/kernel** e de objs de **\/kernel\-**|  
    |-|------------------------|-----------------------------------------------------|---------------------------------------------------------|  
    |**link \/kernel**|Sim|Sim|Sim com aviso de LNK4257|  
    |**link**|Sim|Sim|Sim|  
  
     **LNK4257 linking object not compiled with \/KERNEL ; image may not run**  
  
 A opção de **\/kernel** e a opção de **\/driver** opera independentemente e afeta nenhuma das outras.  
  
### Para definir a opção do compilador do \/kernel no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** para o projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Na caixa de **Opções Adicionais** , adicione `/kernel` ou `/kernel-`.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)