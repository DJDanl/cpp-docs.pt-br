---
title: "Os avisos do compilador são desativados por padrão | Microsoft Docs"
ms.date: 11/04/2016
ms.technology: cpp-tools
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- warnings, compiler
- cl.exe compiler, setting options
ms.assetid: 69809cfb-a38a-4035-b154-283a61938df8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 48afd89f4b795a4f582d8b9506c527a602a1d2b4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warnings-that-are-off-by-default"></a>Avisos de compilador desativados por padrão

O compilador inclui avisos que são desativados por padrão, pois a maioria dos usuários não deseja vê-los. No entanto, você pode habilitar esses avisos usando uma das opções a seguir.

`#pragma warning(default : warning_number )`  
O aviso especificado (`warning_number`) é habilitado no seu nível padrão. A documentação para o aviso contém o nível padrão do aviso.

`#pragma warning( warning_level : warning_number )`  
O aviso especificado (`warning_number`) é habilitado no nível especificado (`warning_level`).

[/ Parede](../build/reference/compiler-option-warning-level.md)  
**/ Parede** habilita todos os avisos que são desativados por padrão.

Os seguintes avisos são desativados por padrão.

|||
|-|-|
|[C4061](../error-messages/compiler-warnings/compiler-warning-level-4-c4061.md) (nível 4)|o enumerador 'identifier' em uma opção de enum 'enumeration' não é tratado explicitamente por um rótulo case|
|[C4062](../error-messages/compiler-warnings/compiler-warning-level-4-c4062.md) (nível 4)|o enumerador 'identifier' em uma opção de enum 'enumeration' não é tratado|
|C4191 (nível 3)|'operator/operation': conversão não segura de 'type of expression' em 'type required'|
|[C4242](../error-messages/compiler-warnings/compiler-warning-level-4-c4242.md) (nível 4)|'identifier': conversão de 'type1' em 'type2', possível perda de dados|
|[C4254](../error-messages/compiler-warnings/compiler-warning-level-4-c4254.md) (nível 4)|'operator': conversão de 'type1' em 'type2', possível perda de dados|
|[C4255](../error-messages/compiler-warnings/compiler-warning-level-4-c4255.md) (nível 4)|'function': nenhum protótipo de função fornecido: convertendo '()' em '(void)'|
|[C4263](../error-messages/compiler-warnings/compiler-warning-level-4-c4263.md) (nível 4)|'function': função membro não substitui nenhuma função membro virtual da classe base|
|[C4264](../error-messages/compiler-warnings/compiler-warning-level-1-c4264.md) (nível 1)|'virtual_function': nenhuma substituição disponível para função membro virtual da 'classe' base; a função é ocultada|
|[C4265](../error-messages/compiler-warnings/compiler-warning-level-3-c4265.md) (nível 3)|'class': a classe tem funções virtuais, mas o destruidor não é virtual|
|[C4266](../error-messages/compiler-warnings/compiler-warning-level-4-c4266.md) (nível 4)|'function': nenhuma substituição disponível para função membro virtual da base 'type'; a função é ocultada|
|[C4287](../error-messages/compiler-warnings/compiler-warning-level-3-c4287.md) (nível 3)|'operator': incompatibilidade de constante negativa/não assinada|
|[C4289](../error-messages/compiler-warnings/compiler-warning-level-4-c4289.md) (nível 4)|extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo do loop for|
|[C4296](../error-messages/compiler-warnings/compiler-warning-level-4-c4296.md) (nível 4)|'operator': a expressão é sempre falsa|
|[C4339](../error-messages/compiler-warnings/compiler-warning-level-4-c4339.md) (nível 4)|'type': uso de tipo indefinido detectado no metadados do CLR - usar esse tipo pode gerar uma exceção de tempo de execução|
|[C4342](../error-messages/compiler-warnings/compiler-warning-level-1-c4342.md) (nível 1)|alteração de comportamento: 'function' chamado, mas um operador de membro foi chamado em versões anteriores|
|[C4350](../error-messages/compiler-warnings/compiler-warning-level-1-c4350.md) (nível 1)|alteração de comportamento: 'member1' chamado no lugar de 'member2'|
|[C4355](../error-messages/compiler-warnings/compiler-warning-c4355.md)|'this' : usado na lista de inicializadores do membro base|
|[C4365](../error-messages/compiler-warnings/compiler-warning-level-4-c4365.md) (nível 4)|'action': conversão de 'type_1' em 'type_2', incompatibilidade de signed/unsigned|
|C4370 (nível 3)|layout da classe foi alterado de uma versão anterior do compilador devido a empacotamento melhor|
|C4371 (nível 3)|layout da classe pode ter sido alterado de uma versão anterior do compilador devido a empacotamento melhor do membro 'member'|
|C4388 (nível 4)|incompatibilidade de signed/unsigned|
|[C4412](../error-messages/compiler-warnings/compiler-warning-level-2-c4412.md) (nível 2)|'function': a assinatura da função contém o tipo 'type'; não é seguro passar objetos C++ entre código puro e combinado ou nativo|
|C4426 (nível 1)|os sinalizadores de otimização alterados após incluir o cabeçalho, pode ser devido a #pragma optimize()|
|[C4435](../error-messages/compiler-warnings/compiler-warning-level-4-c4435.md) (nível 4)|'class1' : layout do objeto em /vd2 será alterado devido à base virtual 'class2'|
|[C4437](../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md) (nível 4)|dynamic_cast da base virtual 'class1' para 'class2' pode falhar em alguns contextos|
|C4444 (nível 3)|top level '__unaligned' não é implementado nesse contexto|
|C4464 (nível 4)|caminho de inclusão relativo contém '... '|
|C4472 (nível 1)|'identifier' é um enum nativo: adicione um especificador de acesso (privado/público) para declarar um enum gerenciado|
|[C4514](../error-messages/compiler-warnings/compiler-warning-level-4-c4514.md) (nível 4)|'function': função embutida sem referência foi removida|
|[C4536](../error-messages/compiler-warnings/compiler-warning-level-4-c4536.md) (nível 4)|'type name': nome do tipo excede o limite de metadados de caracteres 'limit'|
|[C4545](../error-messages/compiler-warnings/compiler-warning-level-1-c4545.md) (nível 1)|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos|
|[C4546](../error-messages/compiler-warnings/compiler-warning-level-1-c4546.md) (nível 1)|faltando lista de argumentos na chamada de função antes da vírgula|
|[C4547](../error-messages/compiler-warnings/compiler-warning-level-1-c4547.md) (nível 1)|'operator': operador antes da vírgula não tem efeito; operador esperado com efeito colateral|
|[C4548](../error-messages/compiler-warnings/compiler-warning-level-1-c4548.md) (nível 1)|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral|
|[C4549](../error-messages/compiler-warnings/compiler-warning-level-1-c4549.md) (nível 1)|'operator': operador antes da vírgula não tem efeito; você intencionava 'operator'?|
|[C4555](../error-messages/compiler-warnings/compiler-warning-level-1-c4555.md) (nível 1)|expressão não tem efeito; expressão esperada com efeito colateral|
|[C4557](../error-messages/compiler-warnings/compiler-warning-level-3-c4557.md) (nível 3)|'__assume' contém efeito 'effect'|
|[C4571](../error-messages/compiler-warnings/compiler-warning-level-4-c4571.md) (nível 4)|Informativo: semântica catch(...) alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas|
|C4574 (nível 4)|'identifier' é definido para ser '0': você quis usar '#if identifier'?|
|C4582 (nível 4)|'*tipo*': construtor não é chamado implicitamente|
|C4583 (nível 4)|'*tipo*': destrutor não está chamado implicitamente|
|C4587 (nível 1)|'*anonymous_structure*': alteração de comportamento: construtor é não mais implicitamente chamado|
|C4588 (nível 1)|'*anonymous_structure*': alteração de comportamento: destruidor é não mais implicitamente chamado|
|C4598 (níveis 1 e 3)|' #include "*cabeçalho*"': número de cabeçalho *número* no cabeçalho pré-compilado não coincide com a compilação atual da posição|
|C4599 (nível 3)|'*opção* *caminho*': o número de argumento de linha de comando *número* não coincide com cabeçalho pré-compilado|
|C4605 (nível 1)|' /D*macro*' especificado na linha de comando atual, mas não foi especificado quando o cabeçalho pré-compilado foi criado|
|[C4619](../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md) (nível 3)|aviso #pragma: não há número de aviso 'number'|
|[C4623](../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md) (nível 4)|'derived class': construtor padrão não pôde ser gerado porque o construtor padrão de uma classe base está inacessível|
|[C4625](../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md) (nível 4)|'derived class': construtor de cópia não pôde ser gerado porque o construtor de cópia de uma classe base está inacessível|
|[C4626](../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md) (nível 4)|'derived class': operador de atribuição não pôde ser gerado porque o operador de atribuição de uma classe base está inacessível|
|[C4628](../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md) (nível 1)|dígrafos não suportados com -Ze. A sequência de caracteres 'digraph' não é interpretada como token alternativo para 'char'|
|[C4640](../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md) (nível 3)|'instance': construção de objeto estático local não é thread-safe|
|C4647 (nível 3)|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores|
|C4654 (nível 4)|Incluir código colocado antes de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado.|
|[C4668](../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md) (nível 4)|'*símbolo*'não está definido como uma macro de pré-processador, substituindo por '0' para'*diretivas*'|
|[C4682](../error-messages/compiler-warnings/compiler-warning-level-4-c4682.md) (nível 4)|'*símbolo*': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[C4686](../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md) (nível 3)|'*tipo definido pelo usuário*': possível alteração em comportamento, alteração no UDT retornar a convenção de chamada|
|[C4692](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) (nível 1)|'*função*': assinatura de membro não private contém tipo nativo private 'native_type' do assembly|
|[C4710](../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md) (nível 4)|'*função*': função não embutida|
|[C4738](../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md) (nível 3)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|[C4746](../error-messages/compiler-warnings/compiler-warning-c4746.md)|acesso volátil de '*expressão*' está sujeito a /volatile:\<iso &#124; ms > Configuração; considere o uso de funções intrínsecas iso_volatile_load/store|
|C4749 (nível 4)|condicionalmente com suporte: offsetof aplicado a tipo de layout não standard '*tipo*'|
|C4767 (nível 4)|nome da seção '*símbolo*' tem mais de 8 caracteres e será truncado pelo vinculador|
|C4768 (nível 3)|atributos de declspec antes de especificação de vinculação são ignorados|
|C4774 (nível 4)|'*cadeia de caracteres*': formato de cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal|
|C4786 (nível 3)|'*símbolo*': nome do objeto foi truncado para 'número' caracteres as informações de depuração|
|[C4820](../error-messages/compiler-warnings/compiler-warning-level-4-c4820.md) (nível 4)|preenchimento de bytes 'bytes' adicionado após construção de 'member_name'|
|C4826 (nível 2)|Conversão de '*type1*'para'*type2*' possui sinal estendido. Isso pode causar comportamento inesperado em tempo de execução.|
|C4837 (nível 4)|trigraph detectado: '? *caracteres*'substituído por'*caracteres*'|
|C4841 (nível 4)|extensão não padrão usada: designador de membro composta usado em offsetof|
|C4842 (nível 4)|o resultado de 'offsetof' aplicado a um tipo usando várias heranças não é garantido para ser consistente entre as versões do compilador|
|[C4868](../error-messages/compiler-warnings/compiler-warning-c4868.md) (nível 4)|'_arquivo_(*line_number*)' compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização entre chaves|
|[C4905](../error-messages/compiler-warnings/compiler-warning-level-1-c4905.md) (nível 1)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|
|[C4906](../error-messages/compiler-warnings/compiler-warning-level-1-c4906.md) (nível 1)|literal de cadeia de caracteres convertido em 'LPWSTR'|
|[C4917](../error-messages/compiler-warnings/compiler-warning-level-1-c4917.md) (nível 1)|'declarator': um GUID pode ser associado apenas a uma classe, uma interface ou um namespace|
|[C4928](../error-messages/compiler-warnings/compiler-warning-level-1-c4928.md) (nível 1)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|
|[C4931](../error-messages/compiler-warnings/compiler-warning-level-4-c4931.md) (nível 4)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|
|[C4946](../error-messages/compiler-warnings/compiler-warning-level-1-c4946.md) (nível 1)|reinterpret_cast usado entre classes relacionadas: 'class1' e 'class2'|
|C4962|'function': otimizações guiadas por perfil desabilitadas porque as otimizações tornaram os dados de perfil inconsistentes|
|[C4986](../error-messages/compiler-warnings/compiler-warning-c4986.md) (nível 4)|'*símbolo*': especificação de exceção não corresponde à declaração anterior|
|C4987 (nível 4)|extensão não padrão usada: 'throw (...)'|
|C4988 (nível 4)|'*símbolo*': variável declarada fora do escopo classe/função|
|C5022|'*tipo*': vários construtores de movimento especificados|
|C5023|'*tipo*': vários operadores de atribuição de movimento especificados|
|C5024 (nível 4)|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|C5025 (nível 4)|'*tipo*': mover o operador de atribuição foi implicitamente definido como excluído|
|C5026 (nível 1 e nível 4)|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|C5027 (nível 1 e nível 4)|'*tipo*': mover o operador de atribuição foi implicitamente definido como excluído|
|C5029 (nível 4)|extensão não padrão usada: atributos de alinhamento no C++ se aplicam a variáveis, membros de dados e somente os tipos de marcas|
|C5031 (nível 4)|Warning (POP) #pragma: provável incompatibilidade, estado de aviso enviado em outro arquivo mostrado|
|C5032 (nível 4)|detectado Warning (push) #pragma com nenhuma Warning (POP) #pragma correspondente|
|C5035|o uso de recurso '*recurso*' faz com que a função *função* a ser compilado como código do convidado|
|C5036 (nível 1)|conversão de ponteiro de função varargs ao compilar com /hybrid:x86arm64 '*type1*'para'*type2*'|

