---
title: -sdl (habilitar verificações de segurança adicionais) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.SDLCheck
dev_langs:
- C++
ms.assetid: 3dcf86a0-3169-4240-9f29-e04a9f535826
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8aa984b488f74043b8c90876047516ebca23d4d3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="sdl-enable-additional-security-checks"></a>/sdl (Habilitar verificações de segurança adicionais)
Adiciona verificações do Security Development Lifecycle (SDL) recomendado. Essas verificações incluem segurança extra relevantes avisos como erros e os recursos de geração de código seguro adicional.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/sdl[-]  
```  
  
## <a name="remarks"></a>Comentários  
 **/SDL** habilita um superconjunto das verificações de segurança da linha de base fornecidos pelo [/GS](../../build/reference/gs-buffer-security-check.md) e substituições **/GS-**. Por padrão, **/sdl** está desativado. **/SDL-** desabilita as verificações de segurança adicional.  
  
## <a name="compile-time-checks"></a>Verificações em tempo de compilação  
 **/SDL** habilita esses avisos como erros:  
  
|Aviso habilitado por /sdl|Opção de linha de comando equivalente|Descrição|  
|------------------------------|-------------------------------------|-----------------|  
|[C4146](../../error-messages/compiler-warnings/compiler-warning-level-2-c4146.md)|/we4146|Um operador unário menos operador foi aplicado a um tipo não assinado, resultando em um resultado não assinado.|  
|[C4308](../../error-messages/compiler-warnings/compiler-warning-level-2-c4308.md)|/we4308|Uma constante integral negativa convertida para tipo unsigned, resultando em um resultado possivelmente sentido.|  
|[C4532](../../error-messages/compiler-warnings/compiler-warning-level-1-c4532.md)|/we4532|O uso de `continue`, `break` ou `goto` palavras-chave em um `__finally` / `finally` bloco possui comportamento indefinido durante o encerramento anormal.|  
|[C4533](../../error-messages/compiler-warnings/compiler-warning-level-1-c4533.md)|/we4533|O código de inicialização de que uma variável não será executada.|  
|[C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|/we4700|Uso de uma variável local não inicializada.|  
|[C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|/we4703|Uso de uma variável de ponteiro local potencialmente não inicializada.|  
|[C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|/we4789|Buffer saturação quando funções específicas de tempo de execução (CRT) C são usadas.|  
|[C4995](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md)|/we4995|Uso de uma função marcado com pragma [preterido](../../preprocessor/deprecated-c-cpp.md).|  
|[C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md)|/we4996|Uso de uma função marcada como [preterido](../../cpp/deprecated-cpp.md).|  
  
## <a name="runtime-checks"></a>Verificações de tempo de execução  
 Quando **/sdl** está habilitado, o compilador gera código para executar essas verificações em tempo de execução:  
  
-   Habilita o modo estrito de **/GS** detecção de estouro de buffer de tempo de execução, equivalente a compilação com `#pragma strict_gs_check(push, on)`.  
  
-   Executa a limpeza de ponteiro limitado. Em expressões que não envolvem cancela a referência em tipos que não possuem nenhum destruidor definido pelo usuário, as referências do ponteiro são definidos para um endereço inválido após uma chamada para `delete`. Isso ajuda a evitar a reutilização de referências de ponteiro obsoletos.  
  
-   Executa a inicialização de membro de classe. Inicializa automaticamente todos os membros de classe como zero na instanciação do objeto (antes da execução do construtor). Isso ajuda a evitar o uso de dados não inicializados associados a membros de classe que o construtor não inicializar explicitamente.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [avisos, /sdl e melhorar a detecção de variáveis não inicializada](http://go.microsoft.com/fwlink/p/?LinkId=331012).  
  
#### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  No **geral** página, selecione a opção do **SDL verificações** lista suspensa.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)