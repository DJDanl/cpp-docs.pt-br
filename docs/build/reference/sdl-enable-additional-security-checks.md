---
title: "/sdl (Habilitar verifica&#231;&#245;es de seguran&#231;a adicionais) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.SDLCheck"
dev_langs: 
  - "C++"
ms.assetid: 3dcf86a0-3169-4240-9f29-e04a9f535826
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /sdl (Habilitar verifica&#231;&#245;es de seguran&#231;a adicionais)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Adiciona verificações recomendada do Security Development Lifecycle \(SDL\).  Essas verificações incluem segurança extra relevantes avisos como erros e recursos de geração de código seguro adicional.  
  
## Sintaxe  
  
```  
/sdl[-]  
```  
  
## Comentários  
 **\/sdl** permite que um superconjunto das verificações de segurança da linha de base fornecidas pelo [\/GS](../Topic/-GS%20\(Buffer%20Security%20Check\).md) e substituições **\/GS\-**.  Por padrão, **\/sdl** permanece desativado.  **\/sdl\-** Desabilita as verificações de segurança adicionais.  
  
## Verificações de tempo de compilação  
 **\/sdl** permite que esses avisos como erros:  
  
|Aviso habilitado por \/sdl|Opção de linha de comando equivalente|Descrição|  
|--------------------------------|-------------------------------------------|---------------|  
|[C4146](../../error-messages/compiler-warnings/compiler-warning-level-2-c4146.md)|\/we4146|Um operador unário menos operador foi aplicado a um tipo sem sinal, resultando em um resultado não assinado.|  
|[C4308](../../error-messages/compiler-warnings/compiler-warning-level-2-c4308.md)|\/we4308|Uma constante de inteiro negativa é convertido em tipo sem sinal, resultando em um resultado possivelmente sem sentido.|  
|[C4532](../../error-messages/compiler-warnings/compiler-warning-level-1-c4532.md)|\/we4532|Uso de `continue`, `break` ou `goto` palavras\-chave em um `__finally`\/`finally` bloco tem um comportamento indefinido durante o encerramento anormal.|  
|[C4533](../../error-messages/compiler-warnings/compiler-warning-level-1-c4533.md)|\/we4533|Inicializando uma variável de código não será executado.|  
|[C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|\/we4700|Uso de uma variável local não inicializada.|  
|[C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|\/we4703|Uso de uma variável de ponteiro locais potencialmente não inicializado.|  
|[C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|\/we4789|Buffer saturação quando funções específicas de tempo de execução \(CRT\) C são usadas.|  
|[C4995](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md)|\/we4995|Uso de uma função marcada com o pragma [preterido](../Topic/deprecated%20\(C-C++\).md).|  
|[C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md)|\/we4996|Uso de uma função marcada como [preterido](../../cpp/deprecated-cpp.md).|  
  
## Verificações de tempo de execução  
 Quando **\/sdl** estiver habilitado, o compilador gera código para executar essas verificações em tempo de execução:  
  
-   Habilita o modo estrito de **\/GS** detecção de estouro de buffer de tempo de execução, equivalente ao compilar com `#pragma strict_gs_check(push, on)`.  
  
-   Executa a limpeza de ponteiro limitado.  Em expressões que não envolvem cancela a referência e tipos que não têm nenhum destruidor definido pelo usuário, as referências do ponteiro são definidas como um endereço inválido após uma chamada para `delete`.  Isso ajuda a evitar a reutilização de referências do ponteiro obsoletos.  
  
-   Executa a inicialização de membro de classe.  Inicializa automaticamente todos os membros de classe como zero na instanciação de objetos \(antes da execução do construtor\).  Isso ajuda a evitar o uso de dados não inicializados associados a membros de classe que o construtor não inicializar explicitamente.  
  
## Observações  
 Para obter mais informações, consulte [avisos, \/sdl e melhorando a detecção de variáveis não inicializada](http://go.microsoft.com/fwlink/p/?LinkId=331012).  
  
#### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Sobre o **geral** página, selecione a opção do **verificações do SDL** lista suspensa.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)