Esses avisos são desativados, a menos que o [/ permissivo-](../build/reference/permissive-standards-conformance.md) é definir a opção de compilador:

|||
|-|-|
|[C4471 (nível 4)](../error-messages/compiler-warnings/compiler-warning-level-4-c4471.md)|uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)|
|[C4608 (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md)|' union\_membro ' já foi inicializada por outro membro de união na lista de inicializador, 'union_member'|


Esses avisos foram desativado por padrão em versões do compilador antes do Visual Studio 2015:

|||
|-|-|
|[C4302](../error-messages/compiler-warnings/compiler-warning-level-2-c4302.md) (nível 2)|'conversion': truncamento de 'type1' para 'type2'|
|[C4311](../error-messages/compiler-warnings/compiler-warning-level-1-c4311.md) (nível 1)|'variable': truncamento de ponteiro de 'type' para 'type'|
|[C4312](../error-messages/compiler-warnings/compiler-warning-level-1-c4312.md) (nível 1)|'operation': conversão de 'type1' em 'type2' de tamanho maior|
|[C4319](../error-messages/compiler-warnings/compiler-warning-level-1-c4319.md) (nível 1)|'operator': zero estendendo 'type1' em 'type2' de tamanho maior|

Esses avisos foram desativado por padrão em versões do compilador antes do Visual Studio 2012:

|||
|-|-|
|[C4431](../error-messages/compiler-warnings/compiler-warning-level-4-c4431.md) (nível 4)|faltando especificador de tipo - int assumido. Observação: C não suporta mais default-int|

## <a name="see-also"></a>Consulte também

[warning](../preprocessor/warning.md)
