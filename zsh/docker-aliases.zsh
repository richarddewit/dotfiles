alias d='docker'

alias dc='docker-compose'
alias dcd='docker-compose down'
alias dcu='docker-compose up --build'
alias dcud='docker-compose up -d --build'
alias dce='docker-compose exec'
alias dcr='docker-compose down && docker-compose up --build'
alias dcrd='docker-compose down && docker-compose up -d --build'

alias dtop='docker stats --format "table {{.Container}}\t{{.Name}}\t{{.CPUPerc}}  {{.MemPerc}}\t{{.NetIO}}\t{{.BlockIO}}"'
